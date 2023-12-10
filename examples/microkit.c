char STRINGLITERAL[1];

typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef unsigned int wchar_t;

typedef signed char int8_t;


typedef short int int16_t;


typedef int int32_t;


typedef long int int64_t;


typedef unsigned char uint8_t;


typedef short unsigned int uint16_t;


typedef unsigned int uint32_t;


typedef long unsigned int uint64_t;




typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef short unsigned int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef long unsigned int uint_least64_t;



typedef int int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef long unsigned int uint_fast64_t;




typedef long int intptr_t;


typedef long unsigned int uintptr_t;




typedef long int intmax_t;
typedef long unsigned int uintmax_t;








       






       


       


       

       






       







       






       







       

typedef signed char seL4_Int8;
typedef unsigned char seL4_Uint8;

//_Static_assert(sizeof(seL4_Int8) == 1, STRINGLITERAL);
//_Static_assert(sizeof(seL4_Uint8) == 1, STRINGLITERAL);







typedef signed short int seL4_Int16;
typedef unsigned short int seL4_Uint16;

//_Static_assert(sizeof(seL4_Int16) == 2, STRINGLITERAL);
//_Static_assert(sizeof(seL4_Uint16) == 2, STRINGLITERAL);






typedef signed int seL4_Int32;
typedef unsigned int seL4_Uint32;

//_Static_assert(sizeof(seL4_Int32) == 4, STRINGLITERAL);
//_Static_assert(sizeof(seL4_Uint32) == 4, STRINGLITERAL);
typedef signed long int seL4_Int64;
typedef unsigned long int seL4_Uint64;
typedef seL4_Int8 seL4_Bool;
typedef seL4_Uint64 seL4_Word;
typedef seL4_Word seL4_CPtr;








       






typedef enum {
    seL4_UnknownSyscall_X0,
    seL4_UnknownSyscall_X1,
    seL4_UnknownSyscall_X2,
    seL4_UnknownSyscall_X3,
    seL4_UnknownSyscall_X4,
    seL4_UnknownSyscall_X5,
    seL4_UnknownSyscall_X6,
    seL4_UnknownSyscall_X7,
    seL4_UnknownSyscall_FaultIP,
    seL4_UnknownSyscall_SP,
    seL4_UnknownSyscall_LR,
    seL4_UnknownSyscall_SPSR,
    seL4_UnknownSyscall_Syscall,

    seL4_UnknownSyscall_Length,
    _enum_pad_seL4_UnknownSyscall_Msg = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_UnknownSyscall_Msg;


typedef enum {
    seL4_UserException_FaultIP,
    seL4_UserException_SP,
    seL4_UserException_SPSR,
    seL4_UserException_Number,
    seL4_UserException_Code,

    seL4_UserException_Length,
    _enum_pad_seL4_UserException_Msg = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_UserException_Msg;


typedef enum {
    seL4_VMFault_IP,
    seL4_VMFault_Addr,
    seL4_VMFault_PrefetchFault,
    seL4_VMFault_FSR,
    seL4_VMFault_Length,
    _enum_pad_seL4_VMFault_Msg = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_VMFault_Msg;
typedef enum {
    seL4_TimeoutReply_FaultIP,
    seL4_TimeoutReply_SP,
    seL4_TimeoutReply_SPSR_EL1,
    seL4_TimeoutReply_X0,
    seL4_TimeoutReply_X1,
    seL4_TimeoutReply_X2,
    seL4_TimeoutReply_X3,
    seL4_TimeoutReply_X4,
    seL4_TimeoutReply_X5,
    seL4_TimeoutReply_X6,
    seL4_TimeoutReply_X7,
    seL4_TimeoutReply_X8,
    seL4_TimeoutReply_X16,
    seL4_TimeoutReply_X17,
    seL4_TimeoutReply_X18,
    seL4_TimeoutReply_X29,
    seL4_TimeoutReply_X30,
    seL4_TimeoutReply_X9,
    seL4_TimeoutReply_X10,
    seL4_TimeoutReply_X11,
    seL4_TimeoutReply_X12,
    seL4_TimeoutReply_X13,
    seL4_TimeoutReply_X14,
    seL4_TimeoutReply_X15,
    seL4_TimeoutReply_X19,
    seL4_TimeoutReply_X20,
    seL4_TimeoutReply_X21,
    seL4_TimeoutReply_X22,
    seL4_TimeoutReply_X23,
    seL4_TimeoutReply_X24,
    seL4_TimeoutReply_X25,
    seL4_TimeoutReply_X26,
    seL4_TimeoutReply_X27,
    seL4_TimeoutReply_X28,
    seL4_TimeoutReply_Length,
    _enum_pad_seL4_TimeoutReply_Msg = ((1ULL << ((sizeof(long)*8) - 1)) - 1)
} seL4_TimeoutReply_Msg;

typedef enum {
    seL4_Timeout_Data,
    seL4_Timeout_Consumed,
    seL4_Timeout_Length,
    _enum_pad_seL4_Timeout_Msg = ((1ULL << ((sizeof(long)*8) - 1)) - 1)
} seL4_TimeoutMsg;
//_Static_assert((3) + (9) == 12, STRINGLITERAL);;
//_Static_assert((3) + (9) == 12, STRINGLITERAL);;
//_Static_assert((3) + (9) == 12, STRINGLITERAL);;
//_Static_assert((3) + (9) == 12, STRINGLITERAL);;
//_Static_assert((3) + (9) == 12, STRINGLITERAL);;

//_Static_assert(sizeof(seL4_Word) == (1u << 3), STRINGLITERAL);



//_Static_assert(8 * sizeof(seL4_Word) == (sizeof(seL4_Word) * 8), STRINGLITERAL);







       









       



typedef seL4_CPtr seL4_ARM_PageUpperDirectory;
typedef seL4_CPtr seL4_ARM_PageGlobalDirectory;


typedef seL4_CPtr seL4_ARM_VSpace;

typedef struct seL4_UserContext_ {

    seL4_Word pc, sp, spsr, x0, x1, x2, x3, x4, x5, x6, x7, x8, x16, x17, x18, x29, x30;

    seL4_Word x9, x10, x11, x12, x13, x14, x15, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28;

    seL4_Word tpidr_el0, tpidrro_el0;
} seL4_UserContext;

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

typedef enum {
    seL4_ARM_PageCacheable = 0x01,
    seL4_ARM_ParityEnabled = 0x02,
    seL4_ARM_Default_VMAttributes = 0x03,
    seL4_ARM_ExecuteNever = 0x04,

    _enum_pad_seL4_ARM_VMAttributes = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_ARM_VMAttributes;

typedef enum {
    seL4_ARM_CacheI = 1,
    seL4_ARM_CacheD = 2,
    seL4_ARM_CacheID = 3,
    _enum_pad_seL4_ARM_CacheType = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_ARM_CacheType;






       
       



void zassert_fail(const char *str, const char *file, int line, const char *function);
struct seL4_Fault {
    seL4_Uint64 words[14];
};
typedef struct seL4_Fault seL4_Fault_t;

enum seL4_Fault_tag {
    seL4_Fault_NullFault = 0,
    seL4_Fault_CapFault = 1,
    seL4_Fault_UnknownSyscall = 2,
    seL4_Fault_UserException = 3,
    seL4_Fault_Timeout = 5,
    seL4_Fault_VMFault = 6
};
typedef enum seL4_Fault_tag seL4_Fault_tag_t;

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_get_seL4_FaultType(seL4_Fault_t seL4_Fault) {
    return (seL4_Fault.words[0] >> 0) & 0xfull;
}

static inline int __attribute__((__const__))
seL4_Fault_seL4_FaultType_equals(seL4_Fault_t seL4_Fault, seL4_Uint64 seL4_Fault_type_tag) {
    return ((seL4_Fault.words[0] >> 0) & 0xfull) == seL4_Fault_type_tag;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_ptr_get_seL4_FaultType(seL4_Fault_t *seL4_Fault_ptr) {
    return (seL4_Fault_ptr->words[0] >> 0) & 0xfull;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_NullFault_new(void) {
    seL4_Fault_t seL4_Fault;


    do { if (!(((seL4_Uint64)seL4_Fault_NullFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_NullFault & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 42, STRINGLITERAL); } } while(0);

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_NullFault & 0xfull) << 0;
    seL4_Fault.words[1] = 0;
    seL4_Fault.words[2] = 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;
    seL4_Fault.words[12] = 0;
    seL4_Fault.words[13] = 0;

    return seL4_Fault;
}

static inline void
seL4_Fault_NullFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr) {

    do { if (!(((seL4_Uint64)seL4_Fault_NullFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_NullFault & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 66, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_NullFault & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0;
    seL4_Fault_ptr->words[2] = 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
    seL4_Fault_ptr->words[12] = 0;
    seL4_Fault_ptr->words[13] = 0;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_new(seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 InRecvPhase, seL4_Uint64 LookupFailureType, seL4_Uint64 MR4, seL4_Uint64 MR5, seL4_Uint64 MR6) {
    seL4_Fault_t seL4_Fault;


    do { if (!(((seL4_Uint64)seL4_Fault_CapFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_CapFault & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 90, STRINGLITERAL); } } while(0);

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_CapFault & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | MR6 << 0;
    seL4_Fault.words[2] = 0
        | MR5 << 0;
    seL4_Fault.words[3] = 0
        | MR4 << 0;
    seL4_Fault.words[4] = 0
        | LookupFailureType << 0;
    seL4_Fault.words[5] = 0
        | InRecvPhase << 0;
    seL4_Fault.words[6] = 0
        | Addr << 0;
    seL4_Fault.words[7] = 0
        | IP << 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;
    seL4_Fault.words[12] = 0;
    seL4_Fault.words[13] = 0;

    return seL4_Fault;
}

static inline void
seL4_Fault_CapFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 InRecvPhase, seL4_Uint64 LookupFailureType, seL4_Uint64 MR4, seL4_Uint64 MR5, seL4_Uint64 MR6) {

    do { if (!(((seL4_Uint64)seL4_Fault_CapFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_CapFault & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 121, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_CapFault & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | MR6 << 0;
    seL4_Fault_ptr->words[2] = 0
        | MR5 << 0;
    seL4_Fault_ptr->words[3] = 0
        | MR4 << 0;
    seL4_Fault_ptr->words[4] = 0
        | LookupFailureType << 0;
    seL4_Fault_ptr->words[5] = 0
        | InRecvPhase << 0;
    seL4_Fault_ptr->words[6] = 0
        | Addr << 0;
    seL4_Fault_ptr->words[7] = 0
        | IP << 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
    seL4_Fault_ptr->words[12] = 0;
    seL4_Fault_ptr->words[13] = 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_CapFault_get_IP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 150, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault.words[7] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_set_IP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 163, STRINGLITERAL); } } while(0)
                               ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 166, STRINGLITERAL); } } while(0);

    seL4_Fault.words[7] &= ~0xffffffffffffffffull;
    seL4_Fault.words[7] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_CapFault_ptr_get_IP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 176, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault_ptr->words[7] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_CapFault_ptr_set_IP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 190, STRINGLITERAL); } } while(0)
                               ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 194, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[7] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[7] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_CapFault_get_Addr(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 203, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault.words[6] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_set_Addr(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 216, STRINGLITERAL); } } while(0)
                               ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 219, STRINGLITERAL); } } while(0);

    seL4_Fault.words[6] &= ~0xffffffffffffffffull;
    seL4_Fault.words[6] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_CapFault_ptr_get_Addr(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 229, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault_ptr->words[6] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_CapFault_ptr_set_Addr(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 243, STRINGLITERAL); } } while(0)
                               ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 247, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[6] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[6] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_CapFault_get_InRecvPhase(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 256, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault.words[5] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_set_InRecvPhase(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 269, STRINGLITERAL); } } while(0)
                               ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 272, STRINGLITERAL); } } while(0);

    seL4_Fault.words[5] &= ~0xffffffffffffffffull;
    seL4_Fault.words[5] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_CapFault_ptr_get_InRecvPhase(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 282, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault_ptr->words[5] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_CapFault_ptr_set_InRecvPhase(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 296, STRINGLITERAL); } } while(0)
                               ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 300, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[5] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[5] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_CapFault_get_LookupFailureType(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 309, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault.words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_set_LookupFailureType(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 322, STRINGLITERAL); } } while(0)
                               ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 325, STRINGLITERAL); } } while(0);

    seL4_Fault.words[4] &= ~0xffffffffffffffffull;
    seL4_Fault.words[4] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_CapFault_ptr_get_LookupFailureType(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 335, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault_ptr->words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_CapFault_ptr_set_LookupFailureType(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 349, STRINGLITERAL); } } while(0)
                               ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 353, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[4] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[4] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_CapFault_get_MR4(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 362, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_set_MR4(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 375, STRINGLITERAL); } } while(0)
                               ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 378, STRINGLITERAL); } } while(0);

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_CapFault_ptr_get_MR4(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 388, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_CapFault_ptr_set_MR4(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 402, STRINGLITERAL); } } while(0)
                               ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 406, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_CapFault_get_MR5(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 415, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_set_MR5(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 428, STRINGLITERAL); } } while(0)
                               ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 431, STRINGLITERAL); } } while(0);

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_CapFault_ptr_get_MR5(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 441, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_CapFault_ptr_set_MR5(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 455, STRINGLITERAL); } } while(0)
                               ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 459, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_CapFault_get_MR6(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 468, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_set_MR6(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 481, STRINGLITERAL); } } while(0)
                               ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 484, STRINGLITERAL); } } while(0);

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_CapFault_ptr_get_MR6(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 494, STRINGLITERAL); } } while(0)
                               ;

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_CapFault_ptr_set_MR6(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_CapFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 508, STRINGLITERAL); } } while(0)
                               ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 512, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_new(seL4_Uint64 X0, seL4_Uint64 X1, seL4_Uint64 X2, seL4_Uint64 X3, seL4_Uint64 X4, seL4_Uint64 X5, seL4_Uint64 X6, seL4_Uint64 X7, seL4_Uint64 FaultIP, seL4_Uint64 SP, seL4_Uint64 LR, seL4_Uint64 SPSR, seL4_Uint64 Syscall) {
    seL4_Fault_t seL4_Fault;


    do { if (!(((seL4_Uint64)seL4_Fault_UnknownSyscall & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UnknownSyscall & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 523, STRINGLITERAL); } } while(0);

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UnknownSyscall & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | Syscall << 0;
    seL4_Fault.words[2] = 0
        | SPSR << 0;
    seL4_Fault.words[3] = 0
        | LR << 0;
    seL4_Fault.words[4] = 0
        | SP << 0;
    seL4_Fault.words[5] = 0
        | FaultIP << 0;
    seL4_Fault.words[6] = 0
        | X7 << 0;
    seL4_Fault.words[7] = 0
        | X6 << 0;
    seL4_Fault.words[8] = 0
        | X5 << 0;
    seL4_Fault.words[9] = 0
        | X4 << 0;
    seL4_Fault.words[10] = 0
        | X3 << 0;
    seL4_Fault.words[11] = 0
        | X2 << 0;
    seL4_Fault.words[12] = 0
        | X1 << 0;
    seL4_Fault.words[13] = 0
        | X0 << 0;

    return seL4_Fault;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 X0, seL4_Uint64 X1, seL4_Uint64 X2, seL4_Uint64 X3, seL4_Uint64 X4, seL4_Uint64 X5, seL4_Uint64 X6, seL4_Uint64 X7, seL4_Uint64 FaultIP, seL4_Uint64 SP, seL4_Uint64 LR, seL4_Uint64 SPSR, seL4_Uint64 Syscall) {

    do { if (!(((seL4_Uint64)seL4_Fault_UnknownSyscall & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UnknownSyscall & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 560, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UnknownSyscall & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | Syscall << 0;
    seL4_Fault_ptr->words[2] = 0
        | SPSR << 0;
    seL4_Fault_ptr->words[3] = 0
        | LR << 0;
    seL4_Fault_ptr->words[4] = 0
        | SP << 0;
    seL4_Fault_ptr->words[5] = 0
        | FaultIP << 0;
    seL4_Fault_ptr->words[6] = 0
        | X7 << 0;
    seL4_Fault_ptr->words[7] = 0
        | X6 << 0;
    seL4_Fault_ptr->words[8] = 0
        | X5 << 0;
    seL4_Fault_ptr->words[9] = 0
        | X4 << 0;
    seL4_Fault_ptr->words[10] = 0
        | X3 << 0;
    seL4_Fault_ptr->words[11] = 0
        | X2 << 0;
    seL4_Fault_ptr->words[12] = 0
        | X1 << 0;
    seL4_Fault_ptr->words[13] = 0
        | X0 << 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X0(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 595, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[13] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X0(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 608, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 611, STRINGLITERAL); } } while(0);

    seL4_Fault.words[13] &= ~0xffffffffffffffffull;
    seL4_Fault.words[13] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X0(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 621, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[13] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X0(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 635, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 639, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[13] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[13] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X1(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 648, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[12] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X1(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 661, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 664, STRINGLITERAL); } } while(0);

    seL4_Fault.words[12] &= ~0xffffffffffffffffull;
    seL4_Fault.words[12] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X1(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 674, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[12] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X1(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 688, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 692, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[12] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[12] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X2(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 701, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[11] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X2(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 714, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 717, STRINGLITERAL); } } while(0);

    seL4_Fault.words[11] &= ~0xffffffffffffffffull;
    seL4_Fault.words[11] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X2(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 727, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[11] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X2(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 741, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 745, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[11] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[11] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X3(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 754, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[10] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X3(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 767, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 770, STRINGLITERAL); } } while(0);

    seL4_Fault.words[10] &= ~0xffffffffffffffffull;
    seL4_Fault.words[10] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X3(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 780, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[10] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X3(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 794, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 798, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[10] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[10] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X4(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 807, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[9] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X4(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 820, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 823, STRINGLITERAL); } } while(0);

    seL4_Fault.words[9] &= ~0xffffffffffffffffull;
    seL4_Fault.words[9] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X4(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 833, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[9] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X4(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 847, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 851, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[9] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[9] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X5(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 860, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[8] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X5(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 873, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 876, STRINGLITERAL); } } while(0);

    seL4_Fault.words[8] &= ~0xffffffffffffffffull;
    seL4_Fault.words[8] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X5(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 886, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[8] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X5(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 900, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 904, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[8] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[8] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X6(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 913, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[7] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X6(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 926, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 929, STRINGLITERAL); } } while(0);

    seL4_Fault.words[7] &= ~0xffffffffffffffffull;
    seL4_Fault.words[7] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X6(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 939, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[7] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X6(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 953, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 957, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[7] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[7] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_X7(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 966, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[6] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_X7(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 979, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 982, STRINGLITERAL); } } while(0);

    seL4_Fault.words[6] &= ~0xffffffffffffffffull;
    seL4_Fault.words[6] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_X7(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 992, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[6] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_X7(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1006, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1010, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[6] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[6] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_FaultIP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1019, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[5] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_FaultIP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1032, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1035, STRINGLITERAL); } } while(0);

    seL4_Fault.words[5] &= ~0xffffffffffffffffull;
    seL4_Fault.words[5] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_FaultIP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1045, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[5] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_FaultIP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1059, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1063, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[5] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[5] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_SP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1072, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_SP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1085, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1088, STRINGLITERAL); } } while(0);

    seL4_Fault.words[4] &= ~0xffffffffffffffffull;
    seL4_Fault.words[4] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_SP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1098, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_SP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1112, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1116, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[4] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[4] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_LR(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1125, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_LR(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1138, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1141, STRINGLITERAL); } } while(0);

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_LR(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1151, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_LR(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1165, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1169, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_SPSR(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1178, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_SPSR(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1191, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1194, STRINGLITERAL); } } while(0);

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_SPSR(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1204, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_SPSR(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1218, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1222, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_Syscall(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1231, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_set_Syscall(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1244, STRINGLITERAL); } } while(0)
                                     ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1247, STRINGLITERAL); } } while(0);

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UnknownSyscall_ptr_get_Syscall(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1257, STRINGLITERAL); } } while(0)
                                     ;

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UnknownSyscall_ptr_set_Syscall(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UnknownSyscall)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1271, STRINGLITERAL); } } while(0)
                                     ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1275, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UserException_new(seL4_Uint64 FaultIP, seL4_Uint64 Stack, seL4_Uint64 SPSR, seL4_Uint64 Number, seL4_Uint64 Code) {
    seL4_Fault_t seL4_Fault;


    do { if (!(((seL4_Uint64)seL4_Fault_UserException & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UserException & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1286, STRINGLITERAL); } } while(0);

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UserException & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | Code << 0;
    seL4_Fault.words[2] = 0
        | Number << 0;
    seL4_Fault.words[3] = 0
        | SPSR << 0;
    seL4_Fault.words[4] = 0
        | Stack << 0;
    seL4_Fault.words[5] = 0
        | FaultIP << 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;
    seL4_Fault.words[12] = 0;
    seL4_Fault.words[13] = 0;

    return seL4_Fault;
}

static inline void
seL4_Fault_UserException_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 FaultIP, seL4_Uint64 Stack, seL4_Uint64 SPSR, seL4_Uint64 Number, seL4_Uint64 Code) {

    do { if (!(((seL4_Uint64)seL4_Fault_UserException & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UserException & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1315, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UserException & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | Code << 0;
    seL4_Fault_ptr->words[2] = 0
        | Number << 0;
    seL4_Fault_ptr->words[3] = 0
        | SPSR << 0;
    seL4_Fault_ptr->words[4] = 0
        | Stack << 0;
    seL4_Fault_ptr->words[5] = 0
        | FaultIP << 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
    seL4_Fault_ptr->words[12] = 0;
    seL4_Fault_ptr->words[13] = 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UserException_get_FaultIP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1342, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault.words[5] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UserException_set_FaultIP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1355, STRINGLITERAL); } } while(0)
                                    ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1358, STRINGLITERAL); } } while(0);

    seL4_Fault.words[5] &= ~0xffffffffffffffffull;
    seL4_Fault.words[5] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UserException_ptr_get_FaultIP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1368, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault_ptr->words[5] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UserException_ptr_set_FaultIP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1382, STRINGLITERAL); } } while(0)
                                    ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1386, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[5] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[5] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UserException_get_Stack(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1395, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault.words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UserException_set_Stack(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1408, STRINGLITERAL); } } while(0)
                                    ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1411, STRINGLITERAL); } } while(0);

    seL4_Fault.words[4] &= ~0xffffffffffffffffull;
    seL4_Fault.words[4] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UserException_ptr_get_Stack(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1421, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault_ptr->words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UserException_ptr_set_Stack(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1435, STRINGLITERAL); } } while(0)
                                    ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1439, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[4] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[4] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UserException_get_SPSR(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1448, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UserException_set_SPSR(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1461, STRINGLITERAL); } } while(0)
                                    ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1464, STRINGLITERAL); } } while(0);

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UserException_ptr_get_SPSR(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1474, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UserException_ptr_set_SPSR(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1488, STRINGLITERAL); } } while(0)
                                    ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1492, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UserException_get_Number(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1501, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UserException_set_Number(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1514, STRINGLITERAL); } } while(0)
                                    ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1517, STRINGLITERAL); } } while(0);

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UserException_ptr_get_Number(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1527, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UserException_ptr_set_Number(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1541, STRINGLITERAL); } } while(0)
                                    ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1545, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_UserException_get_Code(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1554, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UserException_set_Code(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1567, STRINGLITERAL); } } while(0)
                                    ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1570, STRINGLITERAL); } } while(0);

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_UserException_ptr_get_Code(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1580, STRINGLITERAL); } } while(0)
                                    ;

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_UserException_ptr_set_Code(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_UserException)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1594, STRINGLITERAL); } } while(0)
                                    ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1598, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_Timeout_new(seL4_Uint64 data, seL4_Uint64 consumed) {
    seL4_Fault_t seL4_Fault;


    do { if (!(((seL4_Uint64)seL4_Fault_Timeout & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_Timeout & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1609, STRINGLITERAL); } } while(0);

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_Timeout & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | consumed << 0;
    seL4_Fault.words[2] = 0
        | data << 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;
    seL4_Fault.words[12] = 0;
    seL4_Fault.words[13] = 0;

    return seL4_Fault;
}

static inline void
seL4_Fault_Timeout_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 data, seL4_Uint64 consumed) {

    do { if (!(((seL4_Uint64)seL4_Fault_Timeout & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_Timeout & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1635, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_Timeout & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | consumed << 0;
    seL4_Fault_ptr->words[2] = 0
        | data << 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
    seL4_Fault_ptr->words[12] = 0;
    seL4_Fault_ptr->words[13] = 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_Timeout_get_data(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1659, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_Timeout_set_data(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1672, STRINGLITERAL); } } while(0)
                              ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1675, STRINGLITERAL); } } while(0);

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_Timeout_ptr_get_data(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1685, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_Timeout_ptr_set_data(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1699, STRINGLITERAL); } } while(0)
                              ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1703, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_Timeout_get_consumed(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1712, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_Timeout_set_consumed(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1725, STRINGLITERAL); } } while(0)
                              ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1728, STRINGLITERAL); } } while(0);

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_Timeout_ptr_get_consumed(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1738, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_Timeout_ptr_set_consumed(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_Timeout)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1752, STRINGLITERAL); } } while(0)
                              ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1756, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_VMFault_new(seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 PrefetchFault, seL4_Uint64 FSR) {
    seL4_Fault_t seL4_Fault;


    do { if (!(((seL4_Uint64)seL4_Fault_VMFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_VMFault & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1767, STRINGLITERAL); } } while(0);

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_VMFault & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | FSR << 0;
    seL4_Fault.words[2] = 0
        | PrefetchFault << 0;
    seL4_Fault.words[3] = 0
        | Addr << 0;
    seL4_Fault.words[4] = 0
        | IP << 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;
    seL4_Fault.words[12] = 0;
    seL4_Fault.words[13] = 0;

    return seL4_Fault;
}

static inline void
seL4_Fault_VMFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 PrefetchFault, seL4_Uint64 FSR) {

    do { if (!(((seL4_Uint64)seL4_Fault_VMFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_VMFault & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1795, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_VMFault & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | FSR << 0;
    seL4_Fault_ptr->words[2] = 0
        | PrefetchFault << 0;
    seL4_Fault_ptr->words[3] = 0
        | Addr << 0;
    seL4_Fault_ptr->words[4] = 0
        | IP << 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
    seL4_Fault_ptr->words[12] = 0;
    seL4_Fault_ptr->words[13] = 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_VMFault_get_IP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1821, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault.words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_VMFault_set_IP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1834, STRINGLITERAL); } } while(0)
                              ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1837, STRINGLITERAL); } } while(0);

    seL4_Fault.words[4] &= ~0xffffffffffffffffull;
    seL4_Fault.words[4] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_VMFault_ptr_get_IP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1847, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault_ptr->words[4] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_VMFault_ptr_set_IP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1861, STRINGLITERAL); } } while(0)
                              ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1865, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[4] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[4] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_VMFault_get_Addr(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1874, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_VMFault_set_Addr(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1887, STRINGLITERAL); } } while(0)
                              ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1890, STRINGLITERAL); } } while(0);

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_VMFault_ptr_get_Addr(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1900, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_VMFault_ptr_set_Addr(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1914, STRINGLITERAL); } } while(0)
                              ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1918, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_VMFault_get_PrefetchFault(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1927, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_VMFault_set_PrefetchFault(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1940, STRINGLITERAL); } } while(0)
                              ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1943, STRINGLITERAL); } } while(0);

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_VMFault_ptr_get_PrefetchFault(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1953, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_VMFault_ptr_set_PrefetchFault(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1967, STRINGLITERAL); } } while(0)
                              ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1971, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_Fault_VMFault_get_FSR(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1980, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_VMFault_set_FSR(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    do { if (!(((seL4_Fault.words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1993, STRINGLITERAL); } } while(0)
                              ;

    do { if (!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 1996, STRINGLITERAL); } } while(0);

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_Fault_VMFault_ptr_get_FSR(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 2006, STRINGLITERAL); } } while(0)
                              ;

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_Fault_VMFault_ptr_set_FSR(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    do { if (!(((seL4_Fault_ptr->words[0] >> 0) & 0xf) == seL4_Fault_VMFault)) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 2020, STRINGLITERAL); } } while(0)
                              ;


    do { if (!((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 2024, STRINGLITERAL); } } while(0);

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}
typedef enum {
    seL4_SysCall = -1,
    seL4_SysReplyRecv = -2,
    seL4_SysNBSendRecv = -3,
    seL4_SysNBSendWait = -4,
    seL4_SysSend = -5,
    seL4_SysNBSend = -6,
    seL4_SysRecv = -7,
    seL4_SysNBRecv = -8,
    seL4_SysWait = -9,
    seL4_SysNBWait = -10,
    seL4_SysYield = -11,
    _enum_pad_seL4_Syscall_ID = ((1ULL << ((sizeof(long)*8) - 1)) - 1)
} seL4_Syscall_ID;






       
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

 static const seL4_ObjectType seL4_AsyncEndpointObject =
    seL4_NotificationObject;

typedef seL4_Word api_object_t;






       

typedef enum _mode_object {
    seL4_ARM_HugePageObject = seL4_NonArchObjectTypeCount,
    seL4_ARM_PageUpperDirectoryObject,
    seL4_ARM_PageGlobalDirectoryObject,
    seL4_ModeObjectTypeCount
} seL4_ModeObjectType;






       



typedef enum _object {
    seL4_ARM_SmallPageObject = seL4_ModeObjectTypeCount,
    seL4_ARM_LargePageObject,




    seL4_ARM_PageTableObject,
    seL4_ARM_PageDirectoryObject,






    seL4_ObjectTypeCount
} seL4_ArchObjectType;

typedef seL4_Word object_t;






       

typedef enum {
    seL4_NoError = 0,
    seL4_InvalidArgument,
    seL4_InvalidCapability,
    seL4_IllegalOperation,
    seL4_RangeError,
    seL4_AlignmentError,
    seL4_FailedLookup,
    seL4_TruncatedMessage,
    seL4_DeleteFirst,
    seL4_RevokeFirst,
    seL4_NotEnoughMemory,





    seL4_NumErrors
} seL4_Error;






       
enum priorityConstants {
    seL4_InvalidPrio = -1,
    seL4_MinPrio = 0,
    seL4_MaxPrio = 256 - 1
};



enum seL4_MsgLimits {
    seL4_MsgLengthBits = 7,
    seL4_MsgExtraCapBits = 2
};

enum {
    seL4_MsgMaxLength = 120,
};





typedef enum {
    seL4_NoFailure = 0,
    seL4_InvalidRoot,
    seL4_MissingCapability,
    seL4_DepthMismatch,
    seL4_GuardMismatch,
    _enum_pad_seL4_LookupFailureType = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_LookupFailureType;
static inline seL4_Word seL4_MaxExtraRefills(seL4_Word size)
{
    return ((1ul<<(size)) - (10 * sizeof(seL4_Word) + (6 * 8))) / (2 * 8);
}


typedef enum {
    seL4_SchedContext_NoFlag = 0x0,
    seL4_SchedContext_Sporadic = 0x1,
    _enum_pad_seL4_SchedContextFlag = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_SchedContextFlag;






struct seL4_CNode_CapData {
    seL4_Uint64 words[1];
};
typedef struct seL4_CNode_CapData seL4_CNode_CapData_t;

static inline seL4_CNode_CapData_t __attribute__((__const__))
seL4_CNode_CapData_new(seL4_Uint64 guard, seL4_Uint64 guardSize) {
    seL4_CNode_CapData_t seL4_CNode_CapData;


    do { if (!((guard & ~0x3ffffffffffffffull) == ((0 && (guard & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 17, STRINGLITERAL); } } while(0);
    do { if (!((guardSize & ~0x3full) == ((0 && (guardSize & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 18, STRINGLITERAL); } } while(0);

    seL4_CNode_CapData.words[0] = 0
        | (guard & 0x3ffffffffffffffull) << 6
        | (guardSize & 0x3full) << 0;

    return seL4_CNode_CapData;
}

static inline void
seL4_CNode_CapData_ptr_new(seL4_CNode_CapData_t *seL4_CNode_CapData_ptr, seL4_Uint64 guard, seL4_Uint64 guardSize) {

    do { if (!((guard & ~0x3ffffffffffffffull) == ((0 && (guard & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 30, STRINGLITERAL); } } while(0);
    do { if (!((guardSize & ~0x3full) == ((0 && (guardSize & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 31, STRINGLITERAL); } } while(0);

    seL4_CNode_CapData_ptr->words[0] = 0
        | (guard & 0x3ffffffffffffffull) << 6
        | (guardSize & 0x3full) << 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_CNode_CapData_get_guard(seL4_CNode_CapData_t seL4_CNode_CapData) {
    seL4_Uint64 ret;
    ret = (seL4_CNode_CapData.words[0] & 0xffffffffffffffc0ull) >> 6;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_CNode_CapData_t __attribute__((__const__))
seL4_CNode_CapData_set_guard(seL4_CNode_CapData_t seL4_CNode_CapData, seL4_Uint64 v64) {

    do { if (!((((~0xffffffffffffffc0ull >> 6 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 52, STRINGLITERAL); } } while(0);
    seL4_CNode_CapData.words[0] &= ~0xffffffffffffffc0ull;
    seL4_CNode_CapData.words[0] |= (v64 << 6) & 0xffffffffffffffc0ull;
    return seL4_CNode_CapData;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_CNode_CapData_ptr_get_guard(seL4_CNode_CapData_t *seL4_CNode_CapData_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_CNode_CapData_ptr->words[0] & 0xffffffffffffffc0ull) >> 6;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_CNode_CapData_ptr_set_guard(seL4_CNode_CapData_t *seL4_CNode_CapData_ptr, seL4_Uint64 v64) {

    do { if (!((((~0xffffffffffffffc0ull >> 6) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 72, STRINGLITERAL); } } while(0);
    seL4_CNode_CapData_ptr->words[0] &= ~0xffffffffffffffc0ull;
    seL4_CNode_CapData_ptr->words[0] |= (v64 << 6) & 0xffffffffffffffc0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_CNode_CapData_get_guardSize(seL4_CNode_CapData_t seL4_CNode_CapData) {
    seL4_Uint64 ret;
    ret = (seL4_CNode_CapData.words[0] & 0x3full) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_CNode_CapData_t __attribute__((__const__))
seL4_CNode_CapData_set_guardSize(seL4_CNode_CapData_t seL4_CNode_CapData, seL4_Uint64 v64) {

    do { if (!((((~0x3full >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 91, STRINGLITERAL); } } while(0);
    seL4_CNode_CapData.words[0] &= ~0x3full;
    seL4_CNode_CapData.words[0] |= (v64 << 0) & 0x3full;
    return seL4_CNode_CapData;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_CNode_CapData_ptr_get_guardSize(seL4_CNode_CapData_t *seL4_CNode_CapData_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_CNode_CapData_ptr->words[0] & 0x3full) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_CNode_CapData_ptr_set_guardSize(seL4_CNode_CapData_t *seL4_CNode_CapData_ptr, seL4_Uint64 v64) {

    do { if (!((((~0x3full >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 111, STRINGLITERAL); } } while(0);
    seL4_CNode_CapData_ptr->words[0] &= ~0x3full;
    seL4_CNode_CapData_ptr->words[0] |= (v64 << 0) & 0x3f;
}

struct seL4_CapRights {
    seL4_Uint64 words[1];
};
typedef struct seL4_CapRights seL4_CapRights_t;

static inline seL4_CapRights_t __attribute__((__const__))
seL4_CapRights_new(seL4_Uint64 capAllowGrantReply, seL4_Uint64 capAllowGrant, seL4_Uint64 capAllowRead, seL4_Uint64 capAllowWrite) {
    seL4_CapRights_t seL4_CapRights;


    do { if (!((capAllowGrantReply & ~0x1ull) == ((0 && (capAllowGrantReply & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 126, STRINGLITERAL); } } while(0);
    do { if (!((capAllowGrant & ~0x1ull) == ((0 && (capAllowGrant & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 127, STRINGLITERAL); } } while(0);
    do { if (!((capAllowRead & ~0x1ull) == ((0 && (capAllowRead & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 128, STRINGLITERAL); } } while(0);
    do { if (!((capAllowWrite & ~0x1ull) == ((0 && (capAllowWrite & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 129, STRINGLITERAL); } } while(0);

    seL4_CapRights.words[0] = 0
        | (capAllowGrantReply & 0x1ull) << 3
        | (capAllowGrant & 0x1ull) << 2
        | (capAllowRead & 0x1ull) << 1
        | (capAllowWrite & 0x1ull) << 0;

    return seL4_CapRights;
}

static inline void
seL4_CapRights_ptr_new(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint64 capAllowGrantReply, seL4_Uint64 capAllowGrant, seL4_Uint64 capAllowRead, seL4_Uint64 capAllowWrite) {

    do { if (!((capAllowGrantReply & ~0x1ull) == ((0 && (capAllowGrantReply & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 143, STRINGLITERAL); } } while(0);
    do { if (!((capAllowGrant & ~0x1ull) == ((0 && (capAllowGrant & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 144, STRINGLITERAL); } } while(0);
    do { if (!((capAllowRead & ~0x1ull) == ((0 && (capAllowRead & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 145, STRINGLITERAL); } } while(0);
    do { if (!((capAllowWrite & ~0x1ull) == ((0 && (capAllowWrite & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 146, STRINGLITERAL); } } while(0);

    seL4_CapRights_ptr->words[0] = 0
        | (capAllowGrantReply & 0x1ull) << 3
        | (capAllowGrant & 0x1ull) << 2
        | (capAllowRead & 0x1ull) << 1
        | (capAllowWrite & 0x1ull) << 0;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_CapRights_get_capAllowGrantReply(seL4_CapRights_t seL4_CapRights) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights.words[0] & 0x8ull) >> 3;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_CapRights_t __attribute__((__const__))
seL4_CapRights_set_capAllowGrantReply(seL4_CapRights_t seL4_CapRights, seL4_Uint64 v64) {

    do { if (!((((~0x8ull >> 3 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 169, STRINGLITERAL); } } while(0);
    seL4_CapRights.words[0] &= ~0x8ull;
    seL4_CapRights.words[0] |= (v64 << 3) & 0x8ull;
    return seL4_CapRights;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_CapRights_ptr_get_capAllowGrantReply(seL4_CapRights_t *seL4_CapRights_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights_ptr->words[0] & 0x8ull) >> 3;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_CapRights_ptr_set_capAllowGrantReply(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint64 v64) {

    do { if (!((((~0x8ull >> 3) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 189, STRINGLITERAL); } } while(0);
    seL4_CapRights_ptr->words[0] &= ~0x8ull;
    seL4_CapRights_ptr->words[0] |= (v64 << 3) & 0x8;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_CapRights_get_capAllowGrant(seL4_CapRights_t seL4_CapRights) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights.words[0] & 0x4ull) >> 2;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_CapRights_t __attribute__((__const__))
seL4_CapRights_set_capAllowGrant(seL4_CapRights_t seL4_CapRights, seL4_Uint64 v64) {

    do { if (!((((~0x4ull >> 2 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 208, STRINGLITERAL); } } while(0);
    seL4_CapRights.words[0] &= ~0x4ull;
    seL4_CapRights.words[0] |= (v64 << 2) & 0x4ull;
    return seL4_CapRights;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_CapRights_ptr_get_capAllowGrant(seL4_CapRights_t *seL4_CapRights_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights_ptr->words[0] & 0x4ull) >> 2;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_CapRights_ptr_set_capAllowGrant(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint64 v64) {

    do { if (!((((~0x4ull >> 2) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 228, STRINGLITERAL); } } while(0);
    seL4_CapRights_ptr->words[0] &= ~0x4ull;
    seL4_CapRights_ptr->words[0] |= (v64 << 2) & 0x4;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_CapRights_get_capAllowRead(seL4_CapRights_t seL4_CapRights) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights.words[0] & 0x2ull) >> 1;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_CapRights_t __attribute__((__const__))
seL4_CapRights_set_capAllowRead(seL4_CapRights_t seL4_CapRights, seL4_Uint64 v64) {

    do { if (!((((~0x2ull >> 1 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 247, STRINGLITERAL); } } while(0);
    seL4_CapRights.words[0] &= ~0x2ull;
    seL4_CapRights.words[0] |= (v64 << 1) & 0x2ull;
    return seL4_CapRights;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_CapRights_ptr_get_capAllowRead(seL4_CapRights_t *seL4_CapRights_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights_ptr->words[0] & 0x2ull) >> 1;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_CapRights_ptr_set_capAllowRead(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint64 v64) {

    do { if (!((((~0x2ull >> 1) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 267, STRINGLITERAL); } } while(0);
    seL4_CapRights_ptr->words[0] &= ~0x2ull;
    seL4_CapRights_ptr->words[0] |= (v64 << 1) & 0x2;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_CapRights_get_capAllowWrite(seL4_CapRights_t seL4_CapRights) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights.words[0] & 0x1ull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_CapRights_t __attribute__((__const__))
seL4_CapRights_set_capAllowWrite(seL4_CapRights_t seL4_CapRights, seL4_Uint64 v64) {

    do { if (!((((~0x1ull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 286, STRINGLITERAL); } } while(0);
    seL4_CapRights.words[0] &= ~0x1ull;
    seL4_CapRights.words[0] |= (v64 << 0) & 0x1ull;
    return seL4_CapRights;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_CapRights_ptr_get_capAllowWrite(seL4_CapRights_t *seL4_CapRights_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_CapRights_ptr->words[0] & 0x1ull) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_CapRights_ptr_set_capAllowWrite(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint64 v64) {

    do { if (!((((~0x1ull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 306, STRINGLITERAL); } } while(0);
    seL4_CapRights_ptr->words[0] &= ~0x1ull;
    seL4_CapRights_ptr->words[0] |= (v64 << 0) & 0x1;
}

struct seL4_MessageInfo {
    seL4_Uint64 words[1];
};
typedef struct seL4_MessageInfo seL4_MessageInfo_t;

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_new(seL4_Uint64 label, seL4_Uint64 capsUnwrapped, seL4_Uint64 extraCaps, seL4_Uint64 length) {
    seL4_MessageInfo_t seL4_MessageInfo;


    do { if (!((label & ~0xfffffffffffffull) == ((0 && (label & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 321, STRINGLITERAL); } } while(0);
    do { if (!((capsUnwrapped & ~0x7ull) == ((0 && (capsUnwrapped & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 322, STRINGLITERAL); } } while(0);
    do { if (!((extraCaps & ~0x3ull) == ((0 && (extraCaps & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 323, STRINGLITERAL); } } while(0);
    do { if (!((length & ~0x7full) == ((0 && (length & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 324, STRINGLITERAL); } } while(0);

    seL4_MessageInfo.words[0] = 0
        | (label & 0xfffffffffffffull) << 12
        | (capsUnwrapped & 0x7ull) << 9
        | (extraCaps & 0x3ull) << 7
        | (length & 0x7full) << 0;

    return seL4_MessageInfo;
}

static inline void
seL4_MessageInfo_ptr_new(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint64 label, seL4_Uint64 capsUnwrapped, seL4_Uint64 extraCaps, seL4_Uint64 length) {

    do { if (!((label & ~0xfffffffffffffull) == ((0 && (label & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 338, STRINGLITERAL); } } while(0);
    do { if (!((capsUnwrapped & ~0x7ull) == ((0 && (capsUnwrapped & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 339, STRINGLITERAL); } } while(0);
    do { if (!((extraCaps & ~0x3ull) == ((0 && (extraCaps & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 340, STRINGLITERAL); } } while(0);
    do { if (!((length & ~0x7full) == ((0 && (length & (1ull << 63))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 341, STRINGLITERAL); } } while(0);

    seL4_MessageInfo_ptr->words[0] = 0
        | (label & 0xfffffffffffffull) << 12
        | (capsUnwrapped & 0x7ull) << 9
        | (extraCaps & 0x3ull) << 7
        | (length & 0x7full) << 0;
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
seL4_MessageInfo_set_label(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint64 v64) {

    do { if (!((((~0xfffffffffffff000ull >> 12 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 364, STRINGLITERAL); } } while(0);
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
seL4_MessageInfo_ptr_set_label(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint64 v64) {

    do { if (!((((~0xfffffffffffff000ull >> 12) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 384, STRINGLITERAL); } } while(0);
    seL4_MessageInfo_ptr->words[0] &= ~0xfffffffffffff000ull;
    seL4_MessageInfo_ptr->words[0] |= (v64 << 12) & 0xfffffffffffff000;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_MessageInfo_get_capsUnwrapped(seL4_MessageInfo_t seL4_MessageInfo) {
    seL4_Uint64 ret;
    ret = (seL4_MessageInfo.words[0] & 0xe00ull) >> 9;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_set_capsUnwrapped(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint64 v64) {

    do { if (!((((~0xe00ull >> 9 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 403, STRINGLITERAL); } } while(0);
    seL4_MessageInfo.words[0] &= ~0xe00ull;
    seL4_MessageInfo.words[0] |= (v64 << 9) & 0xe00ull;
    return seL4_MessageInfo;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_MessageInfo_ptr_get_capsUnwrapped(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_MessageInfo_ptr->words[0] & 0xe00ull) >> 9;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_MessageInfo_ptr_set_capsUnwrapped(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint64 v64) {

    do { if (!((((~0xe00ull >> 9) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 423, STRINGLITERAL); } } while(0);
    seL4_MessageInfo_ptr->words[0] &= ~0xe00ull;
    seL4_MessageInfo_ptr->words[0] |= (v64 << 9) & 0xe00;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_MessageInfo_get_extraCaps(seL4_MessageInfo_t seL4_MessageInfo) {
    seL4_Uint64 ret;
    ret = (seL4_MessageInfo.words[0] & 0x180ull) >> 7;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_set_extraCaps(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint64 v64) {

    do { if (!((((~0x180ull >> 7 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 442, STRINGLITERAL); } } while(0);
    seL4_MessageInfo.words[0] &= ~0x180ull;
    seL4_MessageInfo.words[0] |= (v64 << 7) & 0x180ull;
    return seL4_MessageInfo;
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

static inline void
seL4_MessageInfo_ptr_set_extraCaps(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint64 v64) {

    do { if (!((((~0x180ull >> 7) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 462, STRINGLITERAL); } } while(0);
    seL4_MessageInfo_ptr->words[0] &= ~0x180ull;
    seL4_MessageInfo_ptr->words[0] |= (v64 << 7) & 0x180;
}

static inline seL4_Uint64 __attribute__((__const__))
seL4_MessageInfo_get_length(seL4_MessageInfo_t seL4_MessageInfo) {
    seL4_Uint64 ret;
    ret = (seL4_MessageInfo.words[0] & 0x7full) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_set_length(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint64 v64) {

    do { if (!((((~0x7full >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 481, STRINGLITERAL); } } while(0);
    seL4_MessageInfo.words[0] &= ~0x7full;
    seL4_MessageInfo.words[0] |= (v64 << 0) & 0x7full;
    return seL4_MessageInfo;
}

static inline seL4_Uint64 __attribute__((__pure__))
seL4_MessageInfo_ptr_get_length(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
    seL4_Uint64 ret;
    ret = (seL4_MessageInfo_ptr->words[0] & 0x7full) >> 0;

    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
seL4_MessageInfo_ptr_set_length(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint64 v64) {

    do { if (!((((~0x7full >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) { zassert_fail(STRINGLITERAL, STRINGLITERAL, 501, STRINGLITERAL); } } while(0);
    seL4_MessageInfo_ptr->words[0] &= ~0x7full;
    seL4_MessageInfo_ptr->words[0] |= (v64 << 0) & 0x7f;
}






       



typedef struct seL4_IPCBuffer_ {
    seL4_MessageInfo_t tag;
    seL4_Word msg[seL4_MsgMaxLength];
    seL4_Word userData;
    seL4_Word caps_or_badges[((1ul<<(seL4_MsgExtraCapBits))-1)];
    seL4_CPtr receiveCNode;
    seL4_CPtr receiveIndex;
    seL4_Word receiveDepth;
} seL4_IPCBuffer __attribute__((__aligned__(sizeof(struct seL4_IPCBuffer_))));

typedef enum {
    seL4_CapFault_IP,
    seL4_CapFault_Addr,
    seL4_CapFault_InRecvPhase,
    seL4_CapFault_LookupFailureType,
    seL4_CapFault_BitsLeft,
    seL4_CapFault_DepthMismatch_BitsFound,
    seL4_CapFault_GuardMismatch_GuardFound = seL4_CapFault_DepthMismatch_BitsFound,
    seL4_CapFault_GuardMismatch_BitsFound,
    _enum_pad_seL4_CapFault_Msg = ((1ULL << ((sizeof(long)*8) - 1)) - 1),
} seL4_CapFault_Msg;






       







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
static inline void seL4_SetIPCBuffer(seL4_IPCBuffer *ipc_buffer)
{
    zsel4_ipc_buffer = ipc_buffer;
    return;
}

static inline seL4_IPCBuffer *seL4_GetIPCBuffer(void)
{
    return zsel4_ipc_buffer;
}

static inline seL4_Word seL4_GetMR(int i)
{
    return seL4_GetIPCBuffer()->msg[i];
}

static inline void seL4_SetMR(int i, seL4_Word mr)
{
    seL4_GetIPCBuffer()->msg[i] = mr;
}

static inline seL4_Word seL4_GetUserData(void)
{
    return seL4_GetIPCBuffer()->userData;
}

static inline void seL4_SetUserData(seL4_Word data)
{
    seL4_GetIPCBuffer()->userData = data;
}

static inline seL4_Word seL4_GetBadge(int i)
{
    return seL4_GetIPCBuffer()->caps_or_badges[i];
}

static inline seL4_CPtr seL4_GetCap(int i)
{
    return (seL4_CPtr)seL4_GetIPCBuffer()->caps_or_badges[i];
}

static inline void seL4_SetCap(int i, seL4_CPtr cptr)
{
    seL4_GetIPCBuffer()->caps_or_badges[i] = (seL4_Word)cptr;
}

static inline void seL4_GetCapReceivePath(seL4_CPtr *receiveCNode, seL4_CPtr *receiveIndex,
                                                seL4_Word *receiveDepth)
{
    seL4_IPCBuffer *ipcbuffer = seL4_GetIPCBuffer();
    if (receiveCNode != (void *)0) {
        *receiveCNode = ipcbuffer->receiveCNode;
    }

    if (receiveIndex != (void *)0) {
        *receiveIndex = ipcbuffer->receiveIndex;
    }

    if (receiveDepth != (void *)0) {
        *receiveDepth = ipcbuffer->receiveDepth;
    }
}

static inline void seL4_SetCapReceivePath(seL4_CPtr receiveCNode, seL4_CPtr receiveIndex, seL4_Word receiveDepth)
{
    seL4_IPCBuffer *ipcbuffer = seL4_GetIPCBuffer();
    ipcbuffer->receiveCNode = receiveCNode;
    ipcbuffer->receiveIndex = receiveIndex;
    ipcbuffer->receiveDepth = receiveDepth;
}






       
static inline void
seL4_Send(seL4_CPtr dest, seL4_MessageInfo_t msgInfo);
static inline seL4_MessageInfo_t
seL4_Recv(seL4_CPtr src, seL4_Word *sender, seL4_CPtr reply);
static inline seL4_MessageInfo_t
seL4_Call(seL4_CPtr dest, seL4_MessageInfo_t msgInfo);
static inline void
seL4_NBSend(seL4_CPtr dest, seL4_MessageInfo_t msgInfo);
static inline seL4_MessageInfo_t
seL4_ReplyRecv(seL4_CPtr src, seL4_MessageInfo_t msgInfo, seL4_Word *sender, seL4_CPtr reply);
static inline seL4_MessageInfo_t
seL4_NBRecv(seL4_CPtr src, seL4_Word *sender, seL4_CPtr reply);
static inline seL4_MessageInfo_t
seL4_NBSendRecv(seL4_CPtr dest, seL4_MessageInfo_t msgInfo, seL4_CPtr src, seL4_Word *sender, seL4_CPtr reply);
static inline seL4_MessageInfo_t
seL4_NBSendWait(seL4_CPtr dest, seL4_MessageInfo_t msgInfo, seL4_CPtr src, seL4_Word *sender);
static inline void
seL4_Yield(void);
static inline seL4_MessageInfo_t
seL4_Wait(seL4_CPtr src, seL4_Word *sender);
static inline seL4_MessageInfo_t
seL4_NBWait(seL4_CPtr src, seL4_Word *sender);
static inline seL4_MessageInfo_t
seL4_Poll(seL4_CPtr src, seL4_Word *sender);
static inline void
seL4_Signal(seL4_CPtr dest);






       









       
static inline void arm_sys_send(seL4_Word sys, seL4_Word dest, seL4_Word info_arg, seL4_Word mr0, seL4_Word mr1,
                                seL4_Word mr2, seL4_Word mr3)
{return;}
static inline void arm_sys_send_null(seL4_Word sys, seL4_Word src, seL4_Word info_arg)
{return;}

static inline void arm_sys_recv(seL4_Word sys, seL4_Word src, seL4_Word *out_badge, seL4_Word *out_info,
                                seL4_Word *out_mr0, seL4_Word *out_mr1, seL4_Word *out_mr2, seL4_Word *out_mr3, __attribute__((unused)) seL4_Word reply)
{return;}

static inline void arm_sys_send_recv(seL4_Word sys, seL4_Word dest, seL4_Word *out_badge, seL4_Word info_arg,
                                     seL4_Word *out_info, seL4_Word *in_out_mr0, seL4_Word *in_out_mr1, seL4_Word *in_out_mr2, seL4_Word *in_out_mr3,
                                     __attribute__((unused)) seL4_Word reply)
{return;}


static inline void arm_sys_nbsend_recv(seL4_Word sys, seL4_Word dest, seL4_Word src, seL4_Word *out_badge,
                                       seL4_Word info_arg,
                                       seL4_Word *out_info, seL4_Word *in_out_mr0, seL4_Word *in_out_mr1, seL4_Word *in_out_mr2,
                                       seL4_Word *in_out_mr3, seL4_Word reply)
{return;}


static inline void arm_sys_null(seL4_Word sys)
{return;}
static inline void seL4_Send(seL4_CPtr dest, seL4_MessageInfo_t msgInfo)
{
    /*arm_sys_send(seL4_SysSend, dest, msgInfo.words[0], seL4_GetMR(0), seL4_GetMR(1), seL4_GetMR(2), seL4_GetMR(3))*/
}

static inline void seL4_SendWithMRs(seL4_CPtr dest, seL4_MessageInfo_t msgInfo,
                                          seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3)
{
    /*arm_sys_send(seL4_SysSend, dest, msgInfo.words[0],
                 mr0 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr0 : 0,
                 mr1 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr1 : 0,
                 mr2 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr2 : 0,
                 mr3 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr3 : 0
                )*/
}

static inline void seL4_NBSend(seL4_CPtr dest, seL4_MessageInfo_t msgInfo)
{
    /*arm_sys_send(seL4_SysNBSend, dest, msgInfo.words[0], seL4_GetMR(0), seL4_GetMR(1), seL4_GetMR(2), seL4_GetMR(3))*/
}

static inline void seL4_NBSendWithMRs(seL4_CPtr dest, seL4_MessageInfo_t msgInfo,
                                            seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3)
{
    /*arm_sys_send(seL4_SysNBSend, dest, msgInfo.words[0],
                 mr0 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr0 : 0,
                 mr1 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr1 : 0,
                 mr2 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr2 : 0,
                 mr3 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0 ? *mr3 : 0
                )*/
}
static inline void seL4_Signal(seL4_CPtr dest)
{
    /*arm_sys_send_null(seL4_SysSend, dest, seL4_MessageInfo_new(0, 0, 0, 0).words[0])*/
}



static inline seL4_MessageInfo_t seL4_Recv(seL4_CPtr src, seL4_Word *sender, seL4_CPtr reply)



{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0;
    seL4_Word msg1;
    seL4_Word msg2;
    seL4_Word msg3;

    /*arm_sys_recv(seL4_SysRecv, src, &badge, &info.words[0], &msg0, &msg1, &msg2, &msg3, reply)*/

    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);


    if (sender) {
        *sender = badge;
    }
    return info;
}


static inline seL4_MessageInfo_t seL4_RecvWithMRs(seL4_CPtr src, seL4_Word *sender, seL4_CPtr reply,
                                                        seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3)




{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0 = 0;
    seL4_Word msg1 = 0;
    seL4_Word msg2 = 0;
    seL4_Word msg3 = 0;

    /*arm_sys_recv(seL4_SysRecv, src, &badge, &info.words[0], &msg0, &msg1, &msg2, &msg3, reply)*/


    if (mr0 != ((void*)0)) {
        *mr0 = msg0;
    }
    if (mr1 != ((void*)0)) {
        *mr1 = msg1;
    }
    if (mr2 != ((void*)0)) {
        *mr2 = msg2;
    }
    if (mr3 != ((void*)0)) {
        *mr3 = msg3;
    }


    if (sender) {
        *sender = badge;
    }
    return info;
}


static inline seL4_MessageInfo_t seL4_NBRecv(seL4_CPtr src, seL4_Word *sender, seL4_CPtr reply)



{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0;
    seL4_Word msg1;
    seL4_Word msg2;
    seL4_Word msg3;

    /*arm_sys_recv(seL4_SysNBRecv, src, &badge, &info.words[0], &msg0, &msg1, &msg2, &msg3, reply)*/

    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);


    if (sender) {
        *sender = badge;
    }
    return info;
}

static inline seL4_MessageInfo_t seL4_Call(seL4_CPtr dest, seL4_MessageInfo_t msgInfo)
{
    seL4_MessageInfo_t info;
    seL4_Word msg0 = seL4_GetMR(0);
    seL4_Word msg1 = seL4_GetMR(1);
    seL4_Word msg2 = seL4_GetMR(2);
    seL4_Word msg3 = seL4_GetMR(3);

    /*arm_sys_send_recv(seL4_SysCall, dest, &dest, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3, 0)*/


    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);

    return info;
}

static inline seL4_MessageInfo_t seL4_CallWithMRs(seL4_CPtr dest, seL4_MessageInfo_t msgInfo,
                                                        seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3)
{
    seL4_MessageInfo_t info;
    seL4_Word msg0 = 0;
    seL4_Word msg1 = 0;
    seL4_Word msg2 = 0;
    seL4_Word msg3 = 0;


    if (mr0 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0) {
        msg0 = *mr0;
    }
    if (mr1 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 1) {
        msg1 = *mr1;
    }
    if (mr2 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 2) {
        msg2 = *mr2;
    }
    if (mr3 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 3) {
        msg3 = *mr3;
    }

    /*arm_sys_send_recv(seL4_SysCall, dest, &dest, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3, 0)*/


    if (mr0 != ((void*)0)) {
        *mr0 = msg0;
    }
    if (mr1 != ((void*)0)) {
        *mr1 = msg1;
    }
    if (mr2 != ((void*)0)) {
        *mr2 = msg2;
    }
    if (mr3 != ((void*)0)) {
        *mr3 = msg3;
    }

    return info;
}


static inline seL4_MessageInfo_t seL4_ReplyRecv(seL4_CPtr src, seL4_MessageInfo_t msgInfo, seL4_Word *sender,
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

    /*arm_sys_send_recv(seL4_SysReplyRecv, src, &badge, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3,
                      reply)*/


    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);


    if (sender) {
        *sender = badge;
    }

    return info;
}


static inline seL4_MessageInfo_t seL4_ReplyRecvWithMRs(seL4_CPtr src, seL4_MessageInfo_t msgInfo,
                                                             seL4_Word *sender,
                                                             seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3, seL4_CPtr reply)





{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0 = 0;
    seL4_Word msg1 = 0;
    seL4_Word msg2 = 0;
    seL4_Word msg3 = 0;

    if (mr0 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0) {
        msg0 = *mr0;
    }
    if (mr1 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 1) {
        msg1 = *mr1;
    }
    if (mr2 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 2) {
        msg2 = *mr2;
    }
    if (mr3 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 3) {
        msg3 = *mr3;
    }

    /*arm_sys_send_recv(seL4_SysReplyRecv, src, &badge, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3,
                      reply)*/


    if (mr0 != ((void*)0)) {
        *mr0 = msg0;
    }
    if (mr1 != ((void*)0)) {
        *mr1 = msg1;
    }
    if (mr2 != ((void*)0)) {
        *mr2 = msg2;
    }
    if (mr3 != ((void*)0)) {
        *mr3 = msg3;
    }


    if (sender) {
        *sender = badge;
    }

    return info;
}


static inline seL4_MessageInfo_t seL4_NBSendRecv(seL4_CPtr dest, seL4_MessageInfo_t msgInfo, seL4_CPtr src,
                                                       seL4_Word *sender, seL4_CPtr reply)
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

    /*arm_sys_nbsend_recv(seL4_SysNBSendRecv, dest, src, &badge, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3,
                        reply)*/


    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);


    if (sender) {
        *sender = badge;
    }

    return info;
}

static inline seL4_MessageInfo_t seL4_NBSendRecvWithMRs(seL4_CPtr dest, seL4_MessageInfo_t msgInfo, seL4_CPtr src,
                                                              seL4_Word *sender,
                                                              seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3, seL4_CPtr reply)
{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0 = 0;
    seL4_Word msg1 = 0;
    seL4_Word msg2 = 0;
    seL4_Word msg3 = 0;

    if (mr0 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0) {
        msg0 = *mr0;
    }
    if (mr1 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 1) {
        msg1 = *mr1;
    }
    if (mr2 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 2) {
        msg2 = *mr2;
    }
    if (mr3 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 3) {
        msg3 = *mr3;
    }

    /*arm_sys_nbsend_recv(seL4_SysNBSendRecv, dest, src, &badge, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3,
                        reply)*/


    if (mr0 != ((void*)0)) {
        *mr0 = msg0;
    }
    if (mr1 != ((void*)0)) {
        *mr1 = msg1;
    }
    if (mr2 != ((void*)0)) {
        *mr2 = msg2;
    }
    if (mr3 != ((void*)0)) {
        *mr3 = msg3;
    }


    if (sender) {
        *sender = badge;
    }

    return info;
}

static inline seL4_MessageInfo_t seL4_NBSendWait(seL4_CPtr dest, seL4_MessageInfo_t msgInfo, seL4_CPtr src,
                                                       seL4_Word *sender)
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

    /*arm_sys_nbsend_recv(seL4_SysNBSendWait, 0, src, &badge, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3,
                        dest)*/


    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);


    if (sender) {
        *sender = badge;
    }

    return info;
}

static inline seL4_MessageInfo_t seL4_NBSendWaitWithMRs(seL4_CPtr dest, seL4_MessageInfo_t msgInfo, seL4_CPtr src,
                                                              seL4_Word *sender,
                                                              seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3)
{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0 = 0;
    seL4_Word msg1 = 0;
    seL4_Word msg2 = 0;
    seL4_Word msg3 = 0;

    if (mr0 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 0) {
        msg0 = *mr0;
    }
    if (mr1 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 1) {
        msg1 = *mr1;
    }
    if (mr2 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 2) {
        msg2 = *mr2;
    }
    if (mr3 != ((void*)0) && seL4_MessageInfo_get_length(msgInfo) > 3) {
        msg3 = *mr3;
    }

    /*arm_sys_nbsend_recv(seL4_SysNBSendRecv, 0, src, &badge, msgInfo.words[0], &info.words[0], &msg0, &msg1, &msg2, &msg3,
                        dest)*/


    if (mr0 != ((void*)0)) {
        *mr0 = msg0;
    }
    if (mr1 != ((void*)0)) {
        *mr1 = msg1;
    }
    if (mr2 != ((void*)0)) {
        *mr2 = msg2;
    }
    if (mr3 != ((void*)0)) {
        *mr3 = msg3;
    }


    if (sender) {
        *sender = badge;
    }

    return info;
}


static inline void seL4_Yield(void)
{return;}


static inline seL4_MessageInfo_t seL4_Wait(seL4_CPtr src, seL4_Word *sender)
{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0;
    seL4_Word msg1;
    seL4_Word msg2;
    seL4_Word msg3;

    /*arm_sys_recv(seL4_SysWait, src, &badge, &info.words[0], &msg0, &msg1, &msg2, &msg3, 0)*/

    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);


    if (sender) {
        *sender = badge;
    }
    return info;
}

static inline seL4_MessageInfo_t seL4_WaitWithMRs(seL4_CPtr src, seL4_Word *sender,
                                                        seL4_Word *mr0, seL4_Word *mr1, seL4_Word *mr2, seL4_Word *mr3)
{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0 = 0;
    seL4_Word msg1 = 0;
    seL4_Word msg2 = 0;
    seL4_Word msg3 = 0;

    /*arm_sys_recv(seL4_SysWait, src, &badge, &info.words[0], &msg0, &msg1, &msg2, &msg3, 0)*/


    if (mr0 != ((void*)0)) {
        *mr0 = msg0;
    }
    if (mr1 != ((void*)0)) {
        *mr1 = msg1;
    }
    if (mr2 != ((void*)0)) {
        *mr2 = msg2;
    }
    if (mr3 != ((void*)0)) {
        *mr3 = msg3;
    }


    if (sender) {
        *sender = badge;
    }
    return info;
}

static inline seL4_MessageInfo_t seL4_NBWait(seL4_CPtr src, seL4_Word *sender)
{
    seL4_MessageInfo_t info;
    seL4_Word badge;
    seL4_Word msg0;
    seL4_Word msg1;
    seL4_Word msg2;
    seL4_Word msg3;

    /*arm_sys_recv(seL4_SysNBWait, src, &badge, &info.words[0], &msg0, &msg1, &msg2, &msg3, 0)*/

    seL4_SetMR(0, msg0);
    seL4_SetMR(1, msg1);
    seL4_SetMR(2, msg2);
    seL4_SetMR(3, msg3);


    if (sender) {
        *sender = badge;
    }
    return info;
}
static inline seL4_MessageInfo_t seL4_Poll(seL4_CPtr src, seL4_Word *sender)
{


    return seL4_NBWait(src, sender);



}


enum invocation_label {
    InvalidInvocation,
    UntypedRetype,
    TCBReadRegisters,
    TCBWriteRegisters,
    TCBCopyRegisters,




    TCBConfigure,

    TCBSetPriority,
    TCBSetMCPriority,




    TCBSetSchedParams,


    TCBSetTimeoutEndpoint,

    TCBSetIPCBuffer,




    TCBSetSpace,

    TCBSuspend,
    TCBResume,
    TCBBindNotification,
    TCBUnbindNotification,
    TCBSetTLSBase,
    CNodeRevoke,
    CNodeDelete,
    CNodeCancelBadgedSends,
    CNodeCopy,
    CNodeMint,
    CNodeMove,
    CNodeMutate,
    CNodeRotate,



    IRQIssueIRQHandler,
    IRQAckIRQ,
    IRQSetIRQHandler,
    IRQClearIRQHandler,
    DomainSetSet,

    SchedControlConfigureFlags,


    SchedContextBind,


    SchedContextUnbind,


    SchedContextUnbindObject,


    SchedContextConsumed,


    SchedContextYieldTo,

    nInvocationLabels
};
enum sel4_arch_invocation_label {
    ARMVSpaceClean_Data = nInvocationLabels,
    ARMVSpaceInvalidate_Data,
    ARMVSpaceCleanInvalidate_Data,
    ARMVSpaceUnify_Instruction,

    ARMPageUpperDirectoryMap,


    ARMPageUpperDirectoryUnmap,

    ARMPageDirectoryMap,
    ARMPageDirectoryUnmap,
    nSeL4ArchInvocationLabels
};
enum arch_invocation_label {
    ARMPageTableMap = nSeL4ArchInvocationLabels,
    ARMPageTableUnmap,






    ARMPageMap,
    ARMPageUnmap,



    ARMPageClean_Data,
    ARMPageInvalidate_Data,
    ARMPageCleanInvalidate_Data,
    ARMPageUnify_Instruction,
    ARMPageGetAddress,
    ARMASIDControlMakePool,
    ARMASIDPoolAssign,
    ARMIRQIssueIRQHandlerTrigger,
    nArchInvocationLabels
};
typedef unsigned long __type_int_size_incorrect[ (sizeof(int) == 4) ? 1 : -1];
typedef unsigned long __type_long_size_incorrect[ (sizeof(long) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_Uint8_size_incorrect[ (sizeof(seL4_Uint8) == 1) ? 1 : -1];
typedef unsigned long __type_seL4_Uint16_size_incorrect[ (sizeof(seL4_Uint16) == 2) ? 1 : -1];
typedef unsigned long __type_seL4_Uint32_size_incorrect[ (sizeof(seL4_Uint32) == 4) ? 1 : -1];
typedef unsigned long __type_seL4_Uint64_size_incorrect[ (sizeof(seL4_Uint64) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_Time_size_incorrect[ (sizeof(seL4_Time) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_Word_size_incorrect[ (sizeof(seL4_Word) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_Bool_size_incorrect[ (sizeof(seL4_Bool) == 1) ? 1 : -1];
typedef unsigned long __type_seL4_CapRights_t_size_incorrect[ (sizeof(seL4_CapRights_t) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_CPtr_size_incorrect[ (sizeof(seL4_CPtr) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_CNode_size_incorrect[ (sizeof(seL4_CNode) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_IRQHandler_size_incorrect[ (sizeof(seL4_IRQHandler) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_IRQControl_size_incorrect[ (sizeof(seL4_IRQControl) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_TCB_size_incorrect[ (sizeof(seL4_TCB) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_Untyped_size_incorrect[ (sizeof(seL4_Untyped) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_DomainSet_size_incorrect[ (sizeof(seL4_DomainSet) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_SchedContext_size_incorrect[ (sizeof(seL4_SchedContext) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_SchedControl_size_incorrect[ (sizeof(seL4_SchedControl) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_VMAttributes_size_incorrect[ (sizeof(seL4_ARM_VMAttributes) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_Page_size_incorrect[ (sizeof(seL4_ARM_Page) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_PageTable_size_incorrect[ (sizeof(seL4_ARM_PageTable) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_PageDirectory_size_incorrect[ (sizeof(seL4_ARM_PageDirectory) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_PageUpperDirectory_size_incorrect[ (sizeof(seL4_ARM_PageUpperDirectory) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_PageGlobalDirectory_size_incorrect[ (sizeof(seL4_ARM_PageGlobalDirectory) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_VSpace_size_incorrect[ (sizeof(seL4_ARM_VSpace) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_ASIDControl_size_incorrect[ (sizeof(seL4_ARM_ASIDControl) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_ASIDPool_size_incorrect[ (sizeof(seL4_ARM_ASIDPool) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_VCPU_size_incorrect[ (sizeof(seL4_ARM_VCPU) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_IOSpace_size_incorrect[ (sizeof(seL4_ARM_IOSpace) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_IOPageTable_size_incorrect[ (sizeof(seL4_ARM_IOPageTable) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_UserContext_size_incorrect[ (sizeof(seL4_UserContext) == 288) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_SIDControl_size_incorrect[ (sizeof(seL4_ARM_SIDControl) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_SID_size_incorrect[ (sizeof(seL4_ARM_SID) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_CBControl_size_incorrect[ (sizeof(seL4_ARM_CBControl) == 8) ? 1 : -1];
typedef unsigned long __type_seL4_ARM_CB_size_incorrect[ (sizeof(seL4_ARM_CB) == 8) ? 1 : -1];




struct seL4_ARM_Page_GetAddress {
 int error;
 seL4_Word paddr;
};
typedef struct seL4_ARM_Page_GetAddress seL4_ARM_Page_GetAddress_t;

struct seL4_ARM_VCPU_ReadRegs {
 int error;
 seL4_Word value;
};
typedef struct seL4_ARM_VCPU_ReadRegs seL4_ARM_VCPU_ReadRegs_t;

struct seL4_ARM_SIDControl_GetFault {
 int error;
 seL4_Word status;
 seL4_Word syndrome_0;
 seL4_Word syndrome_1;
};
typedef struct seL4_ARM_SIDControl_GetFault seL4_ARM_SIDControl_GetFault_t;

struct seL4_ARM_CB_CBGetFault {
 int error;
 seL4_Word status;
 seL4_Word address;
};
typedef struct seL4_ARM_CB_CBGetFault seL4_ARM_CB_CBGetFault_t;

struct seL4_TCB_GetBreakpoint {
 int error;
 seL4_Word vaddr;
 seL4_Word type;
 seL4_Word size;
 seL4_Word rw;
 seL4_Bool is_enabled;
};
typedef struct seL4_TCB_GetBreakpoint seL4_TCB_GetBreakpoint_t;

struct seL4_TCB_ConfigureSingleStepping {
 int error;
 seL4_Bool bp_was_consumed;
};
typedef struct seL4_TCB_ConfigureSingleStepping seL4_TCB_ConfigureSingleStepping_t;

struct seL4_SchedContext_Consumed {
 int error;
 seL4_Time consumed;
};
typedef struct seL4_SchedContext_Consumed seL4_SchedContext_Consumed_t;

struct seL4_SchedContext_YieldTo {
 int error;
 seL4_Time consumed;
};
typedef struct seL4_SchedContext_YieldTo seL4_SchedContext_YieldTo_t;
static inline seL4_Error
seL4_ARM_VSpace_Clean_Data(seL4_ARM_VSpace _service, seL4_Word start, seL4_Word end)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_VSpace_Invalidate_Data(seL4_ARM_VSpace _service, seL4_Word start, seL4_Word end)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_VSpace_CleanInvalidate_Data(seL4_ARM_VSpace _service, seL4_Word start, seL4_Word end)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_VSpace_Unify_Instruction(seL4_ARM_VSpace _service, seL4_Word start, seL4_Word end)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_PageUpperDirectory_Map(seL4_ARM_PageUpperDirectory _service, seL4_CPtr vspace, seL4_Word vaddr, seL4_ARM_VMAttributes attr)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_PageUpperDirectory_Unmap(seL4_ARM_PageUpperDirectory _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_PageDirectory_Map(seL4_ARM_PageDirectory _service, seL4_CPtr vspace, seL4_Word vaddr, seL4_ARM_VMAttributes attr)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_PageDirectory_Unmap(seL4_ARM_PageDirectory _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_PageTable_Map(seL4_ARM_PageTable _service, seL4_CPtr vspace, seL4_Word vaddr, seL4_ARM_VMAttributes attr)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_PageTable_Unmap(seL4_ARM_PageTable _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_Page_Map(seL4_ARM_Page _service, seL4_CPtr vspace, seL4_Word vaddr, seL4_CapRights_t rights, seL4_ARM_VMAttributes attr)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_Page_Unmap(seL4_ARM_Page _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_Page_Clean_Data(seL4_ARM_Page _service, seL4_Word start_offset, seL4_Word end_offset)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_Page_Invalidate_Data(seL4_ARM_Page _service, seL4_Word start_offset, seL4_Word end_offset)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_Page_CleanInvalidate_Data(seL4_ARM_Page _service, seL4_Word start_offset, seL4_Word end_offset)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_Page_Unify_Instruction(seL4_ARM_Page _service, seL4_Word start_offset, seL4_Word end_offset)
{return seL4_NoError;}
static inline seL4_ARM_Page_GetAddress_t
seL4_ARM_Page_GetAddress(seL4_ARM_Page _service)
{seL4_ARM_Page_GetAddress_t result; return result;}
static inline seL4_Error
seL4_ARM_ASIDControl_MakePool(seL4_ARM_ASIDControl _service, seL4_Untyped untyped, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_ARM_ASIDPool_Assign(seL4_ARM_ASIDPool _service, seL4_CPtr vspace)
{return seL4_NoError;}
static inline seL4_Error
seL4_IRQControl_GetTrigger(seL4_IRQControl _service, seL4_Word irq, seL4_Word trigger, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_Untyped_Retype(seL4_Untyped _service, seL4_Word type, seL4_Word size_bits, seL4_CNode root, seL4_Word node_index, seL4_Word node_depth, seL4_Word node_offset, seL4_Word num_objects)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_ReadRegisters(seL4_TCB _service, seL4_Bool suspend_source, seL4_Uint8 arch_flags, seL4_Word count, seL4_UserContext *regs)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_WriteRegisters(seL4_TCB _service, seL4_Bool resume_target, seL4_Uint8 arch_flags, seL4_Word count, seL4_UserContext *regs)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_CopyRegisters(seL4_TCB _service, seL4_TCB source, seL4_Bool suspend_source, seL4_Bool resume_target, seL4_Bool transfer_frame, seL4_Bool transfer_integer, seL4_Uint8 arch_flags)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_Configure(seL4_TCB _service, seL4_CNode cspace_root, seL4_Word cspace_root_data, seL4_CPtr vspace_root, seL4_Word vspace_root_data, seL4_Word buffer, seL4_CPtr bufferFrame)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_SetPriority(seL4_TCB _service, seL4_TCB authority, seL4_Word priority)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_SetMCPriority(seL4_TCB _service, seL4_TCB authority, seL4_Word mcp)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_SetSchedParams(seL4_TCB _service, seL4_TCB authority, seL4_Word mcp, seL4_Word priority, seL4_CPtr sched_context, seL4_CPtr fault_ep)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_SetTimeoutEndpoint(seL4_TCB _service, seL4_CPtr timeout_fault_ep)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_SetIPCBuffer(seL4_TCB _service, seL4_Word buffer, seL4_CPtr bufferFrame)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_SetSpace(seL4_TCB _service, seL4_CPtr fault_ep, seL4_CNode cspace_root, seL4_Word cspace_root_data, seL4_CPtr vspace_root, seL4_Word vspace_root_data)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_Suspend(seL4_TCB _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_Resume(seL4_TCB _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_BindNotification(seL4_TCB _service, seL4_CPtr notification)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_UnbindNotification(seL4_TCB _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_TCB_SetTLSBase(seL4_TCB _service, seL4_Word tls_base)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_Revoke(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_Delete(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_CancelBadgedSends(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_Copy(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_CapRights_t rights)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_Mint(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_CapRights_t rights, seL4_Word badge)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_Move(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_Mutate(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_Word badge)
{return seL4_NoError;}
static inline seL4_Error
seL4_CNode_Rotate(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_Word dest_badge, seL4_CNode pivot_root, seL4_Word pivot_index, seL4_Uint8 pivot_depth, seL4_Word pivot_badge, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_IRQControl_Get(seL4_IRQControl _service, seL4_Word irq, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{return seL4_NoError;}
static inline seL4_Error
seL4_IRQHandler_Ack(seL4_IRQHandler _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_IRQHandler_SetNotification(seL4_IRQHandler _service, seL4_CPtr notification)
{return seL4_NoError;}
static inline seL4_Error
seL4_IRQHandler_Clear(seL4_IRQHandler _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_DomainSet_Set(seL4_DomainSet _service, seL4_Uint8 domain, seL4_TCB thread)
{return seL4_NoError;}
static inline seL4_Error
seL4_SchedControl_ConfigureFlags(seL4_SchedControl _service, seL4_SchedContext schedcontext, seL4_Time budget, seL4_Time period, seL4_Word extra_refills, seL4_Word badge, seL4_Word flags)
{return seL4_NoError;}
static inline seL4_Error
seL4_SchedContext_Bind(seL4_SchedContext _service, seL4_CPtr cap)
{return seL4_NoError;}
static inline seL4_Error
seL4_SchedContext_Unbind(seL4_SchedContext _service)
{return seL4_NoError;}
static inline seL4_Error
seL4_SchedContext_UnbindObject(seL4_SchedContext _service, seL4_CPtr cap)
{return seL4_NoError;}
static inline seL4_SchedContext_Consumed_t
seL4_SchedContext_Consumed(seL4_SchedContext _service)
{
 seL4_SchedContext_Consumed_t result;
  return result;
 }

static inline seL4_SchedContext_YieldTo_t
seL4_SchedContext_YieldTo(seL4_SchedContext _service)
{
 seL4_SchedContext_YieldTo_t result;
  return result;
 }


       
static inline seL4_Error seL4_SchedControl_Configure(seL4_SchedControl _service, seL4_SchedContext schedcontext,
                                                      seL4_Time budget, seL4_Time period, seL4_Word extra_refills, seL4_Word badge)
{
    return seL4_SchedControl_ConfigureFlags(_service, schedcontext, budget, period, extra_refills, badge,
                                            seL4_SchedContext_NoFlag);
}







       








       




enum {
    seL4_CapNull = 0,
    seL4_CapInitThreadTCB = 1,
    seL4_CapInitThreadCNode = 2,
    seL4_CapInitThreadVSpace = 3,
    seL4_CapIRQControl = 4,
    seL4_CapASIDControl = 5,
    seL4_CapInitThreadASIDPool = 6,
    seL4_CapIOPortControl = 7,
    seL4_CapIOSpace = 8,
    seL4_CapBootInfoFrame = 9,
    seL4_CapInitThreadIPCBuffer = 10,
    seL4_CapDomain = 11,
    seL4_CapSMMUSIDControl = 12,
    seL4_CapSMMUCBControl = 13,

    seL4_CapInitThreadSC = 14,
    seL4_NumInitialCaps = 15



};






typedef seL4_Word seL4_SlotPos;

typedef struct seL4_SlotRegion {
    seL4_SlotPos start;
    seL4_SlotPos end;
} seL4_SlotRegion;

typedef struct seL4_UntypedDesc {
    seL4_Word paddr;
    seL4_Uint8 sizeBits;
    seL4_Uint8 isDevice;
    seL4_Uint8 padding[sizeof(seL4_Word) - 2 * sizeof(seL4_Uint8)];
} seL4_UntypedDesc;

typedef struct seL4_BootInfo {
    seL4_Word extraLen;
    seL4_NodeId nodeID;
    seL4_Word numNodes;
    seL4_Word numIOPTLevels;
    seL4_IPCBuffer *ipcBuffer;
    seL4_SlotRegion empty;
    seL4_SlotRegion sharedFrames;
    seL4_SlotRegion userImageFrames;
    seL4_SlotRegion userImagePaging;
    seL4_SlotRegion ioSpaceCaps;
    seL4_SlotRegion extraBIPages;
    seL4_Word initThreadCNodeSizeBits;
    seL4_Domain initThreadDomain;

    seL4_SlotRegion schedcontrol;

    seL4_SlotRegion untyped;
    seL4_UntypedDesc untypedList[230];


} seL4_BootInfo;




typedef struct seL4_BootInfoHeader {

    seL4_Word id;

    seL4_Word len;
} seL4_BootInfoHeader;


void seL4_InitBootInfo(seL4_BootInfo *bi)
;
seL4_BootInfo *seL4_GetBootInfo(void)
;






       









       





static inline seL4_Fault_t seL4_getArchFault(seL4_MessageInfo_t tag)
{
    switch (seL4_MessageInfo_get_label(tag)) {
    case seL4_Fault_UnknownSyscall:
        return seL4_Fault_UnknownSyscall_new(seL4_GetMR(seL4_UnknownSyscall_X0),
                                             seL4_GetMR(seL4_UnknownSyscall_X1),
                                             seL4_GetMR(seL4_UnknownSyscall_X2),
                                             seL4_GetMR(seL4_UnknownSyscall_X3),
                                             seL4_GetMR(seL4_UnknownSyscall_X4),
                                             seL4_GetMR(seL4_UnknownSyscall_X5),
                                             seL4_GetMR(seL4_UnknownSyscall_X6),
                                             seL4_GetMR(seL4_UnknownSyscall_X7),
                                             seL4_GetMR(seL4_UnknownSyscall_FaultIP),
                                             seL4_GetMR(seL4_UnknownSyscall_SP),
                                             seL4_GetMR(seL4_UnknownSyscall_LR),
                                             seL4_GetMR(seL4_UnknownSyscall_SPSR),
                                             seL4_GetMR(seL4_UnknownSyscall_Syscall));

    case seL4_Fault_UserException:
        return seL4_Fault_UserException_new(seL4_GetMR(seL4_UserException_FaultIP),
                                            seL4_GetMR(seL4_UserException_SP),
                                            seL4_GetMR(seL4_UserException_SPSR),
                                            seL4_GetMR(seL4_UserException_Number),
                                            seL4_GetMR(seL4_UserException_Code));
    case seL4_Fault_VMFault:
        return seL4_Fault_VMFault_new(seL4_GetMR(seL4_VMFault_IP),
                                      seL4_GetMR(seL4_VMFault_Addr),
                                      seL4_GetMR(seL4_VMFault_PrefetchFault),
                                      seL4_GetMR(seL4_VMFault_FSR));
    case seL4_Fault_Timeout:
        return seL4_Fault_Timeout_new(seL4_GetMR(seL4_Timeout_Data),
                                      seL4_GetMR(seL4_Timeout_Consumed));

    default:
        return seL4_Fault_NullFault_new();
    }
}

static inline seL4_Fault_t seL4_getFault(seL4_MessageInfo_t tag)
{

    switch (seL4_MessageInfo_get_label(tag)) {
    case seL4_Fault_CapFault:
        return seL4_Fault_CapFault_new(seL4_GetMR(seL4_CapFault_IP),
                                       seL4_GetMR(seL4_CapFault_Addr),
                                       seL4_GetMR(seL4_CapFault_InRecvPhase),
                                       seL4_GetMR(seL4_CapFault_LookupFailureType),
                                       seL4_GetMR(seL4_CapFault_BitsLeft),
                                       seL4_GetMR(seL4_CapFault_GuardMismatch_GuardFound),
                                       seL4_GetMR(seL4_CapFault_GuardMismatch_BitsFound));







    default:
        return seL4_getArchFault(tag);
    }
}
static inline seL4_Bool seL4_isVMFault_tag(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_label(tag) == seL4_Fault_VMFault;
}

static inline seL4_Bool seL4_isUnknownSyscall_tag(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_label(tag) == seL4_Fault_UnknownSyscall;
}

static inline seL4_Bool seL4_isUserException_tag(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_label(tag) == seL4_Fault_UserException;
}

static inline seL4_Bool seL4_isNullFault_tag(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_label(tag) == seL4_Fault_NullFault;
}

static inline seL4_Bool seL4_isCapFault_tag(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_label(tag) == seL4_Fault_CapFault;
}


static inline seL4_Bool seL4_isTimeoutFault_tag(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_label(tag) == seL4_Fault_Timeout;
}

static inline seL4_MessageInfo_t seL4_TimeoutReply_new(seL4_Bool resume, seL4_UserContext regs, seL4_Word length)
{
    seL4_MessageInfo_t info = seL4_MessageInfo_new(!resume, 0, 0, length);
    return info;
}






       








       









       
typedef seL4_CapRights_t seL4_CapRights ;

//typedef union  seL4_PageFaultIpcRegisters ;

typedef seL4_Fault_tag_t seL4_FaultType ;







static inline  seL4_MessageInfo_t
seL4_GetTag(void)
{
    return seL4_GetIPCBuffer()->tag;
}

static inline  void
seL4_SetTag(seL4_MessageInfo_t tag)
{
    seL4_GetIPCBuffer()->tag = tag;
}

static inline  seL4_Word
seL4_PF_FIP(void)
{
    return seL4_GetMR(seL4_VMFault_IP);
}

static inline  seL4_Word
seL4_PF_Addr(void)
{
    return seL4_GetMR(seL4_VMFault_Addr);
}

static inline  seL4_Word
seL4_isPageFault_MSG(void)
{
    return seL4_isVMFault_tag(seL4_GetIPCBuffer()->tag);
}

static inline  seL4_Word
seL4_isPageFault_Tag(seL4_MessageInfo_t tag)
{
    return seL4_isVMFault_tag(tag);
}

static inline  seL4_Word
seL4_isExceptIPC_Tag(seL4_MessageInfo_t tag)
{
    return seL4_isUnknownSyscall_tag(tag);
}

static inline  seL4_Word
seL4_ExceptIPC_Get(seL4_Word mr)
{
    return seL4_GetMR(mr);
}

static inline  void
seL4_ExceptIPC_Set(seL4_Word index, seL4_Word val)
{
    seL4_SetMR(index, val);
}

static inline  seL4_Word
seL4_IsArchSyscallFrom(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_length(tag) == seL4_UnknownSyscall_Length;
}

static inline  seL4_Word
seL4_IsArchExceptionFrom(seL4_MessageInfo_t tag)
{
    return seL4_MessageInfo_get_length(tag) == seL4_UnknownSyscall_Length;
}

typedef seL4_Word seL4_CapData_t ;

static inline  seL4_Word seL4_CapData_Badge_new(seL4_Word badge)
{
    return badge;
}

static inline  seL4_Word seL4_CapData_Guard_new(seL4_Word guard,
                                                                                                        seL4_Word bits)
{
    return seL4_CNode_CapData_new(guard, bits).words[0];
}









       

       







typedef unsigned int microkit_channel;
typedef seL4_MessageInfo_t microkit_msginfo;
void init(void);
void notified(microkit_channel ch);
microkit_msginfo protected(microkit_channel ch, microkit_msginfo msginfo);

extern char microkit_name[16];

extern 
      char 
           have_signal;
extern seL4_CPtr signal;
extern seL4_MessageInfo_t signal_msg;




void microkit_dbg_putc(int c);




void microkit_dbg_puts(const char *s);

static inline void
microkit_notify(microkit_channel ch)
{
    seL4_Signal(10 + ch);
}

static inline void
microkit_irq_ack(microkit_channel ch)
{
    seL4_IRQHandler_Ack(138 + ch);
}

static inline microkit_msginfo
microkit_ppcall(microkit_channel ch, microkit_msginfo msginfo)
{
    return seL4_Call(74 + ch, msginfo);
}

static inline microkit_msginfo
microkit_msginfo_new(uint64_t label, uint16_t count)
{
    return seL4_MessageInfo_new(label, 0, 0, count);
}

static inline uint64_t
microkit_msginfo_get_label(microkit_msginfo msginfo)
{
    return seL4_MessageInfo_get_label(msginfo);
}

static void
microkit_mr_set(uint8_t mr, uint64_t value)
{
    seL4_SetMR(mr, value);
}

static uint64_t
microkit_mr_get(uint8_t mr)
{
    return seL4_GetMR(mr);
}






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

__attribute__((weak)) microkit_msginfo protected(microkit_channel ch, microkit_msginfo msginfo)
{
    return seL4_MessageInfo_new(0, 0, 0, 0);
}

static void run_init_funcs(void)
{return;}

seL4_Word gbadge;

static void handler_loop(void)
{
    
   char have_reply = 0;
   char lhave_signal = have_signal;

    seL4_MessageInfo_t reply_tag;
    seL4_Word badge;

    for (;;) {
        seL4_MessageInfo_t tag;

        if (have_reply) {
            tag = seL4_ReplyRecv(1, reply_tag, &gbadge, 4);
            badge = gbadge;
        } else if (lhave_signal) {
            tag = seL4_NBSendRecv(signal, signal_msg, 1, &gbadge, 4);
            badge = gbadge;
            lhave_signal = 
                         0
                              ;
        } else {
            tag = seL4_Recv(1, &gbadge, 4);
            badge = gbadge;
        }

        uint64_t is_endpoint = badge >> 63;

        if (is_endpoint) {
            have_reply = 
                        1
                            ;
            reply_tag = protected(badge & 0x3f, tag);
        } else {
            unsigned int idx = 0;
            have_reply = 
                        0
                             ;
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

void main(void)
{
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

