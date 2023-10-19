from __future__ import annotations
from enum import Enum
import subprocess
from typing import Any, Collection, Iterator, Literal, Mapping, Sequence
from typing_extensions import NamedTuple, NewType, assert_never

import textwrap
import assume_prove
import source
import re
from utils import open_temp_file

import prog_globals as pg
SMTLIB = NewType("SMTLIB", str)

statically_infered_must_be_true = SMTLIB('true')

ops_to_smt: Mapping[source.Operator, SMTLIB] = {
    source.Operator.PLUS: SMTLIB("bvadd"),
    source.Operator.MINUS: SMTLIB("bvsub"),
    source.Operator.TIMES: SMTLIB("bvmul"),
    source.Operator.MODULUS: SMTLIB("bvurem"),
    source.Operator.DIVIDED_BY: SMTLIB("bvudiv"),
    source.Operator.BW_AND: SMTLIB("bvand"),
    source.Operator.BW_OR: SMTLIB("bvor"),
    source.Operator.BW_XOR: SMTLIB("bvxor"),
    source.Operator.AND: SMTLIB("and"),
    source.Operator.OR: SMTLIB("or"),
    source.Operator.IMPLIES: SMTLIB("=>"),
    source.Operator.EQUALS: SMTLIB("="),
    source.Operator.LESS: SMTLIB("bvult"),
    source.Operator.LESS_EQUALS: SMTLIB("bvule"),
    source.Operator.SIGNED_LESS: SMTLIB("bvslt"),
    source.Operator.SIGNED_LESS_EQUALS: SMTLIB("bvsle"),
    source.Operator.SHIFT_LEFT: SMTLIB("bvshl"),
    source.Operator.SHIFT_RIGHT: SMTLIB("bvlshr"),
    source.Operator.SIGNED_SHIFT_RIGHT: SMTLIB("bvashr"),
    source.Operator.NOT: SMTLIB("not"),
    source.Operator.BW_NOT: SMTLIB("bvnot"),
    source.Operator.TRUE: SMTLIB("true"),
    source.Operator.FALSE: SMTLIB("false"),
    source.Operator.IF_THEN_ELSE: SMTLIB("ite"),
    source.Operator.WORD_ARRAY_ACCESS: SMTLIB("select"),
    source.Operator.WORD_ARRAY_UPDATE: SMTLIB("store"),
    source.Operator.MEM_DOM: SMTLIB("mem-dom"),
    source.Operator.MEM_ACC: SMTLIB("mem-acc"),
    source.Operator.P_VALID: SMTLIB("mem-valid"),
    source.Operator.P_GLOBAL_VALID: SMTLIB("global-valid"),
    source.Operator.MEM_UPDATE: SMTLIB("mem-update")
}

MEM_SORT = SMTLIB('(Array (_ BitVec 64) (_ BitVec 8))')

BOOL = SMTLIB('Bool')

PMS = SMTLIB('PMS')
HTD = SMTLIB('(Array (_ BitVec 64) Bool)')

# 〈simple_symbol 〉 ::= a non-empty sequence of letters, digits and the characters
#                       + - / * = % ? ! . $ _ ~ & ˆ < > @ that does not start
#                       with a digit
RE_VALID_SMTLIB_SIMPLE_SYMBOL_STR = r'[a-zA-Z+\-/*=%?!.$_~<>@][a-zA-Z+\-/*=%?!.$_~<>@0-9]*'
RE_VALID_SMTLIB_SIMPLE_SYMBOL = re.compile(
    "^" + RE_VALID_SMTLIB_SIMPLE_SYMBOL_STR + "$")

Identifier = NewType('Identifier', str)


def word_array(typ: source.TypeWordArray) -> SMTLIB:
    return SMTLIB(f"(Array (_ BitVec {typ.index_bits}) (_ BitVec {typ.value_bits}))")


def identifier(illegal_name: assume_prove.VarName) -> Identifier:
    # '#' are disallowed in SMT
    assert '@' not in illegal_name, "# are replaced with @, but some name already contains a @, which might result on conflicts"
    renamed = illegal_name.replace('#', '@')
    assert RE_VALID_SMTLIB_SIMPLE_SYMBOL.match(
        renamed), f"identifier {illegal_name!r} isn't valid"
    return Identifier(renamed)


class Logic(Enum):
    QF_ABV = 'QF_ABV'
    """ Quantifier free arrays and bit vectors """


class CmdSetLogic(NamedTuple):
    logic: Logic


class CmdDeclareFun(NamedTuple):
    symbol: Identifier
    arg_sorts: Sequence[source.Type]
    ret_sort: source.Type


class CmdAssert(NamedTuple):
    expr: source.ExprT[assume_prove.VarName]


class CmdCheckSat(NamedTuple):
    pass


class CmdDefineFun(NamedTuple):
    symbol: Identifier
    args: Sequence[source.ExprVarT[assume_prove.VarName]]
    ret_sort: source.Type
    term: source.ExprT[assume_prove.VarName]


class CmdDeclareSort(NamedTuple):
    symbol: Identifier
    arity: int


class CmdComment(NamedTuple):
    comment: str


class CmdGetModel(NamedTuple):
    pass


EmptyLine = CmdComment('')

Cmd = CmdDeclareFun | CmdDefineFun | CmdAssert | CmdCheckSat | CmdComment | CmdSetLogic | CmdDeclareSort | CmdGetModel

# This isn't SMTLIB specified but
# Z3/CVC5 generates these in model_response's anyway :(


class CmdForall(NamedTuple):
    args: Sequence[source.ExprVarT[assume_prove.VarName]]
    term: str


# needed because we cannot parse Arrays.
# This is fine because this parsing is only for error reporting

class CmdPartialDefineFun(NamedTuple):
    symbol: Identifier
    args: Sequence[source.ExprVarT[assume_prove.VarName]]
    ret_sort: source.Type
    term: str


ModelResponse = CmdDefineFun | CmdPartialDefineFun | CmdDeclareFun | CmdForall | CmdComment


class CheckSatResponse(Enum):
    UNSAT = SMTLIB("unsat")
    SAT = SMTLIB("sat")
    UNKNOWN = SMTLIB("unknown")


GetModelResponse = Sequence[ModelResponse]
Response = CheckSatResponse | GetModelResponse
Responses = Sequence[Response]


def smt_bitvec_of_size(val: int, size: int) -> SMTLIB:
    assert val >= 0
    assert size > 0
    return SMTLIB(f"(_ bv{val} {size})")


def smt_extract(msb_idx: int, lsb_idx: int, expected_num_bits: int, lhs: source.ExprT[assume_prove.VarName]) -> SMTLIB:
    """
    msb_idx: most significant bit index
    lsb_idx: least significant bit index
    expected_num_bits is just used for safety

    All function symbols with declaration of the form

        ((_ extract i j) (_ BitVec m) (_ BitVec n))

    where
    - i, j, m, n are numerals
    - m > i ≥ j ≥ 0,
    - n = i - j + 1
    """

    assert isinstance(lhs.typ, source.TypeBitVec)
    assert lhs.typ.size > msb_idx >= lsb_idx >= 0
    assert expected_num_bits == msb_idx - lsb_idx + 1

    return SMTLIB(f"((_ extract {msb_idx} {lsb_idx}) {emit_expr(lhs)})")


def smt_zero_extend(num_extra_bits: int, lhs: source.ExprT[assume_prove.VarName]) -> SMTLIB:
    # ((_ zero_extend 0) t) stands for t
    # ((_ zero_extend i) t) abbreviates (concat ((_ repeat i) #b0) t)

    assert num_extra_bits >= 0
    return SMTLIB(f"((_ zero_extend {num_extra_bits}) {emit_expr(lhs)})")


def smt_sign_extend(num_extra_bits: int, lhs: source.ExprT[assume_prove.VarName]) -> SMTLIB:
    # ((_ sign_extend 0) t) stands for t
    # ((_ sign_extend i) t) abbreviates
    #   (concat ((_ repeat i) ((_ extract |m-1| |m-1|) t)) t)

    assert num_extra_bits >= 0
    return SMTLIB(f"((_ sign_extend {num_extra_bits}) {emit_expr(lhs)})")


def emit_num_with_correct_type(expr: source.ExprNumT) -> SMTLIB:
    if isinstance(expr.typ, source.TypeBitVec):
        assert - \
            2 ** expr.typ.size <= expr.num < 2 ** expr.typ.size, f"{expr.num=} doesn't fit in the type {expr.typ=}"
        if expr.num >= 0:
            num = expr.num
        else:
            num = 2 ** 32 + expr.num
        return smt_bitvec_of_size(val=num, size=expr.typ.size)
    assert False, f"{expr} not supported"


def emit_bitvec_cast(target_typ: source.TypeBitVec, operator: Literal[source.Operator.WORD_CAST, source.Operator.WORD_CAST_SIGNED], lhs: source.ExprT[assume_prove.VarName]) -> SMTLIB:
    assert isinstance(lhs.typ, source.TypeBitVec)
    if lhs.typ.size == target_typ.size:
        return emit_expr(lhs)

    if target_typ.size < lhs.typ.size:
        # extract the bottom <target_type.size> bits
        return smt_extract(msb_idx=target_typ.size - 1, lsb_idx=0, expected_num_bits=target_typ.size, lhs=lhs)

    assert lhs.typ.size < target_typ.size
    if operator == source.Operator.WORD_CAST:
        return smt_zero_extend(num_extra_bits=target_typ.size - lhs.typ.size, lhs=lhs)
    elif operator == source.Operator.WORD_CAST_SIGNED:
        return smt_sign_extend(num_extra_bits=target_typ.size - lhs.typ.size, lhs=lhs)

    assert_never(operator)


def emit_expr_symbol(expr: source.ExprSymbol[Any]) -> SMTLIB:
    # see source.py where this is converted to
    # a CmdDeclareFun
    return SMTLIB(f"{expr.name}@global-symbol")


load_word_map: Mapping[int, Identifier] = {
    8: Identifier(str("load-word8")),
    16: Identifier(str("load-word16")),
    32: Identifier(str("load-word32")),
    64: Identifier(str("load-word64"))
}

store_word_map: Mapping[int, Identifier] = {
    8: Identifier(str("store-word8")),
    16: Identifier(str("store-word16")),
    32: Identifier(str("store-word32")),
    64: Identifier(str("store-word64"))
}


def emit_expr(expr: source.ExprT[assume_prove.VarName]) -> SMTLIB:
    if isinstance(expr, source.ExprNum):
        return emit_num_with_correct_type(expr)
    elif isinstance(expr, source.ExprOp):

        # mypy isn't smart enough to understand `in`, so we split the iffs
        if expr.operator == source.Operator.WORD_CAST:
            assert len(expr.operands) == 1
            assert isinstance(expr.typ, source.TypeBitVec)
            return emit_bitvec_cast(expr.typ, source.Operator.WORD_CAST, expr.operands[0])

        if expr.operator == source.Operator.WORD_CAST_SIGNED:
            assert len(expr.operands) == 1
            assert isinstance(expr.typ, source.TypeBitVec)
            return emit_bitvec_cast(expr.typ, source.Operator.WORD_CAST_SIGNED, expr.operands[0])

        if expr.operator in source.nulary_operators:
            return SMTLIB(ops_to_smt[expr.operator])

        if expr.operator is source.Operator.P_ALIGN_VALID:
            assert len(expr.operands) == 2
            typ, val = expr.operands
            assert isinstance(typ, source.ExprType), typ
            if isinstance(val, source.ExprSymbol):
                return statically_infered_must_be_true
            raise NotImplementedError(
                "PAlignValid for non symbols isn't supported")

        if expr.operator is source.Operator.P_GLOBAL_VALID:
            return statically_infered_must_be_true

        if expr.operator is source.Operator.MEM_UPDATE:
            mem, symb_or_addr, value = expr.operands
            if not isinstance(value.typ, source.TypeBitVec):
                assert False, "Only TypeBitVec supported"

            as_fn_call = emit_expr(symb_or_addr)

            value_as_smt = emit_expr(value)

            if value.typ.size not in store_word_map.keys():
                raise NotImplementedError(
                    f"MemUpdate for BitVec of size {value.typ.size} is not supported")
            return SMTLIB(f"({store_word_map[value.typ.size]} {emit_expr(mem)} {as_fn_call} {value_as_smt})")

        if expr.operator is source.Operator.MEM_ACC:
            mem, symb_or_addr = expr.operands
            if not isinstance(expr.typ, source.TypeBitVec):
                assert False, "Only TypBitVec is accepted"

            as_fn_call = emit_expr(symb_or_addr)

            if expr.typ.size not in load_word_map.keys():
                raise NotImplementedError(
                    f"MemAcc for BitVec of size {expr.typ.size} is not supported")
            return SMTLIB(f"({load_word_map[expr.typ.size]} {emit_expr(mem)} {as_fn_call})")

        if expr.operator is source.Operator.P_VALID:
            return statically_infered_must_be_true
            assert len(expr.operands) == 3
            # We do not care about the type
            htd, _, addr = expr.operands

            if not isinstance(addr, source.ExprSymbol | source.ExprVar | source.ExprNum | source.ExprOp):
                assert False, f"Expression {addr} not supported"
            return SMTLIB(f"(= (select {emit_expr(htd)} {emit_expr(addr)}) true)")

        return SMTLIB(f'({ops_to_smt[expr.operator]} {" ".join(emit_expr(op) for op in expr.operands)})')
    elif isinstance(expr, source.ExprVar):
        return SMTLIB(f'{identifier(expr.name)}')
    elif isinstance(expr, source.ExprSymbol):
        return emit_expr_symbol(expr)
    elif isinstance(expr, source.ExprType):
        assert False, "what do i do with this?"
    elif isinstance(expr, source.ExprFunction):
        if len(expr.arguments) == 0:
            return SMTLIB(expr.function_name)
        return SMTLIB(f'({expr.function_name} {" ".join(emit_expr(arg) for arg in expr.arguments)})')
    elif isinstance(expr, source.ExprForall):
        return SMTLIB(f"""
(forall ({" ".join('(' + emit_expr(arg) +' ' + emit_sort(arg.typ) + ')' for arg in expr.args)}) 
    {emit_expr(expr.expr)}
)""")

    assert_never(expr)


def emit_sort(typ: source.Type) -> SMTLIB:
    if isinstance(typ, source.TypeBuiltin):
        if typ.builtin is source.Builtin.BOOL:
            return BOOL
        elif typ.builtin is source.Builtin.MEM:
            return MEM_SORT
        elif typ.builtin is source.Builtin.PMS:
            return PMS
        elif typ.builtin is source.Builtin.HTD:
            return HTD
    elif isinstance(typ, source.TypeBitVec):
        return SMTLIB(f'(_ BitVec {typ.size})')
    elif isinstance(typ, source.TypeWordArray):
        return word_array(typ)

    assert False, f'unhandled sort {typ}'


def emit_cmd(cmd: Cmd) -> SMTLIB:
    if isinstance(cmd, CmdDeclareFun):
        # (declare-fun func_name (T1 T2 ...) T)
        arg_sorts = " ".join(emit_sort(s) for s in cmd.arg_sorts)
        ret_sort = emit_sort(cmd.ret_sort)
        return SMTLIB(f'(declare-fun {cmd.symbol} ({arg_sorts}) {ret_sort})')
    elif isinstance(cmd, CmdAssert):
        return SMTLIB(f"(assert {emit_expr(cmd.expr)})")
    elif isinstance(cmd, CmdCheckSat):
        return SMTLIB(f"(check-sat)")
    elif isinstance(cmd, CmdDefineFun):
        # (define-fun func_name ((a T1) (b T2) ...) T (body))

        assert RE_VALID_SMTLIB_SIMPLE_SYMBOL.match(
            cmd.symbol), f"function name {cmd.symbol!r} isn't valid"
        for arg in cmd.args:
            assert RE_VALID_SMTLIB_SIMPLE_SYMBOL.match(
                cmd.symbol), f"argument {cmd.symbol!r} isn't valid"

        args = ' '.join(
            f'({identifier(arg.name)} {emit_sort(arg.typ)})' for arg in cmd.args)
        return SMTLIB(f"(define-fun {cmd.symbol} ({args}) {emit_sort(cmd.ret_sort)} {emit_expr(cmd.term)})")
    elif isinstance(cmd, CmdComment):
        if cmd.comment == '':
            return SMTLIB('')
        return SMTLIB('; ' + cmd.comment)
    elif isinstance(cmd, CmdSetLogic):
        return SMTLIB(f'(set-logic {cmd.logic.value})')
    elif isinstance(cmd, CmdDeclareSort):
        return SMTLIB(f"(declare-sort {cmd.symbol} {cmd.arity})")
    elif isinstance(cmd, CmdGetModel):
        return SMTLIB(f"(get-model)")
    assert_never(cmd)


def cmd_assert_eq(name: assume_prove.VarName, rhs: source.ExprT[assume_prove.VarName]) -> Cmd:
    return CmdAssert(source.ExprOp(rhs.typ, source.Operator.EQUALS, (source.ExprVar(rhs.typ, name), rhs)))


def merge_smtlib(it: Iterator[SMTLIB]) -> SMTLIB:
    return SMTLIB('\n'.join(it))


raw_mem_acc_prelude = ['''
(define-fun load-word8 ((m {MemSort}) (p (_ BitVec 64)))
	(_ BitVec 8)
	(select m p)
)
''',
                       '''
(define-fun load-word16 ((m {MemSort}) (p (_ BitVec 64)))
	(_ BitVec 16)
	(concat (select m (bvadd p #x0000000000000001))
		(select m p)
	)
)
''',
                       '''
(define-fun load-word32 ((m {MemSort}) (p (_ BitVec 64)))
	(_ BitVec 32)
	(concat
		(concat (select m (bvadd p #x0000000000000003))
				(select m (bvadd p #x0000000000000002)))
		(concat (select m (bvadd p #x0000000000000001))
				(select m p))
	)
)
''',
                       '''
(define-fun load-word64 ((m {MemSort}) (p (_ BitVec 64)))
	(_ BitVec 64)
	(concat (load-word32 m (bvadd p #x0000000000000004))
			(load-word32 m p)
	)
)
''',
                       '''
(define-fun store-word8 ((m {MemSort}) (p (_ BitVec 64)) (v (_ BitVec 8)))
	{MemSort}
	(store m p v)
)
''',
                       '''
(define-fun store-word16 ((m {MemSort}) (p (_ BitVec 64)) (v (_ BitVec 16)))
	{MemSort}
	(store-word8
		(store-word8 m p ((_ extract 7 0) v))
		(bvadd p #x0000000000000001)
		((_ extract 15 8) v)
	)
)
''',
                       '''
(define-fun store-word32 ((m {MemSort}) (p (_ BitVec 64)) (v (_ BitVec 32)))
	{MemSort}
	(store-word16
		(store-word16 m p ((_ extract 15 0) v))
		(bvadd p #x0000000000000002)
		((_ extract 31 16) v)
	)
)
''',
                       '''
(define-fun store-word64 ((m {MemSort}) (p (_ BitVec 64)) (v (_ BitVec 64)))
	{MemSort}
	(store-word32
		(store-word32 m p ((_ extract 31 0) v))
		(bvadd p #x0000000000000004)
		((_ extract 63 32) v)
	)
)''']


def emit_prelude() -> Sequence[Cmd]:
    pms = CmdDeclareSort(Identifier(str(PMS)), 0)
    prelude: Sequence[Cmd] = [pms]
    return prelude


def gen_mem_acc_prelude() -> SMTLIB:
    raw = [x.format(MemSort=MEM_SORT)+"\n" for x in raw_mem_acc_prelude]
    return SMTLIB(''.join(raw))


def make_smtlib(p: assume_prove.AssumeProveProg, prelude_files: Sequence[str] = (), assert_ok_nodes: Collection[source.NodeName] = (), with_model: bool = False) -> SMTLIB:

    # WARN: Please look at error_reporting.get_sat
    # before changing any of the smt emission code.
    # The error_reporting expects a certain structure in the
    # check-sats emitted.

    emited_identifiers: set[Identifier] = set()
    emitted_symbols: set[source.ExprSymbolT] = set()
    emited_variables: set[assume_prove.VarName] = set()

    cmds: list[Cmd] = []
    cmds.extend(emit_prelude())

    # emit all auxilary variable declaration (declare-fun node_x_ok () Bool)
    for node_ok_name in p.nodes_script:
        cmds.append(CmdDeclareFun(identifier(
            node_ok_name), (), source.type_bool))
        emited_identifiers.add(identifier(node_ok_name))
        emited_variables.add(node_ok_name)

    cmds.append(EmptyLine)

    # ignore node_ok like variables
    # only use variables that can be traced back to the C code & spec.
    expr_variables = set()

    # emit all arguments
    for arg in p.arguments:
        cmds.append(CmdDeclareFun(identifier(arg.name), (), arg.typ))
        emited_identifiers.add(identifier(arg.name))
        emited_variables.add(arg.name)
        expr_variables.add(arg.name)

    # emit all variable declaration (declare-fun y () <sort>)
    for script in p.nodes_script.values():
        for ins in script:
            for var in source.all_vars_in_expr(ins.expr):
                iden = identifier(var.name)
                if iden not in emited_identifiers:
                    cmds.append(CmdDeclareFun(iden, (), var.typ))
                    emited_identifiers.add(iden)
                    emited_variables.add(var.name)
                    expr_variables.add(var.name)
            for symbol in source.all_symbols_in_expr(ins.expr):
                if symbol not in emitted_symbols:
                    # see smt.py, this is where the naming structure comes from
                    cmds.append(CmdDeclareFun(Identifier(
                        f"{symbol.name}@global-symbol"), (), symbol.typ))
                    if symbol not in pg.mem.sym_conds:
                        assert False, f"{symbol} not in program globals"

                    conds = pg.mem.sym_conds[symbol]
                    for cond in conds:
                        cmds.append(CmdAssert(cond))

                emitted_symbols.add(symbol)

    cmds.append(EmptyLine)

    # emit all assertions from nodes (node_x_ok = wp(x))
    for node_ok_name, script in p.nodes_script.items():
        expr = assume_prove.apply_weakest_precondition(script)
        cmds.append(cmd_assert_eq(node_ok_name, expr))

    cmds.append(CmdCheckSat())
    if assert_ok_nodes is not None:
        for ok_node in assert_ok_nodes:
            # sanity check if this assert_additional_node actually exists
            node_ok_name = assume_prove.node_ok_name(ok_node)
            assert node_ok_name in p.nodes_script
            cmds.append(CmdComment(
                "WARNING: NOT A VALID PROOF RELATED SMT EXPORT This is used for error reporting only"))
            cmds.append(CmdAssert(source.ExprVar(
                source.type_bool, node_ok_name)))
            cmds.append(CmdCheckSat())

    cmds.append(CmdAssert(source.expr_negate(
        source.ExprVar(source.type_bool, p.entry))))
    cmds.append(CmdCheckSat())

    raw_prelude = ""
    # overwritten if file prelude exists
    if len(prelude_files) == 0:
        raw_prelude = SMTLIB('(set-logic ALL)')

    # NOTE: prelude order matters
    for file in prelude_files:
        with open(file) as f:
            raw_prelude += SMTLIB(f"; prelude from {file}\n")
            raw_prelude += SMTLIB(f.read() + "\n\n")
    if with_model:
        cmds.append(CmdGetModel())

    clean_smt = merge_smtlib(emit_cmd(cmd) for cmd in cmds)
    return SMTLIB(raw_prelude + gen_mem_acc_prelude() + clean_smt)


class CheckSatResult(Enum):
    # TODO: unknown
    UNSAT = 'unsat'
    SAT = 'sat'


class Solver(Enum):
    Z3 = 'z3'
    CVC5 = 'cvc5'


def get_subprocess_file(solver: Solver, filepath: str) -> Sequence[str]:
    if solver is Solver.Z3:
        return ["z3", "-file:"+filepath]
    elif solver is Solver.CVC5:
        return ["cvc5", "--incremental", "--produce-models", filepath]
    else:
        assert_never(solver)


def send_smtlib(smtlib: SMTLIB, solver: Solver) -> Iterator[CheckSatResult]:
    """Send command to any smt solver and returns a boolean per (check-sat)
    """

    with open_temp_file(suffix='.smt2') as (f, fullpath):
        f.write(smtlib)
        f.close()
        p = subprocess.Popen(get_subprocess_file(
            solver, fullpath), stderr=subprocess.PIPE, stdout=subprocess.PIPE)
        output, error = p.communicate()
        p.wait()
    if p.returncode != 0:
        print("stderr:")
        print(textwrap.indent(error.decode('utf-8'), '   '))
        return

    lines = output.splitlines()
    for ln in lines:
        yield CheckSatResult(ln.decode('utf-8'))


class VerificationResult(Enum):
    OK = 'ok'
    FAIL = 'fail'
    INCONSTENT = 'inconsistent'


def parse_sats(sats: Sequence[CheckSatResult]) -> VerificationResult:
    assert len(sats) == 2

    if sats[0] != CheckSatResult.SAT:
        return VerificationResult.INCONSTENT
    elif sats[1] != CheckSatResult.UNSAT:
        return VerificationResult.FAIL

    return VerificationResult.OK
