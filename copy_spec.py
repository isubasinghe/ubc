from typing import Mapping
import source
import nip
from ghost_data_helpers import *


testghost = source.ExprVar(source.TypeBitVec(
    32), source.ProgVarName("test#ghost"))


functions_spec: Mapping[str, source.Ghost[source.ProgVarName | nip.GuardVarName]] = {
    "Kernel_C.process_rx_complete": source.Ghost(
        precondition=conjs((source.expr_true)),
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
