	.file	"myl.c"
	.text
	.globl	printi
	.type	printi, @function
printi:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movb	$48, -54(%ebp)
	movl	$0, -52(%ebp)
	cmpl	$0, 8(%ebp)
	jne	.L2
	movl	-52(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -52(%ebp)
	movzbl	-54(%ebp), %edx
	movb	%dl, -32(%ebp,%eax)
	jmp	.L3
.L2:
	cmpl	$0, 8(%ebp)
	jns	.L4
	movl	-52(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -52(%ebp)
	movb	$45, -32(%ebp,%eax)
	negl	8(%ebp)
	jmp	.L5
.L4:
	jmp	.L5
.L6:
	movl	8(%ebp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -40(%ebp)
	movl	-52(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -52(%ebp)
	movl	-40(%ebp), %edx
	movl	%edx, %ecx
	movzbl	-54(%ebp), %edx
	addl	%ecx, %edx
	movb	%dl, -32(%ebp,%eax)
	movl	8(%ebp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 8(%ebp)
.L5:
	cmpl	$0, 8(%ebp)
	jne	.L6
	movzbl	-32(%ebp), %eax
	cmpb	$45, %al
	jne	.L7
	movl	$1, -48(%ebp)
	jmp	.L8
.L7:
	movl	$0, -48(%ebp)
.L8:
	movl	-52(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -44(%ebp)
	jmp	.L9
.L10:
	leal	-32(%ebp), %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -53(%ebp)
	movl	-48(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -48(%ebp)
	leal	-32(%ebp), %ecx
	movl	-44(%ebp), %edx
	addl	%ecx, %edx
	movzbl	(%edx), %edx
	movb	%dl, -32(%ebp,%eax)
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -44(%ebp)
	movzbl	-53(%ebp), %edx
	movb	%dl, -32(%ebp,%eax)
.L9:
	movl	-48(%ebp), %eax
	cmpl	-44(%ebp), %eax
	jl	.L10
.L3:
	movl	-52(%ebp), %eax
	movl	%eax, -36(%ebp)
	leal	-32(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%eax, %ecx
#APP
# 27 "myl.c" 1
	movl $4, %eax 
	movl $1, %ebx 
	int $128 
	
# 0 "" 2
#NO_APP
	movl	-36(%ebp), %eax
	movl	-12(%ebp), %ebx
	xorl	%gs:20, %ebx
	je	.L12
	call	__stack_chk_fail
.L12:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	printi, .-printi
	.globl	prints
	.type	prints, @function
prints:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -8(%ebp)
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	.L14
	jmp	.L15
.L16:
	addl	$1, -8(%ebp)
.L15:
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L16
.L14:
	movl	-8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%eax, %ecx
#APP
# 41 "myl.c" 1
	movl $4, %eax 
	movl $1, %ebx 
	int $128 
	
# 0 "" 2
#NO_APP
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	prints, .-prints
	.globl	readi
	.type	readi, @function
readi:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	movl	$0, -16(%ebp)
	movl	$48, -4(%ebp)
	movl	$0, -12(%ebp)
	movl	$1, -8(%ebp)
	movb	$0, -17(%ebp)
.L25:
	leal	-17(%ebp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
#APP
# 55 "myl.c" 1
	movl $3, %eax 
	movl $0, %ebx 
	int $128 
	
# 0 "" 2
#NO_APP
	cmpl	$0, -12(%ebp)
	jne	.L19
	movzbl	-17(%ebp), %eax
	cmpb	$45, %al
	jne	.L19
	movl	$-1, -8(%ebp)
	jmp	.L20
.L19:
	movzbl	-17(%ebp), %eax
	cmpb	$10, %al
	jne	.L21
	jmp	.L27
.L21:
	movzbl	-17(%ebp), %eax
	cmpb	$57, %al
	jg	.L23
	movzbl	-17(%ebp), %eax
	cmpb	$47, %al
	jg	.L24
.L23:
	movl	8(%ebp), %eax
	movl	$1, (%eax)
.L24:
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movzbl	-17(%ebp), %eax
	movsbl	%al, %eax
	subl	-4(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -16(%ebp)
.L20:
	addl	$1, -12(%ebp)
	jmp	.L25
.L27:
	movl	-16(%ebp), %eax
	imull	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	readi, .-readi
	.globl	printd
	.type	printd, @function
printd:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	flds	8(%ebp)
	fnstcw	-26(%ebp)
	movzwl	-26(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -28(%ebp)
	fldcw	-28(%ebp)
	fistpl	-16(%ebp)
	fldcw	-26(%ebp)
	movl	$1, -20(%ebp)
	fldz
	flds	8(%ebp)
	fxch	%st(1)
	fucomip	%st(1), %st
	fstp	%st(0)
	jbe	.L29
	movl	$-1, -20(%ebp)
.L29:
	movl	$0, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	printi
	addl	%eax, -12(%ebp)
	movw	$46, -22(%ebp)
	leal	-22(%ebp), %eax
	movl	%eax, (%esp)
	call	prints
	fildl	-16(%ebp)
	flds	8(%ebp)
	fsubp	%st, %st(1)
	fstps	8(%ebp)
	fildl	-20(%ebp)
	flds	8(%ebp)
	fmulp	%st, %st(1)
	fstps	8(%ebp)
	fnstcw	-26(%ebp)
	movzwl	-26(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -28(%ebp)
	jmp	.L31
.L35:
	fstp	%st(0)
.L32:
	flds	8(%ebp)
	flds	.LC1
	fmulp	%st, %st(1)
	fstps	8(%ebp)
.L31:
	flds	8(%ebp)
	fldcw	-28(%ebp)
	fistpl	-32(%ebp)
	fldcw	-26(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -32(%ebp)
	fildl	-32(%ebp)
	flds	8(%ebp)
	fsubp	%st, %st(1)
	fldz
	fucomip	%st(1), %st
	jp	.L35
	fldz
	fucomip	%st(1), %st
	fstp	%st(0)
	jne	.L32
	flds	8(%ebp)
	fldcw	-28(%ebp)
	fistpl	-32(%ebp)
	fldcw	-26(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	printi
	addl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	printd, .-printd
	.globl	readf
	.type	readf, @function
readf:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$44, %esp
	movl	$0, -20(%ebp)
	movl	$0, -24(%ebp)
	movl	$48, -4(%ebp)
	movl	$0, -16(%ebp)
	movl	$1, -12(%ebp)
	movb	$0, -25(%ebp)
.L46:
	leal	-25(%ebp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
#APP
# 95 "myl.c" 1
	movl $3, %eax 
	movl $0, %ebx 
	int $128 
	
# 0 "" 2
#NO_APP
	cmpl	$0, -16(%ebp)
	jne	.L37
	movzbl	-25(%ebp), %eax
	cmpb	$45, %al
	jne	.L37
	movl	$-1, -12(%ebp)
	jmp	.L38
.L37:
	movzbl	-25(%ebp), %eax
	cmpb	$46, %al
	jne	.L39
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	readi
	testl	%eax, %eax
	je	.L40
	movl	$1, %eax
	jmp	.L49
.L40:
	jmp	.L42
.L39:
	movzbl	-25(%ebp), %eax
	cmpb	$10, %al
	jne	.L43
	jmp	.L42
.L43:
	movzbl	-25(%ebp), %eax
	cmpb	$57, %al
	jg	.L44
	movzbl	-25(%ebp), %eax
	cmpb	$47, %al
	jg	.L45
.L44:
	movl	$1, %eax
	jmp	.L49
.L45:
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movzbl	-25(%ebp), %eax
	movsbl	%al, %eax
	subl	-4(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
.L38:
	addl	$1, -16(%ebp)
	jmp	.L46
.L42:
	movl	-24(%ebp), %eax
	movl	%eax, -40(%ebp)
	fildl	-40(%ebp)
	fstps	-8(%ebp)
	fnstcw	-34(%ebp)
	movzwl	-34(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -36(%ebp)
	jmp	.L47
.L48:
	flds	-8(%ebp)
	flds	.LC1
	fdivrp	%st, %st(1)
	fstps	-8(%ebp)
.L47:
	flds	-8(%ebp)
	fldcw	-36(%ebp)
	fistpl	-40(%ebp)
	fldcw	-34(%ebp)
	movl	-40(%ebp), %eax
	testl	%eax, %eax
	jne	.L48
	fildl	-20(%ebp)
	flds	-8(%ebp)
	faddp	%st, %st(1)
	fstps	-8(%ebp)
	fildl	-12(%ebp)
	flds	-8(%ebp)
	fmulp	%st, %st(1)
	fstps	-8(%ebp)
	movl	8(%ebp), %edx
	movl	-8(%ebp), %eax
	movl	%eax, (%edx)
	movl	$0, %eax
.L49:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	readf, .-readf
	.section	.rodata
	.align 4
.LC1:
	.long	1092616192
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
