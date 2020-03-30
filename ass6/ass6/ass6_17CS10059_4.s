	.section	.rodata
  # function readInt start
  # function printInt start
  # function main start
#--loacl var offset: 4 -4
#--loacl var offset: 4 -8
#--loacl var offset: 4 -12
#--loacl var offset: 4 -16
#--loacl var offset: 1 -17
#--loacl var offset: 1 -18
#--loacl var offset: 4 -22
#--loacl var offset: 4 -26
#--loacl var offset: 4 -30
#--loacl var offset: 4 -34
#--loacl var offset: 0 -34
#--loacl var offset: 4 -38
#--loacl var offset: 4 -42
#--loacl var offset: 4 -46
#-46
##ptrlol
##ptrreadInt
##ptrt0
##ptra
##ptrt1
##ptrc
##ptrt2
##ptrb
##ptri
##ptrt3
##ptrt4
##ptrt5
##ptrprintInt
##ptrt6
##ptrretVal
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$64,	%rsp
  # 	leaq	-4(%rbp),	%rax
	movq	%rax,	-12(%rbp)
  # param t0
	movq	-12(%rbp),	%rdi
  # call readInt 1
	call	readInt
  # a = readInt
	movl	%eax,	-16(%rbp)
  # t1 = a
	movl	-16(%rbp),	%eax
	movl	%eax,	-17(%rbp)
  # c = t1
	movl	-17(%rbp),	%eax
	movl	%eax,	-18(%rbp)
  # t2 = 1
	movl	$1,	-22(%rbp)
  # b = t2
	movl	-22(%rbp),	%eax
	movl	%eax,	-26(%rbp)
  # t3 = 0
	movl	$0,	-34(%rbp)
  # i = t3
	movl	-34(%rbp),	%eax
	movl	%eax,	-30(%rbp)
  # if i < a goto .L0
.L2:
	movl	-30(%rbp),	%eax
	cmpl	-16(%rbp),	%eax
	jge	.L4
	jmp	.L0
.L4:
  # goto .L1
	jmp	.L1
  # goto .L1
	jmp	.L1
  # t5 = i
.L3:
	movl	-30(%rbp),	%eax
	movl	%eax,	-38(%rbp)
  # i = i + 1
	movl	-30(%rbp),	%edx
	addl	$1,	%edx
	movl	%edx,	%eax
	movl	%eax,	-30(%rbp)
  # goto .L2
	jmp	.L2
  # b = i
.L0:
	movl	-30(%rbp),	%eax
	movl	%eax,	-26(%rbp)
  # goto .L3
	jmp	.L3
  # param b
.L1:
	movq	-26(%rbp),	%rdi
  # call printInt 1
	call	printInt
  # t6 = 0
	movl	$0,	-46(%rbp)
  # return t6
	movq	-46(%rbp),	%rax
	leave
	ret
  # function main end
	leave
	ret
	.size	main,	.-main
