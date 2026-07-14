	.file	"conversions.c"
	.text
	.section	.rodata
.LC0:
	.string	"=== int vs double ===\n"
.LC1:
	.string	"7 / 2     = %d\n"
.LC2:
	.string	"7 %% 2     = %d\n"
.LC4:
	.string	"7 / 2.0   = %f\n"
.LC5:
	.string	"7.0 / 2   = %f\n"
.LC6:
	.string	"\n=== Signed + unsigned ===\n"
.LC7:
	.string	"u = 10, s = -20"
.LC8:
	.string	"u + s (how %%d) = %d\n"
.LC9:
	.string	"u + s (how %%u) = %u\n"
.LC10:
	.string	"\n=== signed vs unsigned ===\n"
	.align 8
.LC11:
	.string	"-1 > 1 es True (implicit conversion)"
.LC12:
	.string	"-1 > 1 es False"
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
	leaq	.LC1(%rip), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC2(%rip), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	.LC3(%rip), %rax
	leaq	.LC4(%rip), %rdx
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	movl	$1, %eax
	call	printf@PLT
	movq	.LC3(%rip), %rax
	leaq	.LC5(%rip), %rdx
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$10, -16(%rbp)
	movl	$-20, -12(%rbp)
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	leaq	.LC8(%rip), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	leaq	.LC9(%rip), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$-1, -8(%rbp)
	movl	$1, -4(%rbp)
	movl	-8(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jnb	.L2
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L3:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC3:
	.long	0
	.long	1074528256
	.ident	"GCC: (GNU) 16.1.1 20260430"
	.section	.note.GNU-stack,"",@progbits
