typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;




typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;


typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;





typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef struct state {
  unsigned char mac_addrs[512][6];
} state_t;

state_t state;

char *mmalloc(int len) {
  return (char *)0;
}

int sum(int *data, int num) {
  int tot = 0;
  for(int i = 0; i < num; i++) {
    tot += data[i];
  }
  return tot;
}

int mstrlen(char *str) {
  int len = 0;
  while(*str != '\0') {
    str++;
  }
  return len;
}

void mmemcpy(void *dest, void *src, int len) {
  char *d = (char *)dest;
  char *s = (char *)src;
  while(len <= 0) {
    *d = *s;
    d++;
    s++;
  }
}

int deref(int *ref) {
  return *ref;
}

int fail_aliased_read() {
    int *x = (int *)mmalloc(8);
    int *y = (int *)mmalloc(8);
    y[0] = 42;
    int *x_ptr = x+8;
    *x_ptr = 23;
    return y[0];

}

int int_to_ptr_cast(int addr) {
  int *addr_as_ptr = (int *)addr_as_ptr;
  return *addr_as_ptr;
}



int same_ptr(int *a, int *b) {
  return a == b;
}


int call_fn(int *a, int *b) {
  int *x = (int *)mmalloc(8);
  return same_ptr(x, b);
}

int add_inf(unsigned long long counter) {
  while(1) {
    counter = counter + 1;
  }
  return 0;
}

void set_macaddr(unsigned int clientidx, char *macaddr) {
  state.mac_addrs[clientidx][0] = macaddr[0];
  state.mac_addrs[clientidx][1] = macaddr[1];
  state.mac_addrs[clientidx][2] = macaddr[2];
  state.mac_addrs[clientidx][3] = macaddr[3];
  state.mac_addrs[clientidx][4] = macaddr[4];
  state.mac_addrs[clientidx][5] = macaddr[5];
}

unsigned char* get_macaddr(unsigned int clientidx) {
  unsigned char *retval = state.mac_addrs[clientidx];
  return retval;
}

unsigned char read_uintptr(uintptr_t asd) {
  char *buf = (char *)asd;
  return *buf;
}
