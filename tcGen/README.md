## Instructions

How to make?
	
	make

To view help regarding compiler

	./compiler --help

To use the compiler

	Allowed options:
	  --help                  produce help message
	  --debug arg             set debugging on/off
	  -s [ --sfilepath ] arg  path for generated .s file
	  -i [ --input-file ] arg input file name

To generate .s files for test files

	make asm

To run a .s file compiled with the library

	gcc -c -m32 <file.s> -o testfile.o
	gcc -m32 testfile.o -L. -lmyl 
	./a.out

To remove unwanted files

	make clean

## Shortcomings:

* According to the doc 0 is not considered a integer constant.
* Nextlist of last block item is not backpatched. Therefore a return statement is mandatory at the end of a function.
* There is some segmentation fault coming after the end of program don't know why.
* Only the I/O assembly functions provided by the assembly can be implemented.
