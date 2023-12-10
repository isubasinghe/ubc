from typing import Callable, Any
import source
import nip
from ghost_data_helpers import *

msg_info_ret = source.ExprVar(source.type_word64, source.CRetSpecialVar(
    'rv#space#ret__struct_seL4_MessageInfo_C#v.words_C.0'))


def htd_assigned() -> source.ExprVarT[nip.GuardVarName]:
    return g(source.ExprVar(source.type_bool, source.ProgVarName('HTD')))


def mem_assigned() -> source.ExprVarT[nip.GuardVarName]:
    return g(source.ExprVar(source.type_bool, source.ProgVarName('Mem')))


def pms_assigned() -> source.ExprVarT[nip.GuardVarName]:
    return g(source.ExprVar(source.type_bool, source.ProgVarName('PMS')))


def ghost_asserts_assigned() -> source.ExprVarT[nip.GuardVarName]:
    return g(source.ExprVar(source.type_bool, source.ProgVarName('GhostAssertions')))


def recv_postcondition(ret_var: source.ExprVarT[source.ProgVarName]) -> source.ExprT[source.ProgVarName]:
    mem = source.ExprVar(source.type_mem, source.ProgVarName('Mem'))
    gbadge: source.ExprT[source.ProgVarName] = source.ExprFunction(
        source.type_word64, source.FunctionName('gbadge@global-symbol'), [])
    gbadge_val = mem_acc(source.type_word64, gbadge, mem)
    return conjs(
        ule(gbadge_val, u64(63))
    )


functions_spec = {
    "tmp.monitor": source.Ghost(
        precondition=conjs(),
        postcondition=conjs(),
        loop_invariants={lh("3"): conjs(
            htd_assigned(),
            mem_assigned(),
            pms_assigned(),
            ghost_asserts_assigned(),
        )},
        loop_iterations={lh("3"): source.empty_loop_ghost},
    ),
    "tmp.seL4_Recv": source.Ghost(
        precondition=conjs(
        ),
        postcondition=recv_postcondition(msg_info_ret),
        loop_invariants={},
        loop_iterations={},
    ),
}
