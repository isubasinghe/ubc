typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef unsigned int wchar_t;

typedef signed char __int8_t;

typedef unsigned char __uint8_t;
typedef short int __int16_t;

typedef short unsigned int __uint16_t;
typedef int __int32_t;

typedef unsigned int __uint32_t;
typedef long int __int64_t;

typedef long unsigned int __uint64_t;
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
typedef int __int_least32_t;

typedef unsigned int __uint_least32_t;
typedef long int __int_least64_t;

typedef long unsigned int __uint_least64_t;
typedef long int __intmax_t;

typedef long unsigned int __uintmax_t;

typedef long int __intptr_t;

typedef long unsigned int __uintptr_t;

typedef __int8_t int8_t;

typedef __uint8_t uint8_t;

typedef __int16_t int16_t;

typedef __uint16_t uint16_t;

typedef __int32_t int32_t;

typedef __uint32_t uint32_t;

typedef __int64_t int64_t;

typedef __uint64_t uint64_t;

typedef __intmax_t intmax_t;

typedef __uintmax_t uintmax_t;

typedef __intptr_t intptr_t;

typedef __uintptr_t uintptr_t;

typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;

typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;

typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;

typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
typedef int int_fast8_t;
typedef unsigned int uint_fast8_t;
typedef int int_fast16_t;
typedef unsigned int uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
typedef long int int_fast64_t;
typedef long unsigned int uint_fast64_t;

typedef signed char seL4_Int8;
typedef unsigned char seL4_Uint8;


typedef signed short int seL4_Int16;
typedef unsigned short int seL4_Uint16;


typedef signed int seL4_Int32;
typedef unsigned int seL4_Uint32;

typedef signed long int seL4_Int64;
typedef unsigned long int seL4_Uint64;
typedef seL4_Int8 seL4_Bool;
typedef seL4_Uint64 seL4_Word;
typedef seL4_Word seL4_CPtr;

typedef seL4_CPtr seL4_ARM_Page;
typedef seL4_CPtr seL4_ARM_PageTable;
typedef seL4_CPtr seL4_ARM_PageDirectory;
typedef seL4_CPtr seL4_ARM_ASIDControl;
typedef seL4_CPtr seL4_ARM_ASIDPool;
typedef seL4_CPtr seL4_ARM_VCPU;
typedef seL4_CPtr seL4_ARM_IOSpace;
typedef seL4_CPtr seL4_ARM_IOPageTable;
typedef seL4_CPtr seL4_ARM_SIDControl;
typedef seL4_CPtr seL4_ARM_SID;
typedef seL4_CPtr seL4_ARM_CBControl;
typedef seL4_CPtr seL4_ARM_CB;

void zassert_fail(const char *str, const char *file, int line,
                  const char *function);


typedef enum api_object {
  seL4_UntypedObject,
  seL4_TCBObject,
  seL4_EndpointObject,
  seL4_NotificationObject,
  seL4_CapTableObject,

  seL4_SchedContextObject,
  seL4_ReplyObject,

  seL4_NonArchObjectTypeCount,
} seL4_ObjectType;

static const seL4_ObjectType seL4_AsyncEndpointObject = seL4_NotificationObject;

typedef seL4_Word api_object_t;


typedef seL4_Word object_t;


typedef enum {
  seL4_SchedContext_NoFlag = 0x0,
  seL4_SchedContext_Sporadic = 0x1,
  _enum_pad_seL4_SchedContextFlag = ((1ULL << ((sizeof(long) * 8) - 1)) - 1),
} seL4_SchedContextFlag;

struct seL4_CapRights {
  seL4_Uint64 words[1];
};
typedef struct seL4_CapRights seL4_CapRights_t;

struct seL4_MessageInfo {
  seL4_Uint64 words[1];
};
typedef struct seL4_MessageInfo seL4_MessageInfo_t;

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_new(seL4_Uint64 label, seL4_Uint64 capsUnwrapped,
                     seL4_Uint64 extraCaps, seL4_Uint64 length) {
  seL4_MessageInfo_t seL4_MessageInfo;

  do {
    if (!((label & ~0xfffffffffffffull) ==
          ((0 && (label & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);
  do {
    if (!((capsUnwrapped & ~0x7ull) ==
          ((0 && (capsUnwrapped & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);
  do {
    if (!((extraCaps & ~0x3ull) ==
          ((0 && (extraCaps & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);
  do {
    if (!((length & ~0x7full) == ((0 && (length & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);

  seL4_MessageInfo.words[0] =
      0 | (label & 0xfffffffffffffull) << 12 | (capsUnwrapped & 0x7ull) << 9 |
      (extraCaps & 0x3ull) << 7 | (length & 0x7full) << 0;

  return seL4_MessageInfo;
}

static inline void
seL4_MessageInfo_ptr_new(seL4_MessageInfo_t *seL4_MessageInfo_ptr,
                         seL4_Uint64 label, seL4_Uint64 capsUnwrapped,
                         seL4_Uint64 extraCaps, seL4_Uint64 length) {

  do {
    if (!((label & ~0xfffffffffffffull) ==
          ((0 && (label & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);
  do {
    if (!((capsUnwrapped & ~0x7ull) ==
          ((0 && (capsUnwrapped & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);
  do {
    if (!((extraCaps & ~0x3ull) ==
          ((0 && (extraCaps & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);
  do {
    if (!((length & ~0x7full) == ((0 && (length & (1ull << 63))) ? 0x0 : 0))) {
    }
  } while (0);

  seL4_MessageInfo_ptr->words[0] =
      0 | (label & 0xfffffffffffffull) << 12 | (capsUnwrapped & 0x7ull) << 9 |
      (extraCaps & 0x3ull) << 7 | (length & 0x7full) << 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_MessageInfo_get_label(seL4_MessageInfo_t seL4_MessageInfo) {
  seL4_Uint64 ret;
  ret = (seL4_MessageInfo.words[0] & 0xfffffffffffff000ull) >> 12;

  if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
    ret |= 0x0;
  }
  return ret;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_set_label(seL4_MessageInfo_t seL4_MessageInfo,
                           seL4_Uint64 v64) {

  do {
    if (!((((~0xfffffffffffff000ull >> 12) | 0x0) & v64) ==
          ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) {
    }
  } while (0);
  seL4_MessageInfo.words[0] &= ~0xfffffffffffff000ull;
  seL4_MessageInfo.words[0] |= (v64 << 12) & 0xfffffffffffff000ull;
  return seL4_MessageInfo;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_MessageInfo_ptr_get_label(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
  seL4_Uint64 ret;
  ret = (seL4_MessageInfo_ptr->words[0] & 0xfffffffffffff000ull) >> 12;

  if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
    ret |= 0x0;
  }
  return ret;
}

static inline void
seL4_MessageInfo_ptr_set_label(seL4_MessageInfo_t *seL4_MessageInfo_ptr,
                               seL4_Uint64 v64) {

  do {
    if (!((((~0xfffffffffffff000ull >> 12) | 0x0) & v64) ==
          ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) {
    }
  } while (0);
  seL4_MessageInfo_ptr->words[0] &= ~0xfffffffffffff000ull;
  seL4_MessageInfo_ptr->words[0] |= (v64 << 12) & 0xfffffffffffff000;
}


static inline seL4_Uint64 __attribute__((__pure__))
seL4_MessageInfo_ptr_get_extraCaps(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
  seL4_Uint64 ret;
  ret = (seL4_MessageInfo_ptr->words[0] & 0x180ull) >> 7;

  if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
    ret |= 0x0;
  }
  return ret;
}

enum {
    seL4_MsgMaxLength = 120,
};

enum seL4_MsgLimits {
    seL4_MsgLengthBits = 7,
    seL4_MsgExtraCapBits = 2
};

typedef struct seL4_IPCBuffer_ {
  seL4_MessageInfo_t tag;
  seL4_Word msg[seL4_MsgMaxLength];
  seL4_Word userData;
  seL4_Word caps_or_badges[((1ul << (seL4_MsgExtraCapBits)) - 1)];
  seL4_CPtr receiveCNode;
  seL4_CPtr receiveIndex;
  seL4_Word receiveDepth;
} seL4_IPCBuffer __attribute__((__aligned__(sizeof(struct seL4_IPCBuffer_))));


typedef seL4_Word seL4_NodeId;
typedef seL4_Word seL4_PAddr;
typedef seL4_Word seL4_Domain;

typedef seL4_CPtr seL4_CNode;
typedef seL4_CPtr seL4_IRQHandler;
typedef seL4_CPtr seL4_IRQControl;
typedef seL4_CPtr seL4_TCB;
typedef seL4_CPtr seL4_Untyped;
typedef seL4_CPtr seL4_DomainSet;
typedef seL4_CPtr seL4_SchedContext;
typedef seL4_CPtr seL4_SchedControl;

typedef seL4_Uint64 seL4_Time;

extern seL4_IPCBuffer *zsel4_ipc_buffer;
static inline void seL4_SetIPCBuffer(seL4_IPCBuffer *ipc_buffer) {
  zsel4_ipc_buffer = ipc_buffer;
  return;
}

static inline seL4_IPCBuffer *seL4_GetIPCBuffer(void) {
  return zsel4_ipc_buffer;
}

static inline seL4_Word seL4_GetMR(int i) {
  return seL4_GetIPCBuffer()->msg[i];
}

static inline void seL4_SetMR(int i, seL4_Word mr) {
  seL4_GetIPCBuffer()->msg[i] = mr;
}

static inline seL4_MessageInfo_t seL4_Recv(seL4_CPtr src, seL4_Word *sender,
                                           seL4_CPtr reply)

{
  seL4_MessageInfo_t info;
  seL4_Word badge;
  seL4_Word msg0;
  seL4_Word msg1;
  seL4_Word msg2;
  seL4_Word msg3;

  /*arm_sys_recv(seL4_SysRecv, src, &badge, &info.words[0], &msg0, &msg1, &msg2,
   * &msg3, reply)*/

  seL4_SetMR(0, msg0);
  seL4_SetMR(1, msg1);
  seL4_SetMR(2, msg2);
  seL4_SetMR(3, msg3);

  if (sender) {
    *sender = badge;
  }
  return info;
}

static inline seL4_MessageInfo_t seL4_NBRecv(seL4_CPtr src, seL4_Word *sender,
                                             seL4_CPtr reply)

{
  seL4_MessageInfo_t info;
  seL4_Word badge;
  seL4_Word msg0;
  seL4_Word msg1;
  seL4_Word msg2;
  seL4_Word msg3;

  /*arm_sys_recv(seL4_SysNBRecv, src, &badge, &info.words[0], &msg0, &msg1,
   * &msg2, &msg3, reply)*/

  seL4_SetMR(0, msg0);
  seL4_SetMR(1, msg1);
  seL4_SetMR(2, msg2);
  seL4_SetMR(3, msg3);

  if (sender) {
    *sender = badge;
  }
  return info;
}

static inline seL4_MessageInfo_t seL4_Call(seL4_CPtr dest,
                                           seL4_MessageInfo_t msgInfo) {
  seL4_MessageInfo_t info;
  seL4_Word msg0 = seL4_GetMR(0);
  seL4_Word msg1 = seL4_GetMR(1);
  seL4_Word msg2 = seL4_GetMR(2);
  seL4_Word msg3 = seL4_GetMR(3);

  /*arm_sys_send_recv(seL4_SysCall, dest, &dest, msgInfo.words[0],
   * &info.words[0], &msg0, &msg1, &msg2, &msg3, 0)*/

  seL4_SetMR(0, msg0);
  seL4_SetMR(1, msg1);
  seL4_SetMR(2, msg2);
  seL4_SetMR(3, msg3);

  return info;
}

static inline seL4_MessageInfo_t
seL4_ReplyRecv(seL4_CPtr src, seL4_MessageInfo_t msgInfo, seL4_Word *sender,
               seL4_CPtr reply)

{
  seL4_MessageInfo_t info;
  seL4_Word badge;
  seL4_Word msg0;
  seL4_Word msg1;
  seL4_Word msg2;
  seL4_Word msg3;

  msg0 = seL4_GetMR(0);
  msg1 = seL4_GetMR(1);
  msg2 = seL4_GetMR(2);
  msg3 = seL4_GetMR(3);

  /*arm_sys_send_recv(seL4_SysReplyRecv, src, &badge, msgInfo.words[0],
     &info.words[0], &msg0, &msg1, &msg2, &msg3, reply)*/

  seL4_SetMR(0, msg0);
  seL4_SetMR(1, msg1);
  seL4_SetMR(2, msg2);
  seL4_SetMR(3, msg3);

  if (sender) {
    *sender = badge;
  }

  return info;
}

static inline seL4_MessageInfo_t
seL4_NBSendRecv(seL4_CPtr dest, seL4_MessageInfo_t msgInfo, seL4_CPtr src,
                seL4_Word *sender, seL4_CPtr reply) {
  seL4_MessageInfo_t info;
  seL4_Word badge;
  seL4_Word msg0;
  seL4_Word msg1;
  seL4_Word msg2;
  seL4_Word msg3;

  msg0 = seL4_GetMR(0);
  msg1 = seL4_GetMR(1);
  msg2 = seL4_GetMR(2);
  msg3 = seL4_GetMR(3);

  /*arm_sys_nbsend_recv(seL4_SysNBSendRecv, dest, src, &badge, msgInfo.words[0],
     &info.words[0], &msg0, &msg1, &msg2, &msg3, reply)*/

  seL4_SetMR(0, msg0);
  seL4_SetMR(1, msg1);
  seL4_SetMR(2, msg2);
  seL4_SetMR(3, msg3);

  if (sender) {
    *sender = badge;
  }

  return info;
}




typedef unsigned int microkit_channel;
typedef seL4_MessageInfo_t microkit_msginfo;
void init(void);
void notified(microkit_channel ch);
microkit_msginfo protected(microkit_channel ch, microkit_msginfo msginfo);

extern char microkit_name[16];

extern char have_signal;
extern seL4_CPtr signal;
extern seL4_MessageInfo_t signal_msg;

void microkit_dbg_putc(int c);

void microkit_dbg_puts(const char *s);

void seL4_Signal(seL4_CPtr ch) {
  char *x = (void *)0;
  *x = 'a';
}

void seL4_IRQHandler_Ack(seL4_IRQHandler _service) {
  char *x = (void *)0;
  *x = 'a';
}

void microkit_notify(microkit_channel ch) {
  seL4_Signal(10 + ch);
}

void microkit_irq_ack(microkit_channel ch) {
  seL4_IRQHandler_Ack(138 + ch);
}

static inline microkit_msginfo microkit_ppcall(microkit_channel ch,
                                               microkit_msginfo msginfo) {
  return seL4_Call(74 + ch, msginfo);
}

static inline microkit_msginfo microkit_msginfo_new(uint64_t label,
                                                    uint16_t count) {
  return seL4_MessageInfo_new(label, 0, 0, count);
}

static inline uint64_t microkit_msginfo_get_label(microkit_msginfo msginfo) {
  return seL4_MessageInfo_get_label(msginfo);
}

static void microkit_mr_set(uint8_t mr, uint64_t value) {
  seL4_SetMR(mr, value);
}

static uint64_t microkit_mr_get(uint8_t mr) { return seL4_GetMR(mr); }

char zstack[4096] __attribute__((__aligned__(16)));

char passive;
char microkit_name[16];

char have_signal = 0;
seL4_CPtr signal;
seL4_MessageInfo_t signal_msg;

extern seL4_IPCBuffer zsel4_ipc_buffer_obj;

seL4_IPCBuffer *zsel4_ipc_buffer = &zsel4_ipc_buffer_obj;

extern const void (**const zinit_array_start)(void);
extern const void (**const zinit_array_end)(void);

__attribute__((weak))
microkit_msginfo protected(microkit_channel ch, microkit_msginfo msginfo) {
  return seL4_MessageInfo_new(0, 0, 0, 0);
}

static void run_init_funcs(void) { return; }

seL4_Word gbadge;

static void handler_loop(void) {

  char have_reply = 0;
  seL4_MessageInfo_t reply_tag;

  for (;;) {
    seL4_Word badge;
    seL4_MessageInfo_t tag;

    if (have_reply) {
      tag = seL4_ReplyRecv(1, reply_tag, &gbadge, 4);
      badge = gbadge;
    } else if (have_signal) {
      tag = seL4_NBSendRecv(signal, signal_msg, 1, &gbadge, 4);
      badge = gbadge;
    } else {
      tag = seL4_Recv(1, &gbadge, 4);
      badge = gbadge;
    }

    uint64_t is_endpoint = badge >> 63;

    if (is_endpoint) {
      have_reply = 1;
      reply_tag = protected(badge & 0x3f, tag);
    } else {
      unsigned int idx = 0;
      have_reply = 0;
      do {
        if (badge & 1) {
          notified(idx);
        }
        badge >>= 1;
        idx++;
      } while (badge != 0);
    }
  }
}

void main(void) {
  run_init_funcs();
  init();

  if (passive) {
    have_signal = 1;
    signal_msg = seL4_MessageInfo_new(0, 0, 0, 1);
    seL4_SetMR(0, 0);
    signal = (5);
  }

  handler_loop();
}
