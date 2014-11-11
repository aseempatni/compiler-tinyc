a.out: main.o libmyl.a
	gcc -m32 main.o -L. -lmyl 

main.o:	main.c myl.h
	gcc -Wall -m32 -c main.c -Wno-write-strings

libmyl.a: myl.o
	ar -rcs libmyl.a myl.o

myl.o:	myl.c myl.h
	gcc -Wall -m32 -c myl.c

clean:
	rm a.out main.o libmyl.a myl.o
