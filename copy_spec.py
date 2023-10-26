from typing import Mapping
import source
import nip
from ghost_data_helpers import *

ring_handle_t = source.TypeStruct("Kernel_C.ring_handle_C")
ring_buffer_t = source.TypeStruct("Kernel_C.ring_buffer_C")

m_addr = source.ExprSymbol(source.type_word64, source.ProgVarName("m_addr"))
m_len = source.ExprSymbol(source.type_word64, source.ProgVarName("m_len"))
c_addr = source.ExprSymbol(source.type_word64, source.ProgVarName("c_addr"))
c_len = source.ExprSymbol(source.type_word64, source.ProgVarName("c_len"))
cookie = source.ExprSymbol(source.type_word64, source.ProgVarName("cookie"))


testghost = source.ExprVar(source.TypeBitVec(
    32), source.ProgVarName("test#ghost"))


cli = source.ExprSymbol(source.type_word64, source.ProgVarName("rx_ring_cli"))
cli_free_ring = cli
cli_used_ring: source.ExprT[source.ProgVarName] = source.expr_plus(
    cli,
    source.ExprNum(source.type_word64, 8)
)

mux_free_ring = source.ExprSymbol(source.type_word64, source.ProgVarName("rx_ring_mux"))
mux_used_ring: source.ExprT[source.ProgVarName] = source.expr_plus(
    source.ExprSymbol(source.type_word64, source.ProgVarName("rx_ring_mux")), 
    source.ExprNum(source.type_word64, 8)
)

valid_cli = source.expr_valid(htdvar(), ring_handle_t, cli)
valid_cli_free_ring = source.expr_valid(htdvar(), ring_buffer_t, mem_acc_word(cli_free_ring, memvar()))
valid_cli_used_ring = source.expr_valid(htdvar(), ring_buffer_t, mem_acc_word(cli_used_ring, memvar()))


valid_mux_free_ring = source.expr_valid(htdvar(), ring_buffer_t, mem_acc_word(mux_free_ring, memvar()))
valid_mux_used_ring = source.expr_valid(htdvar(), ring_buffer_t, mem_acc_word(mux_used_ring, memvar()))


valid_m_addr = source.expr_valid(htdvar(), source.type_word64, m_addr)
valid_m_len = source.expr_valid(htdvar(), source.type_word32, m_len)
valid_c_addr = source.expr_valid(htdvar(), source.type_word64, c_addr)
valid_c_len = source.expr_valid(htdvar(), source.type_word32, c_len)

functions_spec: Mapping[str, source.Ghost[source.ProgVarName | nip.GuardVarName]] = {
    "Kernel_C.process_rx_complete": source.Ghost(

        precondition=conjs(
            source.expr_valid(arg(htdvar()), ring_handle_t, mem_acc_word(cli_free_ring, arg(memvar()))),
            source.expr_valid(arg(htdvar()), ring_handle_t, mem_acc_word(cli_used_ring, arg(memvar())))
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
                g(testghost),  # remove this
                valid_cli_free_ring,
                valid_cli_used_ring,
                valid_m_addr,
                valid_m_len,
                valid_c_addr,
                valid_c_len
            ),
            lh('16'): conjs(
                g(ulonglong('enqueued')),
                mem_assigned(),
                htd_assigned(),
                pms_assigned(),
                ghost_asserts_assigned(),
                g(testghost),  # remove this
                valid_cli_free_ring,
                valid_cli_used_ring,
                valid_m_addr,
                valid_m_len,
                valid_c_addr,
                valid_c_len
            )
        },
        loop_iterations={
            lh('38'): source.LoopIterationGhost(source.expr_true, source.expr_true),
            lh('16'): source.LoopIterationGhost(source.expr_true, source.expr_true)
        },
    ),
    "Kernel_C.dequeue_used": source.Ghost(
        precondition=conjs(   
        ),
        postcondition=conjs(
            valid_cli_free_ring,
            valid_cli_used_ring,
            valid_m_addr,
            valid_m_len,
            valid_c_addr,
            valid_c_len
        ),
        loop_invariants={},
        loop_iterations={}
    ),
    "Kernel_C.dequeue_free": source.Ghost(
        precondition=conjs(
        ),
        postcondition=conjs( 
            valid_cli_free_ring,
            valid_cli_used_ring,
            valid_m_addr,
            valid_m_len,
            valid_c_addr,
            valid_c_len
        ),
        loop_iterations={},
        loop_invariants={}
    ),

    "Kernel_C.memcpy": source.Ghost(
        precondition=conjs(),
        postcondition=conjs(
            valid_cli_free_ring,
            valid_cli_used_ring,
            valid_m_addr,
            valid_m_len,
            valid_c_addr,
            valid_c_len
        ),
        loop_invariants={},
        loop_iterations={}
    ),
    "Kernel_C.enqueue_used": source.Ghost(
        precondition=conjs(),
        postcondition=conjs(
            valid_cli_free_ring,
            valid_cli_used_ring,
            valid_m_addr,
            valid_m_len,
            valid_c_addr,
            valid_c_len
        ),
        loop_iterations={},
        loop_invariants={}
    ),
    "Kernel_C.enqueue_free": source.Ghost(
        precondition=conjs(),
        postcondition=conjs(
            valid_cli_free_ring,
            valid_cli_used_ring,
            valid_m_addr,
            valid_m_len,
            valid_c_addr,
            valid_c_len
        ),
        loop_iterations={},
        loop_invariants={}
    )
}
