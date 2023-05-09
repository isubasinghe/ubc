import dsa
import assume_prove as ap
import copy
from typing import Iterable, NamedTuple, Tuple, TypeVar
from typing_extensions import assert_never
import source
import smt
from provenance import *
class DebugContext(NamedTuple):
    pass

# Fairly dumb way of error reporting, 
# but easier to ensure correctness. 
def next_func(func: dsa.Function) -> Iterable[Tuple[dsa.Function, source.NodeName, dsa.Node]]:
    func = copy.deepcopy(func)
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
    pass

class OverflowFailure(NamedTuple):
    pass

class UnderflowFailure(NamedTuple):
    pass 

class UnknownFailure(NamedTuple):
    pass

FailureReason = OverflowFailure | UnderflowFailure | UnknownFailure

def determine_reason(node: dsa.Node) -> FailureReason:
    return UnknownFailure()

def print_reason(reason: FailureReason) -> None:
    pass

def extract_and_print_why(func: dsa.Function, reason: FailureReason, node: dsa.Node) -> None:
    pass

def debug_func(func: dsa.Function) -> None:
    for (new_func, node_name, node) in next_func(func):
        prog = ap.make_prog(new_func)
        smtlib = smt.make_smtlib(prog)
        sats = tuple(smt.send_smtlib_to_z3(smtlib))
        result = smt.parse_sats(sats)
        if result is smt.VerificationResult.OK:
            print(sats[1])
            print(result)
            print("Verification failed at node", node_name)
            print(node)
            reason = determine_reason(node)
            print_reason(reason)
            extract_and_print_why(func, reason, node) 
            break
