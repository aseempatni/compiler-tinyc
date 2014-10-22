/*
* 	translator.h
* 	Author: Aseem Patni
*/
#ifndef TRANSLATE 
#define TRANSLATE
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "y.tab.h"
#define size_of_char 		1
#define size_of_int  		4
#define size_of_double		8
#define size_of_pointer		4

extern  char* yytext;
extern  int yyparse();

using namespace std;

/********* Forward Declarations ************/
class sym;												// Entry in a symbol table
class symtab;											// Symbol Table
class quad;
class quads;

/************** enum types *****************/

enum type_e {_VOID, _CHAR, _INT, _DOUBLE, PTR, ARR, FUNC}; 	// Type enumeration
enum op_t {PLUS=1000, SUB, MULT, DIVIDE};

/********** Class Declarations *************/
class symtype {
public:
	symtype(type_e cat, symtype* ptr = NULL, int size = 1): 
		cat(cat), 
		ptr (ptr), 
		size(size) {};
	type_e cat;
	int size;					// Size of array
	symtype* ptr;				// Array -> array of ptr type; pointer-> pointer to ptr type 
	friend ostream& operator<<(ostream&, const symtype);
};

class symtab {
public:
	string tname;
	symtab (string name): 
		tname (name), 
		tcount(0), 
		offset (0) {};
	int tcount;											// Count of temporary variables
	int offset;
	vector <sym> table; 								// The table of symbols
	sym* lookup (string name);							// Lookup for a symbol in symbol table
	sym* gentemp (type_e t, symtype* ptr = NULL, int size = 0);						// Generate a temporary variable and insert it in symbol table
	void print();										// Print the symbol table
	sym& update(string, int size, symtab* = NULL); 
};
class sym {
public:
	string name;
	symtype *type;
	string init;
	int size;
	int offset;
	symtab* nest;
	sym (string name, type_e t=_INT, symtype* ptr = NULL, int size = 0):
		name(name)  {
		type = new symtype (symtype(t, ptr, size));
	};
	friend ostream& operator<<(ostream&, const sym*);
};
class quad {
public:
	quad (string result, string arg1, int op = 0, string arg2 = NULL);
	int op;
	string result;
	string arg1;
	string arg2;
	void print ();
	void update (int addr) {
		this ->result = addr;
	}
};
class quads {
public:
	vector <quad> array;;
	void print ();	
	void printtab();
	void backpatch (list <int>, int);
	void emit(string result, string arg1, int op = 0, string arg2 = NULL);
};
class Singleton {
public:
   static Singleton* GetInstance();
private:
   Singleton();
   static Singleton* pSingleton;						// singleton instance
};

/*********** Function Declarations *********/
list<int> makelist (int);
list<int> merge (list<int> &, list <int> &);

int sizeoftype (symtype);
string to_string (const symtype*);
string optostr(int);
typedef list<int> lint;

/*** Global variables declared in cxx file****/
extern symtab table;									// Global Symbbol Table
extern quads qarr;												// Quads

#endif