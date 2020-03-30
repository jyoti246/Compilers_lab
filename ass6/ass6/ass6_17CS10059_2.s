	.section	.rodata
  # function readFlt start
  # function printFlt start
  # function main start
#--loacl var offset: 8 -8
#--loacl var offset: 4 -12
#--loacl var offset: 4 -16
#--loacl var offset: 8 -24
#--loacl var offset: 4 -28
#--loacl var offset: 4 -32
#-32
##ptrp
##ptrreadFlt
##ptrt0
##ptra
##ptrprintFlt
##ptrt1
##ptrretVal
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64,	%rsp
  # 	leaq	-8(%rbp),	%rax
	movq	%rax,	-16(%rbp)
  # param t0
  # call readFlt 1
	movq	-16(%rbp),	%rax
	pushq	%rax
	call	readFlt
	addq	$8,	%rsp
#--
  # a = readFlt
	movl	%eax,	-24(%rbp)
  # param a
  # call printFlt 1
	movq	-24(%rbp),	%rax
	pushq	%rax
	call	printFlt
	addq	$8,	%rsp
#--
  # t1 = 0
	movl	$0,	-32(%rbp)
  # return t1
	movq	-32(%rbp),	%rax
	leave
	ret
  # function main end
	leave
	ret
	.size	main,	.-main
