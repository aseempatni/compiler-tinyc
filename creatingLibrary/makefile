a.out: main.o libmyl.a
	cc -m32 main.o -L. -lmyl 

main.o:	main.c myl.h
	cc -Wall -m32 -c main.c 

libmyl.a: myl.o
		ar -rcs libmyl.a myl.o

myl.o:	myl.c myl.h
	cc -Wall -m32 -c myl.c

clean:
	rm a.out main.o libmyl.a myl.o
