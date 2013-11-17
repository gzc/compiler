	.file	"sort.c"
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
	pushl	%ebx
	subl	$112, %esp
	.cfi_offset 3, -12
	movl	$0, -112(%ebp)
	jmp	.L2
.L3:
	movl	$9, %eax
	movl	%eax, %edx
	subl	-112(%ebp), %edx
	movl	-112(%ebp), %eax
	movl	%edx, -76(%ebp,%eax,4)
	addl	$1, -112(%ebp)
.L2:
	cmpl	$8, -112(%ebp)
	jle	.L3
	movl	$0, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	$0, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	$8, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	jmp	.L4
.L13:
	subl	$1, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	-40(%ebp,%eax,4), %eax
	movl	%eax, -100(%ebp)
	subl	$1, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	-40(%ebp,%eax,4), %eax
	movl	%eax, -96(%ebp)
	movl	-100(%ebp), %eax
	negl	%eax
	cmpl	-96(%ebp), %eax
	jl	.L15
.L5:
	movl	-96(%ebp), %eax
	movl	-76(%ebp,%eax,4), %eax
	movl	%eax, -92(%ebp)
	movl	-96(%ebp), %eax
	movl	%eax, -88(%ebp)
	movl	-100(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -104(%ebp)
	jmp	.L7
.L9:
	addl	$1, -112(%ebp)
	movl	-112(%ebp), %eax
	movl	-76(%ebp,%eax,4), %eax
	cmpl	-92(%ebp), %eax
	jge	.L10
	movl	-112(%ebp), %eax
	cmpl	-100(%ebp), %eax
	jl	.L9
.L10:
	subl	$1, -104(%ebp)
	movl	-104(%ebp), %eax
	movl	-76(%ebp,%eax,4), %eax
	cmpl	-92(%ebp), %eax
	jg	.L10
	movl	-112(%ebp), %eax
	cmpl	-104(%ebp), %eax
	jge	.L7
	movl	-112(%ebp), %eax
	movl	-76(%ebp,%eax,4), %eax
	movl	%eax, -84(%ebp)
	movl	-104(%ebp), %eax
	movl	-76(%ebp,%eax,4), %edx
	movl	-112(%ebp), %eax
	movl	%edx, -76(%ebp,%eax,4)
	movl	-104(%ebp), %eax
	movl	-84(%ebp), %edx
	movl	%edx, -76(%ebp,%eax,4)
.L7:
	movl	-112(%ebp), %eax
	cmpl	-104(%ebp), %eax
	jl	.L9
	movl	-104(%ebp), %eax
	movl	-76(%ebp,%eax,4), %edx
	movl	-96(%ebp), %eax
	movl	%edx, -76(%ebp,%eax,4)
	movl	-104(%ebp), %eax
	movl	-92(%ebp), %edx
	movl	%edx, -76(%ebp,%eax,4)
	movl	-104(%ebp), %eax
	movl	%eax, -80(%ebp)
	movl	-96(%ebp), %eax
	movl	-80(%ebp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	-80(%ebp), %eax
	movl	-100(%ebp), %edx
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	cmpl	%eax, %ecx
	jle	.L12
	movl	-108(%ebp), %eax
	movl	-96(%ebp), %edx
	movl	%edx, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	movl	-80(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-108(%ebp), %eax
	movl	%edx, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	movl	-100(%ebp), %eax
	cmpl	-80(%ebp), %eax
	jle	.L4
	movl	-80(%ebp), %eax
	leal	1(%eax), %edx
	movl	-108(%ebp), %eax
	movl	%edx, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	-100(%ebp), %edx
	movl	%edx, -76(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	jmp	.L4
.L12:
	movl	-80(%ebp), %eax
	leal	1(%eax), %edx
	movl	-108(%ebp), %eax
	movl	%edx, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	-100(%ebp), %edx
	movl	%edx, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	movl	-80(%ebp), %eax
	cmpl	-96(%ebp), %eax
	jle	.L4
	movl	-108(%ebp), %eax
	movl	-96(%ebp), %edx
	movl	%edx, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
	movl	-80(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-108(%ebp), %eax
	movl	%edx, -40(%ebp,%eax,4)
	addl	$1, -108(%ebp)
.L4:
	cmpl	$0, -108(%ebp)
	jg	.L13
	jmp	.L14
.L15:
	nop
.L14:
	addl	$112, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
