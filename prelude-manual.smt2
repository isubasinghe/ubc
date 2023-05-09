(define-fun HLIPre ((c PlatformContext) (newc (PlatformContext))) Bool 
  (and 
    (= (lc_unhandled_reply c) (lc_unhandled_reply newc))
    (= (lc_unhandled_notified newc) Ch_set_empty)
    (= (lc_unhandled_ppcall newc) Prod_Ch_MsgInfo_Nothing)
    (not (= (lc_receive_oracle newc) Unknown))
    (not (= (lc_receive_oracle newc) (Notification Ch_set_empty) ))
    (= (lc_receive_oracle newc) (lc_receive_oracle c))
  )
)
(check-sat)

