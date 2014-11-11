	.file	"test4.c"
	.comm	a,4,4
	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	1
	.comm	c,1,1
	.globl	d
	.type	d, @object
	.size	d, 1
d:
	.byte	97
	.section	.rodata
.LC0:
	.string	"got into function\n"
.LC1:
	.string	"returning from function\n"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$88, %esp
	movl	$2, -64(%ebp)
	movl	$.LC0, (%esp)
	call	prints
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -60(%ebp)
	movl	$2, -56(%ebp)
	movl	8(%ebp), %eax
	cmpl	-56(%ebp), %eax
	jl	.L2
	addl	$1, 8(%ebp)
	jmp	.L3
.L2:
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -64(%ebp)
.L3:
	leal	-64(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 12(%ebp)
	addl	$1, 8(%ebp)
	movl	-52(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	negl	8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%ebp)
	movl	$.LC1, (%esp)
	call	prints
	movl	-60(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.section	.rodata
.LC2:
	.string	"Sum is equal to "
.LC3:
	.string	"\n"
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
	subl	$80, %esp
	movl	$2, 20(%esp)
	leal	16(%esp), %eax
	movl	%eax, (%esp)
	call	readi
	movl	%eax, 24(%esp)
	leal	16(%esp), %eax
	movl	%eax, (%esp)
	call	readi
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	add
	movl	%eax, 32(%esp)
	movl	$.LC2, (%esp)
	call	prints
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	printi
	movl	$.LC3, (%esp)
	call	prints
	movl	a, %edx
	movl	36(%esp), %eax
	movl	%edx, 40(%esp,%eax,4)
	movl	a, %eax
	movl	%eax, 48(%esp)
	movl	20(%esp), %eax
	movl	40(%esp,%eax,4), %eax
	movl	%eax, a
	movl	20(%esp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
