from typing import Mapping
import source
import nip
from ghost_data_helpers import *
ring_handle_t = source.TypeStruct("Kernel_C.ring_handle_C")

testghost = source.ExprVar(source.TypeBitVec(
    32), source.ProgVarName("test#ghost"))


free_ring = source.ExprSymbol(source.type_word64, source.ProgVarName("rx_ring_cli"))
used_ring: source.ExprT[source.ProgVarName] = source.expr_plus(
    source.ExprSymbol(source.type_word64, source.ProgVarName("rx_ring_cli")), 
    source.ExprNum(source.type_word64, 8)
)

functions_spec: Mapping[str, source.Ghost[source.ProgVarName | nip.GuardVarName]] = {
    "Kernel_C.process_rx_complete": source.Ghost(

        precondition=conjs(
            source.expr_valid(arg(htdvar()), ring_handle_t, mem_acc_word(free_ring, arg(memvar()))),
            source.expr_valid(arg(htdvar()), ring_handle_t, mem_acc_word(used_ring, arg(memvar())))
            ),
        postcondition=conjs(source.expr_true),
        loop_invariants={
            lh('38'): conjs(
                g(ret_32v()),
                g(ulonglong('enqueued')),
                mem_assigned(),
                htd_assigned(),
                pms_assigned(),
                ghost_asserts_assigned(),
                g(testghost)  # remove this
            ),
            lh('16'): conjs(
                g(ulonglong('enqueued')),
                mem_assigned(),
                htd_assigned(),
                pms_assigned(),
                ghost_asserts_assigned(),
                g(testghost)  # remove this
            )
        },
        loop_iterations={
            lh('38'): source.LoopIterationGhost(source.expr_true, source.expr_true),
            lh('16'): source.LoopIterationGhost(source.expr_true, source.expr_true)
        },
    )
}
