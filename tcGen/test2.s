	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"abc\n"
.LC1:
	.string	"abcd"
.LC2:
	.string	"Please enter a number: "
.LC3:
	.string	"You Entered "
.LC4:
	.string	"\n"
	.text	
	.globl	main
	.type	main, @function
main: 
.LFB0:
	.cfi_startproc
	pushl 	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl 	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$138, %esp
	movl	$5, %eax
	movl 	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	$2, %eax
	movl 	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl 	%eax, -12(%ebp)
	movb	$120, -25(%ebp)
	movl	-25(%ebp), %eax
	movl 	%eax, -24(%ebp)
	movl 	$.LC0, -30(%ebp)
	movl	-30(%ebp), %eax
	movl 	%eax, -26(%ebp)
	movl 	$.LC1, -42(%ebp)
	movl	-42(%ebp), %eax
	movl 	%eax, -38(%ebp)
	movl	$5, %eax
	movl 	%eax, -54(%ebp)
	movl	-54(%ebp), %eax
	movl 	%eax, -50(%ebp)
	movl	-4(%ebp), %eax
	cmpl	-12(%ebp), %eax
	jl .L2
	jmp .L3
	jmp .L4
.L2: 
	movl	-4(%ebp), %eax
	movl 	%eax, -70(%ebp)
	addl 	$1, -4(%ebp)
	jmp .L4
.L3: 
	movl 	-4(%ebp), %eax
	movl 	-12(%ebp), %edx
	addl 	%edx, %eax
	movl 	%eax, -78(%ebp)
	movl	-78(%ebp), %eax
	movl 	%eax, -20(%ebp)
.L4: 
	movl 	$.LC2, -90(%ebp)
	movl 	-90(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -94(%ebp)
	leal	-62(%ebp), %eax
	movl 	%eax, -102(%ebp)
	movl 	-102(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	readi
	movl	%eax, -106(%ebp)
	movl	-106(%ebp), %eax
	movl 	%eax, -50(%ebp)
	movl 	$.LC3, -114(%ebp)
	movl 	-114(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -118(%ebp)
	movl 	-50(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	printi
	movl	%eax, -126(%ebp)
	movl	-126(%ebp), %eax
	movl 	%eax, -20(%ebp)
	movl 	$.LC4, -134(%ebp)
	movl 	-134(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -138(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by Aseem Patni"
	.section	.note.GNU-stack,"",@progbits
