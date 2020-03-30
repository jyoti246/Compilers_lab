	.section	.rodata
  # function printInt start
  # function f start
#--param_offset:24
#--loacl var offset: 4 -4
#-4
##ptra
##ptrt0
##ptrretVal
	.globl	f
	.type	f, @function
f:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32,	%rsp
  # t0 = 0
	movl	$0,	-4(%rbp)
  # return t0
	movq	-4(%rbp),	%rax
	leave
	ret
  # function f end
	leave
	ret
	.size	f,	.-f
  # function main start
#--loacl var offset: 4 -4
#--loacl var offset: 4 -8
#--loacl var offset: 1 -9
#--loacl var offset: 1 -10
#--loacl var offset: 4 -14
#--loacl var offset: 4 -18
#--loacl var offset: 4 -22
#--loacl var offset: 4 -26
#--loacl var offset: 4 -30
#--loacl var offset: 4 -34
#--loacl var offset: 4 -38
#-38
##ptrt1
##ptra
##ptrt2
##ptrc
##ptrt3
##ptrb
##ptrt4
##ptrt5
##ptrf
##ptrprintInt
##ptrt6
##ptrretVal
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64,	%rsp
  # t1 = 3
	movl	$3,	-4(%rbp)
  # a = t1
	movl	-4(%rbp),	%eax
	movl	%eax,	-8(%rbp)
  # t2 = a
	movl	-8(%rbp),	%eax
	movl	%eax,	-9(%rbp)
  # c = t2
	movl	-9(%rbp),	%eax
	movl	%eax,	-10(%rbp)
  # t3 = 1
	movl	$1,	-14(%rbp)
  # b = t3
	movl	-14(%rbp),	%eax
	movl	%eax,	-18(%rbp)
  # t4 = 2
	movl	$2,	-22(%rbp)
  # t5 = b + t4
	movl	-18(%rbp),	%edx
	movl	-22(%rbp),	%eax
	addl	 %edx,	%eax
	movl	 %eax,	-26(%rbp)
  # b = t5
	movl	-26(%rbp),	%eax
	movl	%eax,	-18(%rbp)
  # param a
  # call f 1
	movq	-8(%rbp),	%rax
	pushq	%rax
	call	f
	addq	$8,	%rsp
#--
  # b = f
	movl	%eax,	-18(%rbp)
  # param b
	movq	-18(%rbp),	%rdi
  # call printInt 1
	call	printInt
  # t6 = 0
	movl	$0,	-38(%rbp)
  # return t6
	movq	-38(%rbp),	%rax
	leave
	ret
  # function main end
	leave
	ret
	.size	main,	.-main
