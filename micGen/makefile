a.out: lex.yy.o y.tab.o ass5_12CS10008_translator.o
	g++ lex.yy.o y.tab.o ass5_12CS10008_translator.o -lfl

ass5_12CS10008_translator.o: ass5_12CS10008_translator.cxx ass5_12CS10008_translator.h
	g++ -c ass5_12CS10008_translator.h
	g++ -c ass5_12CS10008_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass5_12CS10008.l y.tab.h ass5_12CS10008_translator.h
	flex ass5_12CS10008.l

y.tab.c: ass5_12CS10008.y
	yacc -dtv ass5_12CS10008.y -W

y.tab.h: ass5_12CS10008.y
	yacc -dtv ass5_12CS10008.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass5_12CS10008_translator.o y.output a.out

test: 
	./a.out < ass5_12CS10008_test.c > ass5_12CS10008_test.out
	./a.out < testStatements.c > testStatements.out
	./a.out < testExpressions.c > testExpressions.out
	./a.out < testDeclarations.c > testDeclarations.out
	./a.out < testFunction.c > testFunction.out

