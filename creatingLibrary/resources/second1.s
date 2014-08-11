	.file	"second1.c"
	.section	.rodata
.LC0:
	.string	"My second program\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$.LC0, 28(%esp)
	movl	$19, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	call	write
	movl	$0, (%esp)
	call	_exit
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
