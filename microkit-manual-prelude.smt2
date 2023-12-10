(declare-fun have_signal@global-symbol () (_ BitVec 64))
(declare-fun passive@global-symbol () (_ BitVec 64))
(declare-fun gbadge@global-symbol () (_ BitVec 64))
(declare-fun signal@global-symbol () (_ BitVec 64))
(declare-fun signal_msg@global-symbol () (_ BitVec 64))

(declare-fun handler_loop_pre_unhandled_reply () Maybe_MsgInfo)
(declare-fun handler_loop_pre_receive_oracle () NextRecv)

(declare-fun recv_oracle_kernel () Prod_MsgInfo_SeL4_Ntfn)
