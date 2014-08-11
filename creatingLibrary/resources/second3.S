#include <asm/unistd.h>
#include <syscall.h>
#define STDOUT_FILENO 1

.file "second3.S"
.section        .rodata
L1:
   .string "My second program\n"
L2:

.text
.globl _start
_start:
       movl  $(SYS_write), %eax
       movq  $(STDOUT_FILENO), %rdi
       movq  $L1, %rsi
       movq  $(L2-L1), %rdx
       syscall
       movl  $(SYS_exit), %eax
       movq  $0, %rdi
       syscall
       ret

