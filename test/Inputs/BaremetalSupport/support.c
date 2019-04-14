#include <_syslist.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern int main(int argc, char *argv[]);
extern void (*__init_array_start[])(void);
extern void (*__init_array_end[])(void);
static void HandlerC(unsigned long *hardfault_args);

static int SYS_OPEN = 0x01;
static int SYS_CLOSE = 0x02;
static int SYS_WRITEC = 0x03;
static int SYS_WRITE0 = 0x04;
static int SYS_WRITE = 0x05;
static int SYS_READ = 0x06;
static int SYS_ISTTY = 0x09;
static int SYS_EXIT = 0x18;
static int SYS_SEEK = 0x0A;
static int SYS_GET_CMDLINE = 0x15;

static char* cmdline[1024];

int hostcall(int call, int arg0) {
  register volatile int reg0 asm("r0");
  register volatile int reg1 asm("r1");

  asm volatile("mov r0,r0");

  reg0 = call;
  reg1 = arg0;
  asm("bkpt #0xAB");
  return reg0;
}

void *_sbrk(incr) int incr;
{
  extern char end; /* Set by linker.  */
  static char *heap_end;
  char *prev_heap_end;

  if (heap_end == 0)
    heap_end = &end;

  prev_heap_end = heap_end;
  heap_end += incr;

  return (void *)prev_heap_end;
}

int _kill() {
  errno = ENOSYS;
  return -1;
}

int _getpid() {
  errno = ENOSYS;
  return 0;
}

int _fstat() {
  errno = ENOSYS;
  return -1;
}

int _isatty(int fd) { return hostcall(SYS_ISTTY, (int)&fd); }

int _open(const char *path, int oflag) {
  int args[3] = {(int)path, oflag, strlen(path)};
  return hostcall(SYS_OPEN, (int)&args);
}

int _read(int fd, void *buf, size_t nb) {
  int args[4] = {fd, (int)buf, (int)nb, 0};
  return hostcall(SYS_READ, (int)&args);
}

int _write(int fd, const uint8_t *buf, size_t count) {
  int args[3] = {fd, (int)buf, count};
  return hostcall(SYS_WRITE, (int)&args) > 0 ? -1 : count;
}

int _close(int fd) { return hostcall(SYS_CLOSE, (int)&fd); }

int _lseek(int fd, int offset, int whence) {
  if (whence != 0)
    return -1;
  int args[2] = {fd, offset};
  return hostcall(SYS_SEEK, (int)&args);
}

static void init_array() {
  int count = __init_array_end - __init_array_start;
  for (int i = 0; i < count; i++)
    __init_array_start[i]();
}

char* get_commandline(int* buf_size) {
    static char buffer[1024];
    int args[2] = { (int)buffer, sizeof(buffer) };
    int retval = hostcall(SYS_GET_CMDLINE, (int)&args);
    *buf_size = args[1];
    return buffer;
}

void _exit(int code) { hostcall(SYS_EXIT, code); }

/*
 * Main entrypoint called by startup file
 */
void _start() {
  // initialize global variables
  init_array();
  // call swift
  int retval = main(0, 0);
  // exit using semihosting api semihosting
  _exit(retval == 0 ? 0x20026 : 1);
}

void HardFault_Handler() {
  __asm volatile(
      " movs r0,#4      \n" /* load bit mask into R0 */
      " movs r1, lr     \n" /* load link register into R1 */
      " tst r0, r1      \n" /* compare with bitmask */
      " beq _MSP        \n" /* if bitmask is set: stack pointer is in PSP.
                               Otherwise in MSP */
      " mrs r0, psp     \n" /* otherwise: stack pointer is in PSP */
      " b _GetPC        \n" /* go to part which loads the PC */
      "_MSP:            \n" /* stack pointer is in MSP register */
      " mrs r0, msp     \n" /* load stack pointer into R0 */
      "_GetPC:          \n" /* find out where the hard fault happened */
      " ldr r1,[r0,#20] \n" /* load program counter into R1. R1 contains address
                               of the next instruction where the hard fault
                               happened */
      " b HandlerC      \n" /* decode more information. R0 contains pointer to
                               stack frame */
  );
  HandlerC(0);
}

void MemManage_Handler(void) { _exit(1); }

void BusFault_Handler(void) { _exit(1); }

void UsageFault_Handler(void) { _exit(1); }

void SVC_Handler(void) { _exit(1); }

void DebugMon_Handler(void) { _exit(1); }

void PendSV_Handler(void) { _exit(1); }

void SysTick_Handler(void) { _exit(1); }

static void HandlerC(unsigned long *hardfault_args) {
  volatile unsigned long stacked_r0;
  volatile unsigned long stacked_r1;
  volatile unsigned long stacked_r2;
  volatile unsigned long stacked_r3;
  volatile unsigned long stacked_r12;
  volatile unsigned long stacked_lr;
  volatile unsigned long stacked_pc;
  volatile unsigned long stacked_psr;
  volatile unsigned long _CFSR;
  volatile unsigned long _HFSR;
  volatile unsigned long _DFSR;
  volatile unsigned long _AFSR;
  volatile unsigned long _BFAR;
  volatile unsigned long _MMAR;

  /* suppress warnings about unused variables */
  (void)stacked_r0;
  (void)stacked_r1;
  (void)stacked_r2;
  (void)stacked_r3;
  (void)stacked_r12;
  (void)stacked_lr;
  (void)stacked_pc;
  (void)stacked_psr;
  (void)_CFSR;
  (void)_HFSR;
  (void)_DFSR;
  (void)_AFSR;
  (void)_BFAR;
  (void)_MMAR;

  stacked_r0 = ((unsigned long)hardfault_args[0]);
  stacked_r1 = ((unsigned long)hardfault_args[1]);
  stacked_r2 = ((unsigned long)hardfault_args[2]);
  stacked_r3 = ((unsigned long)hardfault_args[3]);
  stacked_r12 = ((unsigned long)hardfault_args[4]);
  stacked_lr = ((unsigned long)hardfault_args[5]);
  stacked_pc = ((unsigned long)hardfault_args[6]);
  stacked_psr = ((unsigned long)hardfault_args[7]);

  /* Configurable Fault Status Register */
  /* Consists of MMSR, BFSR and UFSR */
  _CFSR = (*((volatile unsigned long *)(0xE000ED28)));

  /* Hard Fault Status Register */
  _HFSR = (*((volatile unsigned long *)(0xE000ED2C)));

  /* Debug Fault Status Register */
  _DFSR = (*((volatile unsigned long *)(0xE000ED30)));

  /* Auxiliary Fault Status Register */
  _AFSR = (*((volatile unsigned long *)(0xE000ED3C)));

  /* Read the Fault Address Registers. These may not contain valid values.
   * Check BFARVALID/MMARVALID to see if they are valid values
   * MemManage Fault Address Register
   */
  _MMAR = (*((volatile unsigned long *)(0xE000ED34)));
  /* Bus Fault Address Register */
  _BFAR = (*((volatile unsigned long *)(0xE000ED38)));

  _exit(1);
}
