CODE_DIR = lib

.PHONY: lib

compiler: lex.yy.o y.tab.o ass6_12CS10008_translator.o ass6_12CS10008_target_translator.o
	g++ lex.yy.o y.tab.o ass6_12CS10008_translator.o \
	ass6_12CS10008_target_translator.o -lfl -o compiler \
	-lboost_program_options

ass6_12CS10008_target_translator.o: ass6_12CS10008_target_translator.cxx
	g++ -c ass6_12CS10008_target_translator.cxx

ass6_12CS10008_translator.o: ass6_12CS10008_translator.cxx ass6_12CS10008_translator.h
	g++ -c ass6_12CS10008_translator.h
	g++ -c ass6_12CS10008_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass6_12CS10008.l y.tab.h ass6_12CS10008_translator.h
	flex ass6_12CS10008.l

y.tab.c: ass6_12CS10008.y
	yacc -dtv ass6_12CS10008.y -W

y.tab.h: ass6_12CS10008.y
	yacc -dtv ass6_12CS10008.y -W

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass6_12CS10008_translator.o y.output compiler ass6_12CS10008_target_translator.o

cleanLib:
	$(MAKE) -C $(CODE_DIR) clean

test: 
	./compiler testBubbleSort.c

asm:
	./compiler -s test4.s test4.c > test4.log
	./compiler -s test1.s test1.c > test1.log
	./compiler -s test2.s test2.c > test2.log
	./compiler -s test3.s test3.c > test3.log
	./compiler -s testBubbleSort.s testBubbleSort.c > testBubbleSort.log

lib:
	$(MAKE) -C $(CODE_DIR)