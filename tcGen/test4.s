	.file	"test.c"
	.comm	a,4,4
	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	1
	.globl	t00
	.data
	.align 4
	.type	t00, @object
	.size	t00, 4
t00:
	.long	1
	.comm	c,1,1
	.globl	d
	.type	d, @object
	.size	d, 1
d:
	.byte	0
	.globl	t01
	.type	t01, @object
	.size	t01, 1
t01:
	.byte	0
	.section	.rodata
.LC0:
	.string	"got into function\n"
.LC1:
	.string	"returning from function\n"
.LC2:
	.string	"Enter two numbers to find their sum using a function call\n"
.LC3:
	.string	"Sum is equal to "
.LC4:
	.string	"\n"
	.text	
	movl	$1, %eax
	movl 	%eax, 0(%ebp)
	movl	0(%ebp), %eax
	movl 	%eax, 0(%ebp)
	movb	$97, 0(%ebp)
	movl	0(%ebp), %eax
	movl 	%eax, 0(%ebp)
	.globl	add
	.type	add, @function
add: 
.LFB0:
	.cfi_startproc
	pushl 	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl 	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$192, %esp
	movl	$2, %eax
	movl 	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl 	%eax, -8(%ebp)
	movl	$10, %eax
	movl 	%eax, -60(%ebp)
	movl 	$.LC0, -72(%ebp)
	movl 	-72(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -76(%ebp)
	movl 	8(%ebp), %eax
	movl 	12(%ebp), %edx
	addl 	%edx, %eax
	movl 	%eax, -84(%ebp)
	movl	-84(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	$2, %eax
	movl 	%eax, -92(%ebp)
	movl	-92(%ebp), %eax
	movl 	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jge .L2
	jmp .L3
	jmp .L4
.L2: 
	movl	8(%ebp), %eax
	movl 	%eax, -104(%ebp)
	addl 	$1, 8(%ebp)
	jmp .L4
.L3: 
	movl 	8(%ebp), %eax
	movl 	12(%ebp), %edx
	addl 	%edx, %eax
	movl 	%eax, -112(%ebp)
	movl	-112(%ebp), %eax
	movl 	%eax, -8(%ebp)
.L4: 
	leal	-8(%ebp), %eax
	movl 	%eax, -120(%ebp)
	movl	-120(%ebp), %eax
	movl 	%eax, -64(%ebp)
	movl	-64(%ebp), %eax
	movl	(%eax),%eax
	movl 	%eax, -128(%ebp)
	movl	-128(%ebp), %eax
	movl 	%eax, 12(%ebp)
	movl	8(%ebp), %eax
	movl 	%eax, -136(%ebp)
	addl 	$1, 8(%ebp)
	movl	-64(%ebp), %eax
	movl	(%eax),%eax
	movl 	%eax, -140(%ebp)
	movl	-64(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	negl	8(%ebp)
	movl	-144(%ebp), %eax
	movl 	%eax, 8(%ebp)
	movl	$2, %eax
	movl 	%eax, -152(%ebp)
	movl 	-152(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -156(%ebp)
	movl	-156(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, -20(%ebp,%eax,1)
	movl	$8, %eax
	movl 	%eax, -164(%ebp)
	movl 	-164(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -168(%ebp)
	movl	-168(%ebp), %eax
	movl	-20(%ebp,%eax,1), %eax
	movl 	%eax, -172(%ebp)
	movl	-172(%ebp), %eax
	movl 	%eax, 8(%ebp)
	movl 	$.LC1, -180(%ebp)
	movl 	-180(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -184(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.globl	main
	.type	main, @function
main: 
.LFB1:
	.cfi_startproc
	pushl 	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl 	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$188, %esp
	movl	$2, %eax
	movl 	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl 	%eax, -4(%ebp)
	movl	$10, %eax
	movl 	%eax, -56(%ebp)
	movl 	$.LC2, -84(%ebp)
	movl 	-84(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -88(%ebp)
	leal	-76(%ebp), %eax
	movl 	%eax, -96(%ebp)
	movl 	-96(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	readi
	movl	%eax, -100(%ebp)
	movl	-100(%ebp), %eax
	movl 	%eax, -64(%ebp)
	leal	-76(%ebp), %eax
	movl 	%eax, -108(%ebp)
	movl 	-108(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	readi
	movl	%eax, -112(%ebp)
	movl	-112(%ebp), %eax
	movl 	%eax, -68(%ebp)
	movl 	-64(%ebp), %eax
	movl 	%eax, 0(%esp)
	movl 	-68(%ebp), %eax
	movl 	%eax, 4(%esp)
	call	add
	movl	%eax, -124(%ebp)
	movl	-124(%ebp), %eax
	movl 	%eax, -72(%ebp)
	movl 	$.LC3, -132(%ebp)
	movl 	-132(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -136(%ebp)
	movl 	-72(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	printi
	movl	%eax, -144(%ebp)
	movl 	$.LC4, -148(%ebp)
	movl 	-148(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -152(%ebp)
	movl 	-12(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -156(%ebp)
	movl	-156(%ebp), %eax
	movl	-160(%ebp), %edx
	movl	%edx, -16(%ebp,%eax,1)
	movl	$2, %eax
	movl 	%eax, -168(%ebp)
	movl 	-168(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -172(%ebp)
	movl	-172(%ebp), %eax
	movl	-160(%ebp), %edx
	movl	%edx, -16(%ebp,%eax,1)
	movl 	-4(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -180(%ebp)
	movl	-180(%ebp), %eax
	movl	-16(%ebp,%eax,1), %eax
	movl 	%eax, -184(%ebp)
	movl	-184(%ebp), %eax
	movl 	%eax, -160(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident		"Compiled by Aseem Patni"
	.section	.note.GNU-stack,"",@progbits
