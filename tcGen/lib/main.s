	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"Error!"
.LC1:
	.string	"OK"
	.text
	.globl	printStatus
	.type	printStatus, @function
printStatus:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	je	.L2
	movl	$.LC0, (%esp)
	call	puts
	jmp	.L1
.L2:
	movl	$.LC1, (%esp)
	call	puts
.L1:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	printStatus, .-printStatus
	.section	.rodata
.LC2:
	.string	"Enter an integer: "
.LC3:
	.string	"Printing the read integer: "
.LC4:
	.string	"\n%d characters printed\n"
.LC5:
	.string	"Enter an float: "
.LC6:
	.string	"\ti = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	movl	%gs:20, %eax
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	movl	$.LC2, (%esp)
	call	prints
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	readi
	movl	%eax, (%esp)
	call	printStatus
	movl	$.LC3, (%esp)
	call	prints
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	call	printi
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	$.LC5, (%esp)
	call	prints
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	readf
	movl	%eax, (%esp)
	call	printStatus
	movl	$.LC3, (%esp)
	call	prints
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	printd
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	$1684234849, 34(%esp)
	movl	$6776421, 38(%esp)
	movw	$0, 42(%esp)
	leal	34(%esp), %eax
	movl	%eax, (%esp)
	call	prints
	movl	%eax, 20(%esp)
	movl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	movl	$0, %eax
	movl	44(%esp), %edx
	xorl	%gs:20, %edx
	je	.L6
	call	__stack_chk_fail
.L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
