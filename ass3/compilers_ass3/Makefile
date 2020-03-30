all : lex.yy.c a.out test
lex.yy.c:    ass3_17CS10016.l
	flex ass3_17CS10016.l

a.out: lex.yy.c ass3_17CS10016.c
	gcc lex.yy.c ass3_17CS10016.c -lfl

test: 	a.out
	./a.out < ass3_17CS10016_test.c

clean:
	rm lex.yy.c a.out