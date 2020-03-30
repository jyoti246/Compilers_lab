final: a.out run_1

a.out: lex.yy.c y.tab.c y.tab.h ass6_17CS10059_translator.h ass6_17CS10059_translator.cxx ass6_17CS10059_target_translator.cxx libmyl.a
	g++ -std=c++14  ass6_17CS10059_translator.cxx lex.yy.c y.tab.c ass6_17CS10059_target_translator.cxx -lfl

y.tab.h: ass6_17CS10059.y
	yacc -dtv -Wconflicts-sr ass6_17CS10059.y
y.tab.c: ass6_17CS10059.y
	yacc -dtv -Wconflicts-sr ass6_17CS10059.y
lex.yy.c: ass6_17CS10059.l y.tab.h
	flex ass6_17CS10059.l

libmyl.a: myl.o
		ar -rcs libmyl.a myl.o

myl.o: myl.c myl.h
		gcc -Wall -c myl.c

clean:
	rm a.out y.tab.h y.tab.c lex.yy.c y.output ass6_17CS10059_quad*.txt

run_1: a.out ass6_17CS10059_test1.c
		./a.out < ass6_17CS10059_test1.c 1
		gcc -W -c ass6_17CS10059_1.s
		gcc ass6_17CS10059_1.o -L. -g -lmyl -o test1.out
		./test1.out

run_2: a.out ass6_17CS10059_test2.c
		./a.out < ass6_17CS10059_test2.c 2
		gcc -W -c ass6_17CS10059_2.s
		gcc ass6_17CS10059_2.o -L. -g -lmyl -o test2.out
		./test2.out

run_3: a.out ass6_17CS10059_test3.c
		./a.out < ass6_17CS10059_test3.c 3
		gcc -W -c ass6_17CS10059_3.s
		gcc ass6_17CS10059_3.o -L. -g -lmyl -o test3.out
		./test3.out

run_4: a.out ass6_17CS10059_test4.c
		./a.out < ass6_17CS10059_test4.c 4
		gcc -W -c ass6_17CS10059_4.s
		gcc ass6_17CS10059_4.o -L. -g -lmyl -o test4.out
		./test4.out

run_5: a.out ass6_17CS10059_test5.c
		./a.out < ass6_17CS10059_test5.c 5
		gcc -W -c ass6_17CS10059_5.s
		gcc ass6_17CS10059_5.o -L. -g -lmyl -o test5.out
		./test5.out

display_1:
	echo "\n-------------------- Test Input --------------------\n"
	cat ass6_17CS10059_test1.c
	echo "\n-------------------- Test Output --------------------\n"
	cat ass6_17CS10059_quads1.out

display_2:
	echo "\n-------------------- Test Input --------------------\n"
	cat ass6_17CS10059_test2.c
	echo "\n-------------------- Test Output --------------------\n"
	cat ass6_17CS10059_quads2.out

display_3:
	echo "\n-------------------- Test Input --------------------\n"
	cat ass6_17CS10059_test3.c
	echo "\n-------------------- Test Output --------------------\n"
	cat ass6_17CS10059_quads3.out

display_4:
	echo "\n-------------------- Test Input --------------------\n"
	cat ass6_17CS10059_test4.c
	echo "\n-------------------- Test Output --------------------\n"
	cat ass6_17CS10059_quads4.out

display_5:
	echo "\n-------------------- Test Input --------------------\n"
	cat ass6_17CS10059_test5.c
	echo "\n-------------------- Test Output --------------------\n"
	cat ass6_17CS10059_quads5.out
