from __future__ import annotations

from dataclasses import dataclass
from enum import Enum, unique
from typing import Any, Callable, Generic, Iterator, Literal, Mapping, NamedTuple, NewType, Sequence, Set, TypeAlias, TypeVar, Tuple, cast
import typing
from typing_extensions import assert_never
from provenance import *

import syntax

if typing.TYPE_CHECKING:
    import nip


class ProgVarName(str):
    """ for example foo___int#v """


HumanVarNameSubject = NewType('HumanVarNameSubject', str)

HumanVarNamePathElement = NewType('HumanVarNamePathElement', str)
HumanVarNamePath = tuple[HumanVarNamePathElement, ...]
""" For struct rect, a path might ['botleft', 'x'] for example

For scalar variables, path will be empty
"""


@unique
class HumanVarNameSpecial(Enum):
    RET = 'ret'


class HumanVarName(NamedTuple):
    subject: HumanVarNameSubject | Literal[HumanVarNameSpecial.RET]

    path: HumanVarNamePath
    """ Right now paths aren't supported """

    """ for example foo """
    use_guard: bool
    """ if set to true, this will evaluate to foo#assigned """


class CRetSpecialVar(ProgVarName):
    field_num: int
    """
    When a function returns a composite type (structs or arrays) it returns
    multiple scalar values, instead of a composite object.
    """


# expressions are immutable containers, so they are covariant in their generic
# parameters.
# https://mypy.readthedocs.io/en/stable/generics.html#variance-of-generic-types
VarNameKind = TypeVar("VarNameKind", covariant=True)
TypeKind = TypeVar("TypeKind", covariant=True)

NodeName = NewType('NodeName', str)
NodeNameErr = NodeName('Err')
NodeNameRet = NodeName('Ret')

Path: TypeAlias = tuple[NodeName, ...]


@dataclass(frozen=True, order=True)
class TypeStruct:
    name: str


@dataclass(frozen=True, order=True)
class TypeBitVec:
    """ Synonym for TypeWord
    """
    size: int


@dataclass(frozen=True, order=True)
class TypeArray:
    element_typ: Type
    size: int


@dataclass(frozen=True, order=True)
class TypePtr:
    pointee_type: Type


@dataclass(frozen=True)
class TypeFloatingPoint:
    exp_bits: int
    """ number of bits in the exponent """
    sig_bits: int
    """ number of bits in the significant """


@unique
class Builtin(Enum):
    BOOL = 'Bool'
    MEM = 'Mem'
    """ Memory """
    DOM = 'Dom'
    """ valid domain of memory operations """
    HTD = 'HTD'
    """ heap type description """
    PMS = 'PMS'
    """ phantom machine state """
    UNIT = 'UNIT'
    """ singleton type """
    TYPE = 'Type'
    """ type of Type expression used for pointer validity """
    TOKEN = 'Token'
    """ spec doesn't say what this is """
    ROUNDING_MODE = 'RoundingMode'


@dataclass(frozen=True, order=True)
class TypeBuiltin:
    builtin: Builtin


@dataclass(frozen=True, order=True)
class TypeWordArray:

    index_bits: int
    """ these are guesses from looking at the code, i don't actually know if
        that's what they're meant to represent

        number of bits used for the index?

        """

    value_bits: int
    """ number of bits used per value?
        same as for index_bits, i'm not actually sure
    """


class SpecGhostName(str):
    pass


@dataclass(frozen=True, order=True, slots=True)
class TypeSpecGhost:
    """
    The specification might require keepnig track of more ghost state.

    Own can have multiple spec ghost. They are differentiated by their name.
    """
    name: SpecGhostName


Type = TypeStruct | TypeBitVec | TypePtr | TypeArray | TypeFloatingPoint | TypeBuiltin | TypeWordArray | TypeSpecGhost


def pretty_type_ascii(typ: Type) -> str:
    if isinstance(typ, TypeBitVec):
        return f'BitVec{typ.size}'
    elif isinstance(typ, TypeBuiltin):
        return typ.builtin.value
    elif isinstance(typ, TypeStruct):
        return str(typ)
    elif isinstance(typ, TypePtr):
        return str(typ)
    elif isinstance(typ, TypeArray):
        return str(typ)
    elif isinstance(typ, TypeFloatingPoint):
        return str(typ)
    elif isinstance(typ, TypeBuiltin):
        return str(typ)
    elif isinstance(typ, TypeWordArray):
        return str(typ)
    elif isinstance(typ, TypeSpecGhost):
        return f"sg'{typ.name}'"
    assert_never(typ)


type_bool: Type = TypeBuiltin(Builtin.BOOL)
type_mem: Type = TypeBuiltin(Builtin.MEM)
type_htd: Type = TypeBuiltin(Builtin.HTD)
type_pms: Type = TypeBuiltin(Builtin.PMS)
# TODO: change this
type_ghost: Type = TypeWordArray(50, 64)
type_word8 = TypeBitVec(8)
type_word12 = TypeBitVec(12)
type_word16 = TypeBitVec(16)
type_word32 = TypeBitVec(32)
type_word52 = TypeBitVec(52)
type_word64 = TypeBitVec(64)


def convert_type(typ: syntax.Type) -> Type:
    if typ.kind == 'Word':
        if typ.num == 8:
            return type_word8
        elif typ.num == 32:
            return type_word32
        elif typ.num == 64:
            return type_word64
        return TypeBitVec(typ.num)
    elif typ.kind == 'Ptr':
        assert typ.el_typ_symb is not None
        return TypePtr(typ.el_typ_symb)
    elif typ.kind == 'Array':
        assert typ.el_typ_symb is not None
        return TypeArray(convert_type(typ.el_typ_symb), typ.num)
    elif typ.kind == 'FloatingPoint':
        assert False, "floating points not supported yet"
        return TypeFloatingPoint(typ.nums[0], typ.nums[1])
    elif typ.kind == 'Struct':
        return TypeStruct(typ.name)
    elif typ.kind == 'Builtin':
        return TypeBuiltin(Builtin(typ.name))
    elif typ.kind == 'WordArray':
        return TypeWordArray(typ.nums[0], typ.nums[1])
    raise NotImplementedError(f"Type {typ.kind} not implemented")


@dataclass(frozen=True)
class ABCExpr(Generic[TypeKind, VarNameKind]):
    typ: TypeKind


@dataclass(frozen=True, order=True)
class ExprVar(ABCExpr[TypeKind, VarNameKind]):
    name: VarNameKind


ExprVarT: TypeAlias = ExprVar[Type, VarNameKind]


@dataclass(frozen=True)
class ExprForall(ABCExpr[TypeKind, VarNameKind]):
    args: Sequence[ExprVar[TypeKind, Any]]
    expr: Expr[TypeKind, VarNameKind]
    pattern: Expr[TypeKind, Any]
    named: str
    skolemId: str


@dataclass(frozen=True)
class ExprNum(ABCExpr[TypeKind, Any]):
    num: int


ExprNumT: TypeAlias = ExprNum[Type]


@dataclass(frozen=True)
class ExprType(ABCExpr[TypeKind, Any]):
    """ should have typ builtin.Type
    """
    val: Type


ExprTypeT: TypeAlias = ExprType[Type]


@dataclass(frozen=True)
class ExprSymbol(ABCExpr[TypeKind, Any]):
    name: str


ExprSymbolT: TypeAlias = ExprSymbol[Type]

FunctionName = NewType('FunctionName', str)
""" This is an *smt* function, not a C function """


@dataclass(frozen=True)
class ExprFunction(ABCExpr[VarNameKind, TypeKind]):
    """ This is an *smt* function, not a C function """
    function_name: FunctionName
    arguments: Sequence[Expr[VarNameKind, TypeKind]]


ExprFunctionT: TypeAlias = ExprFunction[Type, VarNameKind]


@unique
class Operator(Enum):
    """ To convert graph lang operator name to this enum, just do Operator(parsed_operator_name)

    Some operators that are specified in the spec aren't used.
    Some operators that are used aren't specified in the spec.
    """
    PLUS = 'Plus'
    MINUS = 'Minus'
    TIMES = 'Times'
    MODULUS = 'Modulus'
    DIVIDED_BY = 'DividedBy'

    BW_AND = 'BWAnd'
    BW_OR = 'BWOr'
    BW_XOR = 'BWXor'

    SHIFT_LEFT = 'ShiftLeft'
    SHIFT_RIGHT = 'ShiftRight'
    SIGNED_SHIFT_RIGHT = 'SignedShiftRight'

    AND = 'And'
    OR = 'Or'
    IMPLIES = 'Implies'

    NOT = 'Not'

    TRUE = 'True'
    FALSE = 'False'

    EQUALS = 'Equals'
    LESS = 'Less'
    LESS_EQUALS = 'LessEquals'
    SIGNED_LESS = 'SignedLess'
    SIGNED_LESS_EQUALS = 'SignedLessEquals'

    BW_NOT = 'BWNot'
    WORD_REVERSE = 'WordReverse'
    WORD_CAST = 'WordCast'
    WORD_CAST_SIGNED = 'WordCastSigned'

    MEM_ACC = 'MemAcc'
    MEM_UPDATE = 'MemUpdate'

    WORD_ARRAY_ACCESS = 'WordArrayAccess'
    WORD_ARRAY_UPDATE = 'WordArrayUpdate'

    P_VALID = 'PValid'
    P_WEAK_VALID = 'PWeakValid'
    P_ALIGN_VALID = 'PAlignValid'
    P_GLOBAL_VALID = 'PGlobalValid'
    P_ARRAY_VALID = 'PArrayValid'

    MEM_DOM = 'MemDom'
    HTD_UPDATE = 'HTDUpdate'
    IF_THEN_ELSE = 'IfThenElse'

    CONCAT = 'Concat'

    # COUNT_LEADING_ZEROES = 'CountLeadingZeros'
    # COUNT_TRAILING_ZEROES = 'CountTrailingZeroes'

    # ROUND_NEAREST_TIES_TO_EVEN = 'roundNearestTiesToEven'
    # ROUND_NEAREST_TIES_TO_AWAY = 'roundNearestTiesToAway'
    # ROUND_TOWARD_POSITIVE = 'roundTowardPositive'
    # ROUND_TOWARD_NEGATIVE = 'roundTowardNegative'
    # ROUND_TOWARD_ZERO = 'roundTowardZero'

    # optional apparently
    # FP_ABS = 'fp.abs'
    # FP_NEG = 'fp.neg'
    # FP_ADD = 'fp.add'
    # FP_SUB = 'fp.sub'
    # FP_MUL = 'fp.mul'
    # FP_DIV = 'fp.div'
    # FP_FMA = 'fp.fma'
    # FP_SQRT = 'fp.sqrt'
    # FP_REM = 'fp.rem'
    # FP_ROUND_TO_INTEGRAL = 'fp.roundToIntegral'
    # FP_MIN = 'fp.min'
    # FP_MAX = 'fp.max'
    # FP_LEQ = 'fp.leq'
    # FP_LT = 'fp.lt'
    # FP_GEQ = 'fp.geq'
    # FP_GT = 'fp.gt'
    # FP_EQ = 'fp.eq'
    # FP_IS_NORMAL = 'fp.isNormal'
    # FP_IS_SUBNORMAL = 'fp.IsSubnormal'
    # FP_IS_ZERO = 'fp.isZero'
    # FP_IS_INFINITE = 'fp.isInfinite'
    # FP_IS_NAN = 'fp.isNaN'
    # FP_IS_NEGATIVE = 'fp.isNegative'
    # FP_IS_POSITIVE = 'fp.isPositive'

    # TO_FLOATING_POINT = 'ToFloatingPoint'
    # TO_FLOATING_POINT_SIGNED = 'ToFloatingPointSigned'
    # TO_FLOATING_POINT_UNSIGNED = 'ToFloatingPointUnsigned'
    # FLOATING_POINT_CAST = 'FloatingPointCast'


# operators that take no arguments
nulary_operators = {Operator.TRUE, Operator.FALSE}

pretty_binary_operators_ascii = {
    Operator.PLUS: '+',
    Operator.MINUS: '-',

    Operator.TIMES: '*',
    Operator.MODULUS: '%',
    Operator.DIVIDED_BY: '/',

    Operator.BW_AND: '&',
    Operator.BW_OR: '|',
    Operator.BW_XOR: '^',

    Operator.SHIFT_LEFT: '<<',
    Operator.SHIFT_RIGHT: '>>',
    Operator.SIGNED_SHIFT_RIGHT: '>>s',

    Operator.AND: '&&',
    Operator.OR: '||',
    Operator.IMPLIES: '->',

    Operator.EQUALS: '=',
    Operator.LESS: '<',
    Operator.LESS_EQUALS: '<=',
    Operator.SIGNED_LESS: '<s',
    Operator.SIGNED_LESS_EQUALS: '<=s',
}


@dataclass(frozen=True)
class ExprOp(ABCExpr[TypeKind, VarNameKind]):
    operator: Operator
    operands: tuple[Expr[TypeKind, VarNameKind], ...]


ExprOpT: TypeAlias = ExprOp[Type, VarNameKind]


Expr: TypeAlias = \
    ExprVar[TypeKind, VarNameKind] \
    | ExprNum[TypeKind] \
    | ExprType[TypeKind] \
    | ExprOp[TypeKind, VarNameKind] \
    | ExprFunction[TypeKind, VarNameKind] \
    | ExprSymbol[TypeKind] \
    | ExprForall[TypeKind, VarNameKind] \

ExprT: TypeAlias = Expr[Type, VarNameKind]

ProgVar: TypeAlias = ExprVarT[ProgVarName]

expr_true: Expr[Type, Any] = ExprOp(type_bool, Operator.TRUE, ())
expr_false: Expr[Type, Any] = ExprOp(type_bool, Operator.FALSE, ())

# testing the type checker
expr0: Expr[int, str] = ExprVar(2, 'variable')  # pass
expr1: Expr[Type, str] = ExprVar(type_bool, 'variable')  # pass
expr2: ExprT[str] = ExprVar(type_bool, 'variable')  # pass
expr3: ExprT[str] = ExprVar(type_bool, 'variable')  # pass
expr4: ExprVar[Type, str] = ExprVar(type_bool, 'foo')  # pass
expr5: ExprVarT[str] = ExprVar(type_bool, 'bar')  # pass
# expr5: Expr[int, bool] = ExprOp(type_bool, Operator.AND, ())  # fail


def visit_expr(expr: ExprT[VarNameKind], visitor: Callable[[ExprT[VarNameKind]], None]) -> None:
    visitor(expr)
    if isinstance(expr, ExprOp):
        for operand in expr.operands:
            visit_expr(operand, visitor)
    elif isinstance(expr, ExprFunction):
        for arg in expr.arguments:
            visit_expr(arg, visitor)
    elif not isinstance(expr, ExprVar
                        | ExprNum | ExprType | ExprSymbol | ExprForall):
        assert_never(expr)


def expr_where_vars_are_used_in_node(node: Node[VarNameKind], selection: Set[ExprVarT[VarNameKind]]) -> Iterator[tuple[ExprVarT[VarNameKind], ExprT[VarNameKind]]]:
    if isinstance(node, NodeBasic):
        for upd in node.upds:
            for var in selection & all_vars_in_expr(upd.expr):
                yield var, upd.expr
    elif isinstance(node, NodeCall):
        for arg in node.args:
            for var in selection & all_vars_in_expr(arg):
                yield var, arg
    elif isinstance(node, NodeCond | NodeAssume | NodeAssert):
        for var in selection & all_vars_in_expr(node.expr):
            yield var, node.expr
    elif not isinstance(node, NodeEmpty):
        assert_never(node)


def pretty_expr_ascii(expr: ExprT[VarNameKind]) -> str:
    if isinstance(expr, ExprNum):
        return str(expr.num)
    elif isinstance(expr, ExprSymbol):
        return expr.name
    elif isinstance(expr, ExprType):
        return str(expr.val)
    elif isinstance(expr, ExprVar):
        if isinstance(expr.name, str):
            return expr.name
        if isinstance(expr.name, tuple):
            assert len(expr.name) == 2
            assert isinstance(expr.name[0], str)
            assert isinstance(expr.name[1], int)
            return f'{expr.name[0]}:{expr.name[1]}'
        assert False, f'{expr}'
    elif isinstance(expr, ExprOp):
        if expr.operator in pretty_binary_operators_ascii:
            assert len(
                expr.operands) == 2, f"{len(expr.operands)} {expr.operator}"
            return f'({pretty_expr_ascii(expr.operands[0])} {pretty_binary_operators_ascii[expr.operator]} {pretty_expr_ascii(expr.operands[1])})'
        elif expr.operator == Operator.IF_THEN_ELSE:
            assert len(expr.operands) == 3
            cond, then, otherwise = (pretty_expr_ascii(operand)
                                     for operand in expr.operands)
            return f'({cond} ? {then} : {otherwise})'
        else:
            return f'{expr.operator.value}({", ".join(pretty_expr_ascii(operand) for operand in expr.operands)})'
    elif isinstance(expr, ExprFunction):
        return f'{expr.function_name} {" ".join(pretty_expr_ascii(arg) for arg in expr.arguments)}'
    elif isinstance(expr, ExprForall):
        return f"""
(forall ({" ".join('(' + pretty_expr_ascii(arg) + ' ' + pretty_type_ascii(arg.typ) + ')' for arg in expr.args)}) 
    ({pretty_expr_ascii(expr.expr)}) 
    :pattern ({pretty_expr_ascii(expr.pattern)})
)"""

    assert_never(expr)


def convert_expr(expr: syntax.Expr) -> ExprT[ProgVarName]:
    typ = convert_type(expr.typ)
    if expr.kind == 'Op':
        return ExprOp(typ, Operator(expr.name), tuple(convert_expr(operand) for operand in expr.vals))
    elif expr.kind == 'Var':
        return ExprVar(typ, ProgVarName(expr.name))
    elif expr.kind == 'Num':
        return ExprNum(typ, expr.val)
    elif expr.kind == 'Type':
        return ExprType(typ, convert_type(expr.val))
    elif expr.kind == 'Symbol':
        return ExprSymbol(typ, expr.name)
    raise NotImplementedError


def all_vars_in_expr(expr: ExprT[VarNameKind]) -> set[ExprVarT[VarNameKind]]:
    s: set[ExprVarT[VarNameKind]] = set()

    def visitor(expr: ExprT[VarNameKind]) -> None:
        if isinstance(expr, ExprVar):
            s.add(ExprVar(expr.typ, expr.name))
    visit_expr(expr, visitor)
    return s


def all_symbols_in_expr(expr: ExprT[VarNameKind]) -> set[ExprSymbolT]:
    s: set[ExprSymbolT] = set()

    def visitor(expr: ExprT[VarNameKind]) -> None:
        if isinstance(expr, ExprSymbol):
            s.add(expr)
    visit_expr(expr, visitor)
    return s


VarNameKind2 = TypeVar('VarNameKind2', covariant=True)

# type hints could be stronger (when expr is ExprVar, we return an ExprVar,
# etc) but I don't think python allows for it (unless we use overloads)


def convert_expr_vars(f: Callable[[ExprVar[TypeKind, VarNameKind]], Expr[TypeKind, VarNameKind2]], expr: Expr[TypeKind, VarNameKind]) -> Expr[TypeKind, VarNameKind2]:
    if isinstance(expr, ExprNum):
        return expr
    elif isinstance(expr, ExprVar):
        return f(expr)
    elif isinstance(expr, ExprOp):
        ops = tuple(convert_expr_vars(f, operand) for operand in expr.operands)
        return ExprOp(expr.typ, Operator(expr.operator), operands=ops)
    elif isinstance(expr, ExprType | ExprSymbol):
        return expr
    elif isinstance(expr, ExprFunction):
        args = tuple(convert_expr_vars(f, arg) for arg in expr.arguments)
        return ExprFunction(expr.typ, expr.function_name, args)
    elif isinstance(expr, ExprForall):

        expr_inner = convert_expr_vars(f, expr.expr)
        return ExprForall(expr.typ, expr.args, expr_inner, expr.pattern, expr.named, expr.skolemId)

    assert_never(expr)


def expr_eq(lhs: ExprT[VarNameKind], rhs: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    """ equate """
    assert lhs.typ == rhs.typ
    return ExprOp(type_bool, Operator.EQUALS, (lhs, rhs))


def expr_neq(lhs: ExprT[VarNameKind], rhs: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    assert lhs.typ == rhs.typ
    return expr_negate(expr_eq(lhs, rhs))


def mk_binary_bitvec_operation(op: Operator) -> Callable[[ExprT[VarNameKind], ExprT[VarNameKind]], ExprT[VarNameKind]]:
    def f(lhs: ExprT[VarNameKind], rhs: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
        assert lhs.typ == rhs.typ
        assert isinstance(lhs.typ, TypeBitVec)
        return ExprOp(lhs.typ, op, (lhs, rhs))
    return f


def mk_binary_bitvec_relation(op: Operator) -> Callable[[ExprT[VarNameKind], ExprT[VarNameKind]], ExprT[VarNameKind]]:
    def f(lhs: ExprT[VarNameKind], rhs: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
        assert lhs.typ == rhs.typ
        assert isinstance(lhs.typ, TypeBitVec)
        return ExprOp(type_bool, op, (lhs, rhs))
    return f


def expr_valid(htd: ExprT[VarNameKind], ty: Type, loc: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    assert htd.typ == type_htd
    assert loc.typ == type_word64
    return ExprOp(type_bool, Operator.P_VALID, (htd, ExprType(ty, ty), loc))


expr_ult = mk_binary_bitvec_relation(Operator.LESS)
expr_ule = mk_binary_bitvec_relation(Operator.LESS_EQUALS)
expr_slt = mk_binary_bitvec_relation(Operator.SIGNED_LESS)
expr_sle = mk_binary_bitvec_relation(Operator.SIGNED_LESS_EQUALS)
expr_mul = mk_binary_bitvec_operation(Operator.TIMES)
expr_plus = mk_binary_bitvec_operation(Operator.PLUS)
expr_sub = mk_binary_bitvec_operation(Operator.MINUS)
expr_udiv = mk_binary_bitvec_operation(Operator.DIVIDED_BY)
expr_shift_left = mk_binary_bitvec_operation(Operator.SHIFT_LEFT)
expr_shift_right = mk_binary_bitvec_operation(Operator.SHIFT_RIGHT)
# don't implement expr_sdiv (cparser will never generate signed division)


def expr_ite(cond: ExprT[VarNameKind], yes: ExprT[VarNameKind], no: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    assert yes.typ == no.typ
    assert cond.typ == type_bool
    return ExprOp(yes.typ, Operator.IF_THEN_ELSE, (cond, yes, no))


def expr_negate(expr: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    assert expr.typ == type_bool

    if isinstance(expr, ExprOp) and expr.operator == Operator.NOT:
        assert len(expr.operands) == 1
        return expr.operands[0]

    if expr == expr_true:
        return expr_false
    if expr == expr_false:
        return expr_true

    return ExprOp(type_bool, Operator.NOT, (expr, ))


def expr_or(lhs: ExprT[VarNameKind], rhs: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    assert lhs.typ == type_bool
    assert rhs.typ == type_bool

    if lhs == expr_true or rhs == expr_true:
        return expr_true
    if lhs == expr_false:
        return rhs
    if rhs == expr_false:
        return lhs

    return ExprOp(type_bool, Operator.OR, (lhs, rhs))


def expr_and(lhs: ExprT[VarNameKind], rhs: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    assert lhs.typ == type_bool
    assert rhs.typ == type_bool

    if lhs == expr_true:
        return rhs
    if rhs == expr_true:
        return lhs
    if lhs == expr_false or rhs == expr_false:
        return expr_false

    return ExprOp(type_bool, Operator.AND, (lhs, rhs))


def expr_implies(antecedent: ExprT[VarNameKind], consequent: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    assert antecedent.typ == type_bool
    assert consequent.typ == type_bool
    return ExprOp(type_bool, Operator.IMPLIES, (antecedent, consequent))


def expr_split_conjuncts(expr: ExprT[VarNameKind]) -> Iterator[ExprT[VarNameKind]]:
    if isinstance(expr, ExprOp) and expr.operator == Operator.AND:
        for operand in expr.operands:
            yield from expr_split_conjuncts(operand)
    else:
        yield expr


def condition_to_evaluate_subexpr_in_expr(expr: ExprT[VarNameKind], sub: ExprT[VarNameKind]) -> ExprT[VarNameKind]:
    # traverse down the if, building up the condition to reach a particular variable
    if isinstance(expr, ExprNum):
        if expr == sub:
            return expr_true
        return expr_false
    elif isinstance(expr, ExprVar):
        if expr == sub:
            return expr_true
        return expr_false
    elif isinstance(expr, ExprOp):
        reachability_condition = [condition_to_evaluate_subexpr_in_expr(
            operand, sub) for operand in expr.operands]

        disjunctions = [d for d in reachability_condition if d != expr_false]

        # none of the operands use the sub expression
        if len(disjunctions) == 0:
            return expr_false

        if expr.operator is Operator.IF_THEN_ELSE and reachability_condition != [expr_true, expr_true]:
            assert len(expr.operands) == 3
            cond, then, otherwise = expr.operands

            # a bunch of shortcuts to emit smaller expressions
            # sub expression is used in the condition, so there is no escaping anything
            if reachability_condition[0] == expr_true:
                return expr_true
            if reachability_condition[0] == expr_false and reachability_condition[1] == expr_false:
                return expr_and(expr_negate(cond), reachability_condition[2])
            if reachability_condition[0] == expr_false and reachability_condition[2] == expr_false:
                return expr_and(cond, reachability_condition[1])

            # subexpr used in condition
            #   OR (condition AND subexpr used in then branch)
            #   OR (NOT condition AND subexpr used in else branch)

            branches = expr_or(
                expr_and(cond, reachability_condition[1]),
                expr_and(expr_negate(cond), reachability_condition[2])
            )
            return expr_or(reachability_condition[0], branches)

        # one operand always uses the sub expression
        if expr_true in disjunctions:
            return expr_true

        # either sub expression is used in first operand, or second operand, etc...
        cond = disjunctions[0]
        for op in disjunctions[1:]:
            cond = expr_or(cond, op)
        return cond
    elif isinstance(expr, ExprFunction):
        conditions = [condition_to_evaluate_subexpr_in_expr(
            arg, sub) for arg in expr.arguments]
        cond = expr_false
        for op in conditions:
            cond = expr_or(cond, op)
        return cond

    elif isinstance(expr, ExprType | ExprSymbol):
        assert False, "I'm not sure what this is suppose to mean"
    elif isinstance(expr, ExprForall):
        assert False, "not sure what to do here yet"
    assert_never(expr)

# for the following commented out expr classes
# not present in the kernel functions, I don't want to make an abstraction for
# something i can't even test once

# @dataclass(frozen=True)
# class ExprField(ExprT[VarNameKind]):
#     struct: ExprT[VarNameKind]
#     field_name: str
#     field_type: Type

# @dataclass(frozen=True)
# class ExprFieldUpd(ExprT[VarNameKind]):
#     struct: ExprT[VarNameKind]
#     field_name: str
#     field_type: Type
#     val: ExprT[VarNameKind]

#
# @dataclass(frozen=True)
# class ExprStructCons(ExprT[VarNameKind]):
#     inits: Mapping[]


@dataclass(frozen=True)
class ABCNode(Generic[VarNameKind]):
    origin: Provenance


@dataclass(frozen=True)
class Update(Generic[VarNameKind]):
    var: ExprVar[Type, VarNameKind]
    expr: ExprT[VarNameKind]


@dataclass(frozen=True)
class NodeEmpty(ABCNode[VarNameKind]):
    succ: NodeName


@dataclass(frozen=True)
class NodeBasic(ABCNode[VarNameKind]):
    upds: tuple[Update[VarNameKind], ...]
    succ: NodeName


@dataclass(frozen=True)
class NodeCall(ABCNode[VarNameKind]):
    succ: NodeName
    fname: str
    args: tuple[ExprT[VarNameKind], ...]
    rets: tuple[ExprVar[Type, VarNameKind], ...]


@dataclass(frozen=True)
class NodeCond(ABCNode[VarNameKind]):
    expr: ExprT[VarNameKind]
    succ_then: NodeName
    succ_else: NodeName


@dataclass(frozen=True)
class NodeAssume(ABCNode[VarNameKind]):
    expr: ExprT[VarNameKind]
    succ: NodeName


@dataclass(frozen=True)
class NodeAssert(ABCNode[VarNameKind]):
    expr: ExprT[VarNameKind]
    succ: NodeName


Node = NodeBasic[VarNameKind] | NodeCall[VarNameKind] | NodeCond[
    VarNameKind] | NodeEmpty | NodeAssume[VarNameKind] | NodeAssert[VarNameKind]

LoopHeaderName = NewType('LoopHeaderName', NodeName)


@dataclass(frozen=True)
class Loop(Generic[VarNameKind]):
    back_edge: tuple[NodeName, NodeName]
    """
    back_edge = (latch, loop header)
    """

    nodes: tuple[NodeName, ...]
    """ nodes forming a natural loop """

    targets: Sequence[ExprVarT[VarNameKind]]
    """ All the variables that are written to during the loop
    """

    @property
    def header(self) -> NodeName:
        return self.back_edge[1]


# FIXME: circular import
import abc_cfg  # nopep8


@dataclass(frozen=True)
class GhostlessFunction(Generic[VarNameKind, VarNameKind2]):
    """
    First generic parameter: var name kind for nodes
    Second generic parameter: var name kind for ghost
    """

    name: str

    cfg: abc_cfg.CFG

    # TODO: find good way to freeze dict and keep type hints
    nodes: Mapping[NodeName, Node[VarNameKind]]

    variables: Set[ExprVarT[VarNameKind]]
    """
    Node name => Node
    """

    loops: Mapping[LoopHeaderName, Loop[VarNameKind]]
    """
    loop header => loop information
    """

    signature: FunctionSignature[VarNameKind]

    def c_return(self, path: HumanVarNamePath) -> ExprVarT[ProgVarName] | None:
        """
        A function may return multiple values, but the C function only
        returns one. This functions returns that variable.

        If the C function has return type void, this function returns None.

        TODO: This doesn't support struct or arrays (they are split as
        individual scalars, so there would be multiple ret__ variables).
        => Always give in an empty path.
        """
        if len(path) > 0:
            raise NotImplementedError("struct and arrays aren't supported yet")

        c_ret: ExprVarT[ProgVarName] | None = None
        for ret in self.signature.returns:
            if ret.name.startswith('ret__'):
                assert c_ret is None, f'found 2 ret__ variables {ret.name} {c_ret}'
                c_ret = ret

        assert c_ret is not None, f"didn't find a c ret variable"
        return c_ret

    def is_loop_header(self, node_name: NodeName) -> LoopHeaderName | None:
        if node_name in self.loops:
            return LoopHeaderName(node_name)
        return None

    def is_loop_latch(self, node_name: NodeName) -> LoopHeaderName | None:
        """ A loop latch is a node which jumps *back* to the loop header (LLVM terminology)

              n1
              |
              v
        n5 <- n2 <---|
              |      |
              v      |
              n3 --> n4

        n1: entry
        n2: loop header
        n3: normal node
        n4: latch
        n5: loop exit
        """
        for succ in self.cfg.all_succs[node_name]:
            lh = self.is_loop_header(succ)
            if lh and node_name in self.loops[lh].nodes:
                assert (node_name, succ) in self.cfg.back_edges
                return lh

        return None

    def is_loop_latch_or_loop_entry(self, node_name: NodeName) -> bool:
        return any(self.is_loop_header(succ) is not None for succ in self.cfg.all_succs[node_name])

    def acyclic_preds_of(self, node_name: NodeName) -> Iterator[NodeName]:
        """ returns all the direct predecessors, removing the ones that would follow back edges """
        return (p for p in self.cfg.all_preds[node_name] if (p, node_name) not in self.cfg.back_edges)

    def traverse_topologically_bottom_up(self) -> Iterator[NodeName]:
        q: list[NodeName] = [n for n, succs in self.cfg.all_succs.items() if len(
            [succ for succ in succs if (n, succ) not in self.cfg.back_edges]) == 0]
        visited: set[NodeName] = set()

        while q:
            n = q.pop(-1)
            if n in visited:
                continue

            if any(succ not in visited for succ in self.cfg.all_succs[n] if (n, succ) not in self.cfg.back_edges):
                continue

            visited.add(n)
            yield n

            for pred in self.cfg.all_preds[n]:
                if (pred, n) not in self.cfg.back_edges:
                    q.append(pred)

        assert len(visited - {NodeNameErr, NodeNameRet}
                   ) == len(self.nodes), visited

    def traverse_topologically(self, skip_err_and_ret: bool = False) -> Iterator[NodeName]:
        q: list[NodeName] = [
            n for n, preds in self.cfg.all_preds.items() if len([p for p in self.acyclic_preds_of(n)]) == 0]
        visited: set[NodeName] = set()
        while q:
            n = q.pop(-1)
            if n in visited:
                continue

            if not all(p in visited for p in self.acyclic_preds_of(n)):
                continue

            visited.add(n)
            if n not in (NodeNameErr, NodeNameRet) or not skip_err_and_ret:
                yield n

            for succ in self.cfg.all_succs[n]:
                if (n, succ) not in self.cfg.back_edges:
                    q.append(succ)

        assert len(visited - {NodeNameErr, NodeNameRet}) == len(self.nodes)

    def all_variables(self) -> Set[ExprVarT[VarNameKind]]:
        all_vars: set[ExprVarT[VarNameKind]] = set()
        all_vars.update(self.signature.parameters)
        for n, node in self.nodes.items():
            all_vars.update(used_variables_in_node(node))
            all_vars.update(assigned_variables_in_node(
                self, n, with_loop_targets=True))
        return all_vars

    def with_ghost(self, ghost: Ghost[ProgVarName | nip.GuardVarName] | None) -> GenericFunction[VarNameKind, ProgVarName | nip.GuardVarName]:
        if ghost is None:
            ghost = Ghost(precondition=expr_true,
                          postcondition=expr_true,
                          loop_invariants={lh: expr_true for lh in self.loops},
                          loop_iterations={
                              lh: empty_loop_ghost for lh in self.loops},
                          )

        if self.loops.keys() != ghost.loop_invariants.keys():
            print("Expected loop invariants: ", self.loops.keys())
            print("Got loop invariants: ", ghost.loop_invariants.keys())
            assert False, "loop invariants don't match"
        return GenericFunction(name=self.name, variables=self.variables, nodes=self.nodes, loops=self.loops, signature=self.signature, cfg=self.cfg, ghost=ghost)


@dataclass(frozen=True)
class LoopIterationGhost(Generic[VarNameKind]):
    pre_iter: ExprT[VarNameKind]
    """ This is pre_iter is dangerous. It is assumed, but never proved within
        this tool. So using false as a pre_iter for example will mean the loop
        will always verify, even when it shouldn't.

        We use them to implement oracles. Those oracles will be connected to
        the rest of the proofs, but _outside_ of this tool.

        This is why loop iteration conditions are packaged with loop
        invariants. Most code won't and shouldn't use them.
    """

    post_iter: ExprT[VarNameKind]


empty_loop_ghost: LoopIterationGhost[Any] = LoopIterationGhost(
    expr_true, expr_true)


@dataclass(frozen=True)
class Ghost(Generic[VarNameKind]):
    # TODO: ensure on construction that loop invariants and loop iterations
    # have the same keys

    precondition: ExprT[VarNameKind]
    postcondition: ExprT[VarNameKind]
    loop_invariants: Mapping[LoopHeaderName, ExprT[VarNameKind]]
    loop_iterations: Mapping[LoopHeaderName, LoopIterationGhost[VarNameKind]]


@dataclass(frozen=True)
class GenericFunction(GhostlessFunction[VarNameKind, VarNameKind2]):
    ghost: Ghost[VarNameKind2]


Function: TypeAlias = 'GenericFunction[ProgVarName, ProgVarName | nip.GuardVarName]'


def is_loop_counter_name(var: str) -> bool:
    return (var.startswith("loop#")
            and var.endswith("#count")
            and all(map(lambda c: ord('0') <= ord(c) and ord(c) <= ord('9'), var[len("loop#"):-len("#count")])))


def used_variables_in_node(node: Node[VarNameKind]) -> Set[ExprVarT[VarNameKind]]:
    used_variables: set[ExprVarT[VarNameKind]] = set()
    if isinstance(node, NodeBasic):
        for upd in node.upds:
            used_variables |= all_vars_in_expr(upd.expr)
    elif isinstance(node, NodeCall):
        for arg in node.args:
            used_variables |= all_vars_in_expr(arg)
    elif isinstance(node, NodeCond | NodeAssume | NodeAssert):
        used_variables |= all_vars_in_expr(node.expr)
    elif not isinstance(node, NodeEmpty):
        assert_never(node)
    return used_variables


def assigned_variables_in_node(func: GhostlessFunction[VarNameKind, Any], n: NodeName, *, with_loop_targets: bool) -> Set[ExprVarT[VarNameKind]]:
    if n in (NodeNameRet, NodeNameErr):
        return set()

    assigned_variables: set[ExprVarT[VarNameKind]] = set()
    node = func.nodes[n]
    expected_length = 0
    if isinstance(node, NodeBasic):
        assigned_variables.update(upd.var for upd in node.upds)
        expected_length += len(node.upds)
    elif isinstance(node, NodeCall):
        assigned_variables.update(ret for ret in node.rets)
        expected_length += len(node.rets)
    elif not isinstance(node, NodeEmpty | NodeCond | NodeAssume | NodeAssert):
        # technically, NodeAssume can encode an assignment
        # but it's just the wrong tool for the job, because the nip
        # stage won't automatically know that it was assigned,
        # so you'll have to do that yourself (and that's risky)
        #
        # so we say they never assign any variable
        assert_never(node)

    if (loop_header := func.is_loop_header(n)) and with_loop_targets:
        assigned_variables.update(func.loops[loop_header].targets)
        expected_length += len(func.loops[loop_header].targets)

    assert len(assigned_variables) == expected_length

    return assigned_variables


"""
This step (inserting the ghost state) should be done in one clean stage,
instead of hooking up here.

This is not done now because the later stage ghost code manually load
functions again, so we have to change the source. In the future, we will only
ever load once (and thus patch once and for all).
"""


@dataclass(frozen=True, slots=True, order=True)
class SpecGhost:
    name: str
    bit_size: int


"""
This should be loaded from a specification description (ie. a prelude and list
of spec ghosts). This will be done in the stage mentionned above.
"""
# spec_ghosts: tuple[SpecGhost, ...] = (
#     SpecGhost(name="local_context", bit_size=407), )
spec_ghosts: tuple[SpecGhost, ...] = (SpecGhost(name="test", bit_size=32), )


def mk_spec_ghost_var(sg: SpecGhost) -> ExprVarT[ProgVarName]:
    return ExprVar(TypeBitVec(sg.bit_size), ProgVarName(sg.name + '#ghost'))


def convert_function_nodes(nodes: Mapping[str | int, syntax.Node]) -> Mapping[NodeName, Node[ProgVarName]]:
    safe_nodes: dict[NodeName, Node[ProgVarName]] = {}
    for name, node in nodes.items():
        name = NodeName(str(name))
        if node.kind == "Basic":
            if len(node.upds) == 0:
                safe_nodes[name] = NodeEmpty(succ=NodeName(
                    str(node.cont)), origin=Provenance.NODE_EMPTY)
            else:
                upds: list[Update[ProgVarName]] = []
                for var, expr in node.upds:
                    upds.append(Update(
                        var=ExprVarT[ProgVarName](
                            convert_type(var[1]), ProgVarName(var[0])),
                        expr=convert_expr(expr)))
                safe_nodes[name] = NodeBasic(origin=Provenance.GRAPHLANG, upds=tuple(
                    upds), succ=NodeName(str(node.cont)))
        elif node.kind == "Call":
            safe_nodes[name] = NodeCall(
                origin=Provenance.GRAPHLANG,
                succ=NodeName(str(node.cont)),
                fname=node.fname,
                args=tuple(convert_expr(arg) for arg in node.args)
                + tuple(mk_spec_ghost_var(sg) for sg in spec_ghosts),
                rets=tuple(ExprVar(convert_type(typ), ProgVarName(name))
                           for name, typ in node.rets)
                + tuple(mk_spec_ghost_var(sg) for sg in spec_ghosts))

        elif node.kind == "Cond":
            safe_nodes[name] = NodeCond(
                origin=Provenance.GRAPHLANG,
                succ_then=NodeName(str(node.left)), succ_else=NodeName(str(node.right)), expr=convert_expr(node.cond))
        else:
            raise ValueError(f"unknown kind {node.kind!r}")
    return safe_nodes


@dataclass(frozen=True)
class FunctionSignature(Generic[VarNameKind]):
    parameters: Tuple[ExprVarT[VarNameKind], ...]
    returns: Tuple[ExprVarT[ProgVarName], ...]


def convert_function_metadata(func: syntax.Function) -> FunctionSignature[ProgVarName]:
    args = tuple(ExprVar(convert_type(typ), ProgVarName(name))
                 for name, typ in func.inputs) \
        + tuple(mk_spec_ghost_var(sg) for sg in spec_ghosts)

    rets = tuple(ExprVar(convert_type(typ), ProgVarName(name))
                 for name, typ in func.outputs) \
        + tuple(mk_spec_ghost_var(sg) for sg in spec_ghosts)

    return FunctionSignature(args, rets)


def get_function_variables(func: GhostlessFunction[ProgVarName, Any], nodes: Mapping[NodeName, Node[ProgVarName]]) -> Set[ExprVarT[ProgVarName]]:
    s: Set[ExprVarT[ProgVarName]] = set()
    for node_name, node in nodes.items():
        s.update(used_variables_in_node(node))
        s.update(assigned_variables_in_node(
            func, node_name, with_loop_targets=True))
    return s


def convert_function(func: syntax.Function) -> GhostlessFunction[ProgVarName, Any]:
    safe_nodes = convert_function_nodes(func.nodes)
    all_succs = abc_cfg.compute_all_successors_from_nodes(safe_nodes)
    assert func.entry is not None
    cfg = abc_cfg.compute_cfg_from_all_succs(
        all_succs, NodeName(str(func.entry)))
    loops = abc_cfg.compute_loops(
        safe_nodes, cfg)

    metadata = convert_function_metadata(func)

    # fn without any variables obtained
    tmpfn: GhostlessFunction[ProgVarName, Any] = GhostlessFunction(cfg=cfg, variables=set(
        []), nodes=safe_nodes, loops=loops, signature=metadata, name=func.name)

    # Insert all variables here
    variables = get_function_variables(tmpfn, safe_nodes)
    variables.add(ExprVar(type_mem, ProgVarName('Mem')))
    variables.add(ExprVar(type_htd, ProgVarName('HTD')))
    variables.add(ExprVar(type_pms, ProgVarName('PMS')))
    variables.add(
        ExprVar(type_ghost, ProgVarName('GhostAssertions')))

    variables.update(metadata.returns)
    variables.update(metadata.parameters)

    for spec_gh_var in spec_ghosts:
        spec_var = mk_spec_ghost_var(spec_gh_var)
        variables.add(spec_var)

    return GhostlessFunction(cfg=cfg, variables=variables, nodes=safe_nodes, loops=loops, signature=metadata, name=func.name)
