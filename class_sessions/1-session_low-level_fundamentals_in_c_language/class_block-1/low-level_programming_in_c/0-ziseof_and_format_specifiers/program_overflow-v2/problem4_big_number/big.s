	.file	"big.c"
	.text
	.section	.rodata
.LC0:
	.string	"sum a(100) + b(50)  is = %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movb	$100, -3(%rbp)
	movb	$50, -2(%rbp)
	movzbl	-3(%rbp), %edx
	movzbl	-2(%rbp), %eax
	addl	%edx, %eax
	movb	%al, -1(%rbp)
	movsbl	-1(%rbp), %eax
	leaq	.LC0(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.1.1 20260430"
	.section	.note.GNU-stack,"",@progbits
