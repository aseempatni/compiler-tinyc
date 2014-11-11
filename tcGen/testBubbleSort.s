	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"Enter number of elements\n"
.LC1:
	.string	"Enter "
.LC2:
	.string	" integers\n"
.LC3:
	.string	"Sorted list in ascending order:\n"
.LC4:
	.string	"\n"
.LC5:
	.string	"Done.\n"
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
	subl	$720, %esp
	movl	$100, %eax
	movl 	%eax, -404(%ebp)
	movl 	$.LC0, -432(%ebp)
	movl 	-432(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -436(%ebp)
	leal	-424(%ebp), %eax
	movl 	%eax, -444(%ebp)
	movl 	-444(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	readi
	movl	%eax, -448(%ebp)
	movl	-448(%ebp), %eax
	movl 	%eax, -408(%ebp)
	movl 	$.LC1, -456(%ebp)
	movl 	-456(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -460(%ebp)
	movl 	-408(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	printi
	movl	%eax, -468(%ebp)
	movl 	$.LC2, -472(%ebp)
	movl 	-472(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -476(%ebp)
	movl	$1, %eax
	movl 	%eax, -480(%ebp)
	movl	-480(%ebp), %eax
	movl 	%eax, -412(%ebp)
.L2: 
	movl	-412(%ebp), %eax
	cmpl	-408(%ebp), %eax
	jle .L4
	jmp .L5
.L3: 
	movl	-412(%ebp), %eax
	movl 	%eax, -492(%ebp)
	addl 	$1, -412(%ebp)
	jmp .L2
.L4: 
	movl	$1, %eax
	movl 	%eax, -496(%ebp)
	movl 	-412(%ebp), %eax
	movl 	-496(%ebp), %edx
	subl 	%edx, %eax
	movl 	%eax, -504(%ebp)
	movl 	-504(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -508(%ebp)
	leal	-424(%ebp), %eax
	movl 	%eax, -512(%ebp)
	movl 	-512(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	readi
	movl	%eax, -516(%ebp)
	movl	-508(%ebp), %eax
	movl	-516(%ebp), %edx
	movl	%edx, -4(%ebp,%eax,1)
	jmp .L3
.L5: 
	movl	$1, %eax
	movl 	%eax, -524(%ebp)
	movl	-524(%ebp), %eax
	movl 	%eax, -412(%ebp)
.L6: 
	movl	-412(%ebp), %eax
	cmpl	-408(%ebp), %eax
	jl .L8
	jmp .L14
.L7: 
	movl	-412(%ebp), %eax
	movl 	%eax, -536(%ebp)
	addl 	$1, -412(%ebp)
	jmp .L6
.L8: 
	movl	$1, %eax
	movl 	%eax, -540(%ebp)
	movl	-540(%ebp), %eax
	movl 	%eax, -416(%ebp)
.L9: 
	movl 	-408(%ebp), %eax
	movl 	-412(%ebp), %edx
	subl 	%edx, %eax
	movl 	%eax, -552(%ebp)
	movl	-416(%ebp), %eax
	cmpl	-552(%ebp), %eax
	jle .L11
	jmp .L7
.L10: 
	movl	-416(%ebp), %eax
	movl 	%eax, -560(%ebp)
	addl 	$1, -416(%ebp)
	jmp .L9
.L11: 
	movl	$1, %eax
	movl 	%eax, -564(%ebp)
	movl 	-416(%ebp), %eax
	movl 	-564(%ebp), %edx
	subl 	%edx, %eax
	movl 	%eax, -572(%ebp)
	movl 	-572(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -576(%ebp)
	movl	-576(%ebp), %eax
	movl	-4(%ebp,%eax,1), %eax
	movl 	%eax, -580(%ebp)
	movl 	-416(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -584(%ebp)
	movl	-584(%ebp), %eax
	movl	-4(%ebp,%eax,1), %eax
	movl 	%eax, -588(%ebp)
	movl	-580(%ebp), %eax
	cmpl	-588(%ebp), %eax
	jg .L12
	jmp .L10
	jmp .L13
.L12: 
	movl	$1, %eax
	movl 	%eax, -596(%ebp)
	movl 	-416(%ebp), %eax
	movl 	-596(%ebp), %edx
	subl 	%edx, %eax
	movl 	%eax, -604(%ebp)
	movl 	-604(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -608(%ebp)
	movl	-608(%ebp), %eax
	movl	-4(%ebp,%eax,1), %eax
	movl 	%eax, -612(%ebp)
	movl	-612(%ebp), %eax
	movl 	%eax, -420(%ebp)
	movl	$1, %eax
	movl 	%eax, -620(%ebp)
	movl 	-416(%ebp), %eax
	movl 	-620(%ebp), %edx
	subl 	%edx, %eax
	movl 	%eax, -628(%ebp)
	movl 	-628(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -632(%ebp)
	movl 	-416(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -636(%ebp)
	movl	-636(%ebp), %eax
	movl	-4(%ebp,%eax,1), %eax
	movl 	%eax, -640(%ebp)
	movl	-632(%ebp), %eax
	movl	-640(%ebp), %edx
	movl	%edx, -4(%ebp,%eax,1)
	movl 	-416(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -648(%ebp)
	movl	-648(%ebp), %eax
	movl	-420(%ebp), %edx
	movl	%edx, -4(%ebp,%eax,1)
	jmp .L10
.L13: 
	jmp .L10
	jmp .L7
.L14: 
	movl 	$.LC3, -656(%ebp)
	movl 	-656(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -660(%ebp)
	movl	$1, %eax
	movl 	%eax, -664(%ebp)
	movl	-664(%ebp), %eax
	movl 	%eax, -412(%ebp)
.L15: 
	movl	-412(%ebp), %eax
	cmpl	-408(%ebp), %eax
	jle .L17
	jmp .L18
.L16: 
	movl	-412(%ebp), %eax
	movl 	%eax, -676(%ebp)
	addl 	$1, -412(%ebp)
	jmp .L15
.L17: 
	movl	$1, %eax
	movl 	%eax, -680(%ebp)
	movl 	-412(%ebp), %eax
	movl 	-680(%ebp), %edx
	subl 	%edx, %eax
	movl 	%eax, -688(%ebp)
	movl 	-688(%ebp), %eax
	imull 	$4, %eax
	movl 	%eax, -692(%ebp)
	movl	-692(%ebp), %eax
	movl	-4(%ebp,%eax,1), %eax
	movl 	%eax, -696(%ebp)
	movl 	-696(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	printi
	movl	%eax, -700(%ebp)
	movl 	$.LC4, -704(%ebp)
	movl 	-704(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -708(%ebp)
	jmp .L16
.L18: 
	movl 	$.LC5, -712(%ebp)
	movl 	-712(%ebp), %eax
	movl 	%eax, 0(%esp)
	call	prints
	movl	%eax, -716(%ebp)
	movl	$0, %eax
	movl 	%eax, -720(%ebp)
	movl	-720(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident		"Compiled by Aseem Patni"
	.section	.note.GNU-stack,"",@progbits
