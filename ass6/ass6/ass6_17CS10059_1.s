	.section	.rodata
  # function printInt start
  # function printStr start
  # function main start
#--loacl var offset: 4 -4
#--loacl var offset: 4 -8
#--loacl var offset: 4 -12
#--loacl var offset: 4 -16
#--loacl var offset: 4 -20
#--loacl var offset: 0 -20
#--loacl var offset: 4 -24
#--loacl var offset: 4 -28
#--loacl var offset: 4 -32
#-32
##ptra
##ptrb
##ptrt0
##ptrprintInt
##ptrt1
##ptrt2
##ptrt3
##ptrt4
##ptrt5
##ptrretVal
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64,	%rsp
  # t0 = 5555
	movl	$5555,	-12(%rbp)
  # a = t0
	movl	-12(%rbp),	%eax
	movl	%eax,	-4(%rbp)
  # param a
	movq	-4(%rbp),	%rdi
  # call printInt 1
	call	printInt
  # t1 = 10
.L2:
	movl	$10,	-20(%rbp)
  # if a > t1 goto .L0
	movl	-4(%rbp),	%eax
	cmpl	-20(%rbp),	%eax
	jle	.L3
	jmp	.L0
.L3:
  # goto .L1
	jmp	.L1
  # goto .L1
	jmp	.L1
  # t3 = 2
.L0:
	movl	$2,	-24(%rbp)
  # t4 = a / t3
	movl	-4(%rbp),	%eax
	cltd
	idivl	-24(%rbp)
	movl	%eax,	-28(%rbp)
  # b = t4
	movl	-28(%rbp),	%eax
	movl	%eax,	-8(%rbp)
  # a = b
	movl	-8(%rbp),	%eax
	movl	%eax,	-4(%rbp)
  # goto .L2
	jmp	.L2
  # param a
.L1:
	movq	-4(%rbp),	%rdi
  # call printInt 1
	call	printInt
  # t5 = 0
	movl	$0,	-32(%rbp)
  # return t5
	movq	-32(%rbp),	%rax
	leave
	ret
  # function main end
	leave
	ret
	.size	main,	.-main
