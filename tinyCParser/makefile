a.out: lex.yy.o y.tab.o ass3_12CS10008_main.o
	gcc lex.yy.o y.tab.o ass3_12CS10008_main.o -lfl

ass3_12CS10008_main.o: ass3_12CS10008_main.c
	gcc -c ass3_12CS10008_main.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.c: ass3_12CS10008.l y.tab.h
	flex ass3_12CS10008.l

y.tab.c: ass3_12CS10008.y
	yacc -dtv ass3_12CS10008.y -W

y.tab.h: ass3_12CS10008.y
	yacc -dtv ass3_12CS10008.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass3_12CS10008_main.o y.output a.out

test: 
	./a.out < ass3_12CS10008_test.c