	.file	"unsigned_260.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"\n Something similar to problem 1 would happen: the value doesn't fit, but since it's a unsigned value with a range of 0 to 255, the binary sum results in a value lower than expected. "
	.align 8
.LC1:
	.string	"unsigned char z = x (250) + y (10),the result of z = %u"
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
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movb	$-6, -3(%rbp)
	movb	$10, -2(%rbp)
	movzbl	-3(%rbp), %edx
	movzbl	-2(%rbp), %eax
	addl	%edx, %eax
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	leaq	.LC1(%rip), %rdx
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
