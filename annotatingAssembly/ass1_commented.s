	.file	"ass1.c"		# source file name
	.section	.rodata		# read only data section
	.align 4				# align with 4-byte boundary
.LC0:						# Label of string - 1st printf
	.string	"Enter the order of the square matrix: "
.LC1:						# Label of string - 1st scanf
	.string	"%d"
	.align 4 				# align with 4 byte boundary
.LC2:						# label of string - 2nd printf
	.string	"Enter the matrix in row-major order:"
.LC3:						# label of string - 3rd printf
	.string	"The input matrix is:"
.LC4:						# label of string - 2nd scanf
	.string	"%d "
.LC5:						# label of string - 4th printf
	.string	"In cs order:"
	.text					# Code starts
	.globl	main			# main is a global name
	.type	main, @function	
main:						# Label main:
.LFB0:	 					# First function
	.cfi_startproc
	pushl	%ebp 				# Save old base pointer
	.cfi_def_cfa_offset 8 		# offset of 8 bytes
	.cfi_offset 5, -8
	movl	%esp, %ebp			# ebp <-- esp, set new base pointer
	.cfi_def_cfa_register 5 	# Call frame address in register 5
	andl	$-16, %esp			# Adjust to 16-byte boundary
	subl	$1632, %esp			# Create space for the local matrix
	movl	$.LC0, (%esp)		# Push the first parameter
	call	printf				# Calls printf
	leal	20(%esp), %eax		# eax <-- n
	movl	%eax, 4(%esp)		# n
	movl	$.LC1, (%esp)		# Push the second parameter
	call	__isoc99_scanf		# Call scanf
	movl	$.LC2, (%esp)		# Push the third parameter
	call	puts				# Calls puts() to print \n
	movl	$0, 24(%esp) 		# i <-- 0
	jmp	.L2 					# goto label .L2
.L5:
	movl	$0, 28(%esp) 		# j <-- 0
	jmp	.L3 					# goto .L3
.L4:
	leal	32(%esp), %ecx		# ecx <-- data
	movl	24(%esp), %edx		# edx <-- i
	movl	%edx, %eax 			# eax <-- edx
	sall	$2, %eax 			# eax <-- eax << 2 4*i
	addl	%edx, %eax 			# eax <-- eax + edx 5*i
	sall	$2, %eax 			# eax <-- eax << 2 20*i
	movl	28(%esp), %edx 		# edx <-- j
	addl	%edx, %eax 			# eax <-- eax + edx 20*i+j
	sall	$2, %eax 			# eax <-- eax << 2
	addl	%ecx, %eax			# eax <-- eax + ecx
	movl	%eax, 4(%esp) 		# Push the second parameter data [i][j]
	movl	$.LC1, (%esp) 		# scan for input
	call	__isoc99_scanf 		# Calls scanf
	addl	$1, 28(%esp) 		# j <-- j+1
.L3:
	movl	20(%esp), %eax		# eax = esp+20 n
	cmpl	%eax, 28(%esp) 		# if j<n
	jl	.L4 					# goto .L4
	addl	$1, 24(%esp) 		# i <-- i+1
.L2:
	movl	20(%esp), %eax 		# eax <-- n
	cmpl	%eax, 24(%esp) 		# if i<n
	jl	.L5 					# goto .L5
	movl	$.LC3, (%esp) 		# Push the string "The input matrix is"
	call	puts				# Calls puts() to print
	movl	$0, 24(%esp) 		# i <-- 0
	jmp	.L6 					# goto .L6
.L9:
	movl	$0, 28(%esp) 		# j <-- 0
	jmp	.L7 					# goto .L7
.L8:
	movl	24(%esp), %edx 		# edx <-- i
	movl	%edx, %eax			# eax <-- i
	sall	$2, %eax			# eax <-- 4*i
	addl	%edx, %eax 			# eax <-- 5*i
	sall	$2, %eax 			# eax <-- 20*i
	movl	28(%esp), %edx 		# edx <-- j
	addl	%edx, %eax 			# eax <-- eax + j
	movl	32(%esp,%eax,4), %eax  	# eax <-- esp + 32 + 4*eax
	movl	%eax, 4(%esp) 		# Push the second parameter data [i][j]
	movl	$.LC4, (%esp) 		# loads value to print
	call	printf				# Calls printf
	addl	$1, 28(%esp) 		# j <-- j+1
.L7:
	movl	20(%esp), %eax 		# eax <-- n
	cmpl	%eax, 28(%esp) 		# if j<n
	jl	.L8 					# goto .L8
	movl	$10, (%esp) 		# esp <-- '\n'
	call	putchar 			# Put a newline char
	addl	$1, 24(%esp) 		# i <-- i+1
.L6:
	movl	20(%esp), %eax 		# eax <--n
	cmpl	%eax, 24(%esp) 		# if i<n
	jl	.L9 					# goto .L9
	movl	$.LC5, (%esp) 		# Push the first parameter
	call	puts				# Calls puts() to print
	movl	20(%esp), %eax 		# eax <-- n
	leal	32(%esp), %edx 		# edx <-- esp + 32 (data)
	movl	%edx, 4(%esp) 		# Push the second parameter data
	movl	%eax, (%esp) 		# Push the first parameter n
	call	cs 					# Call function cs
	movl	$0, %eax 			# eax <-- 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC6:
	.string	"%d\n" 				# Label of string 
	.text
	.globl	cs
	.type	cs, @function
cs: 							# function cs
.LFB1:							# Second function
	.cfi_startproc 				# Call Frame Information
	pushl	%ebp 				# save old base pointer
	.cfi_def_cfa_offset 8 		# ooffset of 8
	.cfi_offset 5, -8 			
	movl	%esp, %ebp 			# ebp <-- esp
	.cfi_def_cfa_register 5		# Call frame address in register 5
	subl	$24, %esp 			# Create 24 byte stack frame
	cmpl	$0, 8(%ebp) 		# if n!=0
	jne	.L12 					# goto .L12
	movl	$10, (%esp) 		# otherwise put a '\n'
	call	putchar 			# Call putchar
	jmp	.L11 					# goto .L11 exit
.L12:
	cmpl	$1, 8(%ebp) 		# if n!=2
	jne	.L14 					# goto .L14
	movl	12(%ebp), %eax 		# eax <-- ebp +12 
	movl	(%eax), %eax 		# data [0][0]
	movl	%eax, 4(%esp)		# Push parameter 2 eax
	movl	$.LC6, (%esp)		# Push parameter 1
	call	printf				# Calls printf
	jmp	.L11					# goto .L11 exit
.L14:
	movl	$0, 12(%esp) 		# 4th parameter <-- 0
	movl	$1, 8(%esp) 		# third parameter <-- 1
	movl	12(%ebp), %eax 		# eax <-- data
	movl	%eax, 4(%esp) 		# second parameter <-- eax
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp) 		# first parameter <-- n
	call	po 					# Call po
	movl	12(%ebp), %eax 		# eax <-- data[0][0]
	addl	$80, %eax			# eax <-- data[1][0]
	leal	4(%eax), %edx 		# edx <-- data[1][1]
	movl	8(%ebp), %eax 		# eax <-- n
	subl	$2, %eax 			# eax <-- n-2
	movl	%edx, 4(%esp) 		# second parameter <-- edx
	movl	%eax, (%esp) 		# first parameter <-- n-2
	call	cs 					# call cs
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
po: 							# Function po
.LFB2: 							# Third function
	.cfi_startproc 				# Start of function
	pushl	%ebp 				# Save old base pointer
	.cfi_def_cfa_offset 8 		# set offset to 8
	.cfi_offset 5, -8
	movl	%esp, %ebp 			# ebp <-- esp, new base pointer
	.cfi_def_cfa_register 5 	# Call frame address in register 5
	subl	$24, %esp 			# Create 24 byte stack frame
	movl	16(%ebp), %eax 		# eax <-- type
	cmpl	$2, %eax 			# if type == 2
	je	.L17 					# goto .L17
	cmpl	$2, %eax 			# if type > 2
	jg	.L18					# goto .L18
	cmpl	$1, %eax 			# if type ==1
	je	.L19 					# goto .L19
	jmp	.L15 					# goto .L15 exit if matches with nothing
.L18:
	cmpl	$3, %eax 			# if type == 3
	je	.L20 					# goto .L20
	cmpl	$4, %eax 			# if type ==4
	je	.L21 					# goto .L21
	jmp	.L15					# goto .L15 exit if matches with nothing
.L19:
	movl	8(%ebp), %eax 		# eax <-- n
	subl	$1, %eax 			# eax <-- n-1
	cmpl	20(%ebp), %eax 		# if n-1 != ind
	jne	.L22 					# goto .L22
	movl	$0, 12(%esp) 		# 4th parameter <-- 0
	movl	$2, 8(%esp) 		# 3rd parameter <-- 2
	movl	12(%ebp), %eax 		# eax <-- data
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp) 		# 1st parameter <-- n
	call	po 					# call po
	jmp	.L15					# goto .L15 exit if matches with nothing
.L22:
	movl	12(%ebp), %eax 		# eax <-- data
	movl	20(%ebp), %edx 		# edx <-- ind
	movl	(%eax,%edx,4), %eax 	# eax <-- data [0][ind]
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data [0][ind]
	movl	$.LC4, (%esp) 		# 1st parameter <-- .LC4
	call	printf				# Calls printf
	movl	20(%ebp), %eax 		# eax <-- ind 
	addl	$1, %eax 			# eax <-- ind + 1
	movl	%eax, 12(%esp) 		# 4th parameter <-- ind + 1
	movl	$1, 8(%esp) 		# 3rd parameter <-- 1
	movl	12(%ebp), %eax 		# eax <-- data
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp) 		# 1st parameter <-- n
	call	po 					# call po
	jmp	.L15					# goto .L15 exit if matches with nothing
.L17:
	movl	8(%ebp), %eax 		# eax <-- n
	subl	$1, %eax 			# eax <-- eax -1, n-1
	cmpl	20(%ebp), %eax		# if n-1 != ind
	jne	.L24 					# goto .L24
	movl	8(%ebp), %eax 		# eax <-- n
	subl	$1, %eax 			# eax <-- n-1
	movl	%eax, 12(%esp) 		# 4th parameter <-- n-1
	movl	$3, 8(%esp) 		# 3rd parameter <-- 3
	movl	12(%ebp), %eax 		# eax <-- data
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp) 		# 1st parameter <-- n
	call	po 					# call po
	jmp	.L15 					# goto .L15 exit if matches with nothing		
.L24:
	movl	20(%ebp), %edx 		# edx <-- ind
	movl	%edx, %eax			# eax <-- ind
	sall	$2, %eax 			# eax <-- 4*ind
	addl	%edx, %eax 			# eax <-- 4*ind
	sall	$4, %eax 			# eax <-- 80*ind
	movl	%eax, %edx 			# edx <-- 80*ind
	movl	12(%ebp), %eax 		# eax <-- data
	addl	%edx, %eax			# eax <-- data [ind][0]
	movl	8(%ebp), %edx 		# edx <-- n
	subl	$1, %edx			# edx <-- n-1
	movl	(%eax,%edx,4), %eax 	# eax <-- data [ind][n-1]
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data [ind][n-1]
	movl	$.LC4, (%esp) 		# 1st parameter <-- .LC4
	call	printf				# Calls printf
	movl	20(%ebp), %eax 		# eax <-- ind
	addl	$1, %eax 			# eax <-- ind + 1
	movl	%eax, 12(%esp) 		# 4th parameter  <-- ind + 1
	movl	$2, 8(%esp) 		# 3rd parameter <-- 2
	movl	12(%ebp), %eax 		# eax <-- data
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp)		# 1st parameter <-- n
	call	po 					# call po
	jmp	.L15					# goto .L15 exit if matches with nothing
.L20:
	cmpl	$0, 20(%ebp) 		# if ind != 0
	jne	.L26 					# goto .L26
	movl	8(%ebp), %eax 		# eax <-- n
	subl	$1, %eax 			# eax <-- n-1
	movl	%eax, 12(%esp) 		# 4th parameter <-- n-1
	movl	$4, 8(%esp) 		# 3rd parameter <-- 4
	movl	12(%ebp), %eax 		# eax <-- data
	movl	%eax, 4(%esp) 		# 2nd parameter <-- eax
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp) 		# 1st parameter <-- n
	call	po 					# call po
	jmp	.L15					# goto .L15 exit if matches with nothing
.L26:
	movl	8(%ebp), %edx 		# edx <-- n
	movl	%edx, %eax 			# eax <-- n
	sall	$2, %eax 			# eax <-- 4*n
	addl	%edx, %eax 			# eax <-- eax + n 5n
	sall	$4, %eax 			# eax <-- 16*eax, 80n
	leal	-80(%eax), %edx 	# edx <-- eax -80
	movl	12(%ebp), %eax 		# eax <-- data
	addl	%eax, %edx 			# edx <-- data [n-1][0]
	movl	20(%ebp), %eax 		#eax <--ind
	movl	(%edx,%eax,4), %eax 	# eax <-- data {n-1}[ind]
	movl	%eax, 4(%esp) 		# second parameter eax
	movl	$.LC4, (%esp) 		# first parameter .LC4
	call	printf				# Calls printf
	movl	20(%ebp), %eax 		# eax <-- ind
	subl	$1, %eax			# eax <-- ind -1
	movl	%eax, 12(%esp) 		# 4 parameter <-- ind -1
	movl	$3, 8(%esp) 		# 3rd parameter <-- 3
	movl	12(%ebp), %eax 		# data <-- n
	movl	%eax, 4(%esp) 		# second parameter <-- data
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp) 		# 1st paramteter <-- n
	call	po 					# call po
	jmp	.L15					# goto .L15 exit if matches with nothing
.L21:
	cmpl	$0, 20(%ebp) 		# if ind != 0
	jne	.L28 					# goto >l28
	jmp	.L15					# goto .L15 exit if matches with nothing
.L28:
	movl	20(%ebp), %edx 		# edx <-- ind
	movl	%edx, %eax 			# eax <-- ind
	sall	$2, %eax 			# eax <-- 4*ind
	addl	%edx, %eax 			# eax <-- 5*ind
	sall	$4, %eax 			# eax <-- eax*16, 80*ind
	movl	%eax, %edx 			# edx <-- 80*ind
	movl	12(%ebp), %eax 		# eax <-- data
	addl	%edx, %eax			# eax <-- datta [ind][0]
	movl	(%eax), %eax 		# eax <-- value of data [ind][0]
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data [ind][0]
	movl	$.LC4, (%esp) 		# first parameter <-- .LC4
	call	printf				# Calls printf
	movl	20(%ebp), %eax 		# eax <-- ind
	subl	$1, %eax 			# eax <-- ind -1
	movl	%eax, 12(%esp) 		# 4th parameter <-- ind -1
	movl	$4, 8(%esp) 		# 3rd parameter <-- 4
	movl	12(%ebp), %eax		# eax <-- data
	movl	%eax, 4(%esp) 		# 2nd parameter <-- data
	movl	8(%ebp), %eax 		# eax <-- n
	movl	%eax, (%esp) 		# 1st parameter <-- n
	call	po 					# call po
	nop 						# No Operation
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
