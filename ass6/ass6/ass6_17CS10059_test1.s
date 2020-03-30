	.file	"ass6_17CS10059_test1.c"
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
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$11, -80(%rbp)
	movl	-80(%rbp), %eax
	addl	$2, %eax
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -76(%rbp)
	movl	$3, -72(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -68(%rbp)
	movl	$1, -64(%rbp)
	movl	$7, -60(%rbp)
	movl	$949, -56(%rbp)
	movl	$7, -52(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1088212173
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
