	.section	.rodata
  # function readInt start
  # function printInt start
  # function readFlt start
  # function printFlt start
  # function main start
#--loacl var offset: 4 -4
#--loacl var offset: 4 -8
#--loacl var offset: 4 -12
#--loacl var offset: 4 -16
#--loacl var offset: 4 -20
#--loacl var offset: 4 -24
#--loacl var offset: 8 -32
#--loacl var offset: 4 -36
#--loacl var offset: 4 -40
#--loacl var offset: 4 -44
#--loacl var offset: 4 -48
#-48
##ptrn
##ptrreadInt
##ptrt0
##ptrx
##ptri
##ptrprintInt
##ptrf
##ptrreadFlt
##ptrt1
##ptrprintFlt
##ptrt2
##ptrretVal
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80,	%rsp
  # 	leaq	-4(%rbp),	%rax
	movq	%rax,	-12(%rbp)
  # param t0
	movq	-12(%rbp),	%rdi
  # call readInt 1
	call	readInt
  # x = readInt
	movl	%eax,	-16(%rbp)
  # i = x
	movl	-16(%rbp),	%eax
	movl	%eax,	-20(%rbp)
  # param i
	movq	-20(%rbp),	%rdi
  # call printInt 1
	call	printInt
  # 	leaq	-32(%rbp),	%rax
	movq	%rax,	-40(%rbp)
  # param t1
  # call readFlt 1
	movq	-40(%rbp),	%rax
	pushq	%rax
	call	readFlt
	addq	$8,	%rsp
#--
  # f = readFlt
	movl	%eax,	-32(%rbp)
  # param f
  # call printFlt 1
	movq	-32(%rbp),	%rax
	pushq	%rax
	call	printFlt
	addq	$8,	%rsp
#--
  # t2 = 0
	movl	$0,	-48(%rbp)
  # return t2
	movq	-48(%rbp),	%rax
	leave
	ret
  # function main end
	leave
	ret
	.size	main,	.-main
