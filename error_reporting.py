import dsa
import assume_prove as ap
import copy
from typing import Iterable, NamedTuple, Tuple, TypeVar
from typing_extensions import assert_never
import source
import smt
from provenance import *
import nip
class DebugContext(NamedTuple):
    pass

# Fairly dumb way of error reporting, 
# but easier to ensure correctness. 
# TODO: Maybe bisecting through this is possible?
def next_func(func: dsa.Function) -> Iterable[Tuple[dsa.Function, source.NodeName, dsa.Node]]:
    replace_nodes: dict[source.NodeName, dsa.Node] = {}
    for (k,v) in func.nodes.items():
        replace_nodes[k] = v
    for node_name in func.traverse_topologically():
        node = func.nodes[node_name]
        if isinstance(node, source.NodeAssert):
            replace_nodes[node_name] = source.NodeAssert(expr=source.expr_true, succ=node.succ, origin=node.origin)
            yield dsa.Function(name=func.name, cfg=func.cfg, 
                            nodes=replace_nodes, loops=func.loops, 
                            signature=func.signature, ghost=func.ghost, contexts=func.contexts), node_name, func.nodes[node_name]
        elif isinstance(node, source.NodeCond) and node.succ_else == source.NodeNameErr:
            replace_nodes[node_name] = source.NodeCond(expr=source.expr_true, succ_then=node.succ_then, succ_else=node.succ_else, origin=node.origin)
            yield dsa.Function(name=func.name, cfg=func.cfg, 
                            nodes=replace_nodes, loops=func.loops, 
                            signature=func.signature, ghost=func.ghost, contexts=func.contexts), node_name, func.nodes[node_name]
    

T = TypeVar('T')
def pretty_print(e: source.ExprT[T]) -> None:
    if isinstance(e, source.ExprOp):
        pass
    elif isinstance(e, source.ExprVar):
        pass
    elif isinstance(e, source.ExprNum):
        pass
    elif isinstance(e, source.ExprFunction):
        pass
    elif isinstance(e, source.ExprSymbol):
        assert False, "not to worry, this case isn't handled"
    elif isinstance(e, source.ExprType):
        assert False, "This shouldn't occur here"
    else:
        assert_never(e)

class OverflowFailure(NamedTuple):
    pass

class UnderflowFailure(NamedTuple):
    pass 

class UnknownFailure(NamedTuple):
    pass

class UnInitialised(NamedTuple):
    pass

class UnAlignedMemory(NamedTuple):
    pass

class InvalidMemory(NamedTuple):
    pass

FailureReason = OverflowFailure | UnderflowFailure | UnknownFailure | UnInitialised | UnAlignedMemory | InvalidMemory

def expr_all_adds(e: source.ExprT) -> bool:
    allowed_ops = {source.Operator.PLUS, source.Operator.TIMES, source.Operator.EQUALS, source.Operator.SIGNED_LESS, source.Operator.SIGNED_LESS_EQUALS, source.Operator.AND, source.Operator.OR}
    valid: bool = True
    def visitor(v: source.ExprT):
        if isinstance(v, source.ExprOp):
            if v.operator not in allowed_ops:
                print(v.operator)
                nonlocal valid
                valid = False
        elif isinstance(v, source.ExprNum):
            pass
        elif isinstance(v, source.ExprVar):
            pass
        else:
            pass
    source.visit_expr(e, visitor)
    return valid 

def expr_all_subtract(e: source.ExprT) -> bool:
    allowed_ops = {source.Operator.MINUS, source.Operator.DIVIDED_BY, source.Operator.EQUALS, source.Operator.SIGNED_LESS, source.Operator.SIGNED_LESS_EQUALS, source.Operator.AND, source.Operator.OR }
    valid: bool = True
    def visitor(v: source.ExprT):
        if isinstance(v, source.ExprOp):
            if v.operator not in allowed_ops:
                nonlocal valid
                valid = False
        elif isinstance(v, source.ExprNum):
            pass
        elif isinstance(v, source.ExprVar):
            pass
        else:
            pass
    source.visit_expr(e, visitor)
    return valid 

def expr_all_pointeralignops(e: source.ExprT) -> bool:
    return False

def determine_reason(node: dsa.Node) -> FailureReason:
    assert not isinstance(node, source.NodeBasic)
    assert not isinstance(node, source.NodeCall)
    if isinstance(node, source.NodeEmpty):
        return UnknownFailure()
    elif isinstance(node.origin, ProvenanceNipGuard):
        return UnInitialised()
    elif isinstance(node.origin, ProvenanceGraphLang):
        assert isinstance(node, source.NodeCond)
        if expr_all_adds(node.expr):
            return OverflowFailure()
        elif expr_all_subtract(node.expr):
            return UnderflowFailure()
        elif expr_all_pointeralignops(node.expr):
            return UnAlignedMemory()
    return UnknownFailure()

def print_reason(reason: FailureReason) -> None:
    if isinstance(reason, UnInitialised):
        print("uninitialised variable")
    elif isinstance(reason, UnknownFailure):
        print("unable to determine failure reason")
    elif isinstance(reason, UnderflowFailure):
        print("variable underflows")
    elif isinstance(reason, OverflowFailure):
        print("variable overflows")
    elif isinstance(reason, UnAlignedMemory):
        print("unaligned memory")
    elif isinstance(reason, InvalidMemory):
        print("invalid memory")
    else:
        assert_never(reason)

def human_var_nip(src: source.ExprVarT[dsa.Incarnation[source.ProgVarName | nip.GuardVarName]]) -> str:
    varname = str(src.name.base)
    splitvarname = varname.split('#v#assigned')
    assert len(splitvarname) == 2, "This is not supposed to happen, there is a bug in the error reporting python code"
    human_varname = splitvarname[0].split('___')
    assert len(human_varname) == 2, "This is not supposed to happen"
    return human_varname[0]


def human_var(src: source.ExprVarT[dsa.Incarnation[source.ProgVarName | nip.GuardVarName]]) -> str:
    varname = str(src.name.base)
    human_varname = varname.split('___')
    assert len(human_varname) == 2, "This is not supposed to happen"
    return human_varname[0]

def extract_and_print_why(func: dsa.Function, reason: FailureReason, node: dsa.Node) -> None:
    if isinstance(reason, UnInitialised):
        variables = list(map(human_var_nip, source.used_variables_in_node(node)))
        assert len(variables) > 0, "Makes no sense for no variables to be uninitialised and still have the reason as uninitialised"
        if len(variables) == 1:
            print(variables[0], "was uninitialised")
            return
        print("one of", variables, "was uninitialised")
    elif isinstance(reason, OverflowFailure):
        assert isinstance(node, source.NodeCond)
        variables = list(map(human_var, source.used_variables_in_node(node)))
        if len(variables) == 0:
            pass 
        elif len(variables) == 1:
            print(f"variable {variables[0]} is involved in an overflow")
        else:
            succ_node_name = node.succ_then
            succ_node = func.nodes[succ_node_name]
            # a guard is always followed: 
            assert isinstance(succ_node, nip.NodeGuard)
            succ_succ_node_name = succ_node.succ_then
            succ_succ_node = func.nodes[succ_succ_node_name]
            assert isinstance(succ_succ_node, source.NodeBasic)
            print(f"one or more of variables", variables, f"leads to an overflow from some interleaving of arithmetic operation(s), refer to GraphLang at node {succ_succ_node_name}")
    elif isinstance(reason, UnderflowFailure):
        pass
    elif isinstance(reason, UnknownFailure):
        pass
    elif isinstance(reason, InvalidMemory):
        pass
    elif isinstance(reason, UnAlignedMemory):
        pass
    else:
        assert_never(reason)

def debug_func(func: dsa.Function) -> None:
    for (new_func, node_name, node) in next_func(func):
        prog = ap.make_prog(new_func)
        smtlib = smt.make_smtlib(prog)
        sats = tuple(smt.send_smtlib(smtlib, smt.SolverType.CVC5))
        result = smt.parse_sats(sats)
        if result is smt.VerificationResult.OK:
            print("Verification failed at node", node_name)
            reason = determine_reason(node)
            print_reason(reason)
            extract_and_print_why(func, reason, node) 
            break


# To enter this (assert prog.entry) results in SAT
def debug_func_smt(func: dsa.Function) -> None:
    prog = ap.make_prog(func)
    for node_name in func.traverse_topologically():
        print('*' * 80)
        print(f"(assert {node_name})")
        smtlib = smt.make_smtlib(prog, ap.node_ok_name(node_name))
        sats = tuple(smt.send_smtlib(smtlib, smt.SolverType.CVC5))
        result = smt.parse_sats(sats)
        print(result)
        
        # if node_name == source.NodeNameErr or node_name == prog.entry:
        #     continue
        # print(f"(assert {node_name})")
        # smtlib = smt.make_smtlib(prog, ap.node_ok_name(node_name))
        # sats = tuple(smt.send_smtlib(smtlib, smt.SolverType.CVC5))
        # result = smt.parse_sats(sats)
        # if result == smt.VerificationResult.OK:
        #     print(f"Verification failed at {prev_node_name}")
        #     assert prev_node_name is not None
        #     prev_node = func.nodes[prev_node_name]
        #     reason = determine_reason(prev_node)
        #     print_reason(reason)
        #     extract_and_print_why(func, reason, prev_node)
        #     break
        # prev_node_name = node_name

