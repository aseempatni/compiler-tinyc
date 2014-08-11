	.file	"ass1.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"Enter the order of the square matrix: "
.LC1:
	.string	"%d"
	.align 4
.LC2:
	.string	"Enter the matrix in row-major order:"
.LC3:
	.string	"The input matrix is:"
.LC4:
	.string	"%d "
.LC5:
	.string	"In cs order:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$1632, %esp
	movl	$.LC0, (%esp)
	call	printf
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, 24(%esp)
	jmp	.L2
.L5:
	movl	$0, 28(%esp)
	jmp	.L3
.L4:
	leal	32(%esp), %ecx
	movl	24(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	28(%esp), %edx
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	__isoc99_scanf
	addl	$1, 28(%esp)
.L3:
	movl	20(%esp), %eax
	cmpl	%eax, 28(%esp)
	jl	.L4
	addl	$1, 24(%esp)
.L2:
	movl	20(%esp), %eax
	cmpl	%eax, 24(%esp)
	jl	.L5
	movl	$.LC3, (%esp)
	call	puts
	movl	$0, 24(%esp)
	jmp	.L6
.L9:
	movl	$0, 28(%esp)
	jmp	.L7
.L8:
	movl	24(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	28(%esp), %edx
	addl	%edx, %eax
	movl	32(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	addl	$1, 28(%esp)
.L7:
	movl	20(%esp), %eax
	cmpl	%eax, 28(%esp)
	jl	.L8
	movl	$10, (%esp)
	call	putchar
	addl	$1, 24(%esp)
.L6:
	movl	20(%esp), %eax
	cmpl	%eax, 24(%esp)
	jl	.L9
	movl	$.LC5, (%esp)
	call	puts
	movl	20(%esp), %eax
	leal	32(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	cs
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC6:
	.string	"%d\n"
	.text
	.globl	cs
	.type	cs, @function
cs:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	.L12
	movl	$10, (%esp)
	call	putchar
	jmp	.L11
.L12:
	cmpl	$1, 8(%ebp)
	jne	.L14
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	jmp	.L11
.L14:
	movl	$0, 12(%esp)
	movl	$1, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	movl	12(%ebp), %eax
	addl	$80, %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	subl	$2, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	cs
.L11:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	cs, .-cs
	.globl	po
	.type	po, @function
po:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	cmpl	$2, %eax
	je	.L17
	cmpl	$2, %eax
	jg	.L18
	cmpl	$1, %eax
	je	.L19
	jmp	.L15
.L18:
	cmpl	$3, %eax
	je	.L20
	cmpl	$4, %eax
	je	.L21
	jmp	.L15
.L19:
	movl	8(%ebp), %eax
	subl	$1, %eax
	cmpl	20(%ebp), %eax
	jne	.L22
	movl	$0, 12(%esp)
	movl	$2, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	jmp	.L15
.L22:
	movl	12(%ebp), %eax
	movl	20(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	20(%ebp), %eax
	addl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	jmp	.L15
.L17:
	movl	8(%ebp), %eax
	subl	$1, %eax
	cmpl	20(%ebp), %eax
	jne	.L24
	movl	8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$3, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	jmp	.L15
.L24:
	movl	20(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$4, %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	8(%ebp), %edx
	subl	$1, %edx
	movl	(%eax,%edx,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	20(%ebp), %eax
	addl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$2, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	jmp	.L15
.L20:
	cmpl	$0, 20(%ebp)
	jne	.L26
	movl	8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$4, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	jmp	.L15
.L26:
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	-80(%eax), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	20(%ebp), %eax
	movl	(%edx,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	20(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$3, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	jmp	.L15
.L21:
	cmpl	$0, 20(%ebp)
	jne	.L28
	jmp	.L15
.L28:
	movl	20(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$4, %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	20(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 12(%esp)
	movl	$4, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	po
	nop
.L15:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	po, .-po
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
