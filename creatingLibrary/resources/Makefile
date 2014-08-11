a.out: mainPrintInt.o libprintInt.a
	cc -m32 mainPrintInt.o -L. -lprintInt 

mainPrintInt.o:	mainPrintInt.c printInt.h
	cc -Wall -m32 -c mainPrintInt.c

libprintInt.a:	printInt.o
		ar -rcs libprintInt.a printInt.o

printInt.o:	printInt.c printInt.h
	cc -Wall -m32 -c printInt.c
clean:
	rm a.out mainPrintInt.o libprintInt.a printInt.o
