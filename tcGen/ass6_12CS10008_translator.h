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
#define size_of_char 		1
#define size_of_int  		4
#define size_of_double		8
#define size_of_pointer		4

#define debug(x) do { \
  if (gDebug) { cerr << x << std::endl; } \
} while (0)

extern  char* yytext;
extern  int yyparse();
extern bool gDebug;

using namespace std;

/********* Forward Declarations ************/

class sym;						// Entry in a symbol table
class symtab;					// Symbol Table
class quad;						// Entry in quad array
class quads;					// All Quads
class symtype;					// Type of a symbol in symbol table

/************** Enum types *****************/

enum type_e {	// Type enumeration
_VOID, _CHAR, _INT, _DOUBLE, PTR, ARR}; 	
enum optype { EQUAL, EQUALSTR, EQUALCHAR, 
// Relational Operators 
LT, GT, LE, GE, EQOP, NEOP,
GOTOOP, _RETURN,
// Arithmatic Operators
ADD, SUB, MULT, DIVIDE, RIGHTOP, LEFTOP, MODOP,
// Unary Operators
UMINUS, UPLUS, ADDRESS, RIGHT_POINTER, BNOT, LNOT,
// Bit Operators
BAND, XOR, INOR,
// PTR Assign
PTRL, PTRR,
// ARR Assign
ARRR, ARRL,
// Function call
PARAM, CALL, FUNC, FUNCEND
};

/********** Class Declarations *************/

class symtype { // Type of an element in symbol table
public:
	symtype(type_e cat, symtype* ptr = NULL, int width = 1);
	type_e cat;
	int width;					// Size of array
	symtype* ptr;				// Array -> array of ptr type; pointer-> pointer to ptr type 

	friend ostream& operator<<(ostream&, const symtype);
};

class sym { // Row in a Symbol Table
public:
	string name;				// Name of symbol
	symtype *type;				// Type of Symbol
	string init;				// Symbol initialisation
	string category;			// local, temp or global
	int size;					// Size of the type of symbol
	int offset;					// Offset of symbol computed at the end
	symtab* nest;				// Pointer to nested symbol table
	
	sym (string, type_e t=_INT, symtype* ptr = NULL, int width = 0);
	sym* update(symtype * t); 	// Update using type object and nested table pointer
	sym* update(type_e t); 		// Update using raw type and nested table pointer
	sym* initialize (string);
	friend ostream& operator<<(ostream&, const sym*);
	sym* linkst(symtab* t);
};

class symtab { // Symbol Table
public:
	string tname;				// Name of Table
	int tcount;					// Count of temporary variables
	list <sym> table; 			// The table of symbols
	symtab* parent;
	map<string, int> ar;		// Activation Record

	symtab (string name="");
	sym* lookup (string name);					// Lookup for a symbol in symbol table
	void print(int all = 0);					// Print the symbol table
	void computeOffsets();						// Compute offset of the whole symbol table recursively
};

class quad { // Individual Quad
public:
	optype op;					// Operator
	string result;				// Result
	string arg1;				// Argument 1
	string arg2;				// Argument 2

	void print ();								// Print Quads
	void update (int addr);						// Used for backpatching address
	quad (string result, string arg1, optype op = EQUAL, string arg2 = "");
	quad (string result, int arg1, optype op = EQUAL, string arg2 = "");
	friend ostream& operator<<(ostream&, const quad*);
};

class quads { // Quad Array
public:
	vector <quad> array;		// Vector of quads

	quads () {array.reserve(300);}
	void print ();								// Print all the quads
	void printtab();							// Print quads in tabular form
};

class Singleton {	// Global Symbol Table is Singleton Object
public:
   static Singleton* GetInstance();
private:
   Singleton();
   static Singleton* pSingleton;					// singleton instance
};

/*********** Function Declarations *********/

sym* gentemp (type_e t=_INT, string init = "");		// Generate a temporary variable and insert it in symbol table
sym* gentemp (symtype* t, string init = "");		// Generate a temporary variable and insert it in symbol table

void backpatch (list <int>, int);
void emit(optype opL, string result, string arg1="", string arg2 = "");
void emit(optype op, string result, int arg1, string arg2 = "");

typedef list<int> lint;
list<int> makelist (int);							// Make a new list contaninig an integer
list<int> merge (list<int> &, list <int> &);		// Merge two lists

int sizeoftype (symtype*);							// Calculate size of any type
string convert_to_string (const symtype*);			// For printing type structure
string optostr(int);

sym* conv (sym*, type_e);							// Convert symbol to different type
bool typecheck(sym* &s1, sym* &s2);					// Checks if two symbbol table entries have same type
bool typecheck(symtype* s1, symtype* s2);			// Check if the type objects are equivalent

int nextinstr();									// Returns the address of the next instruction
string NumberToString(int);							// Converts a number to string mainly used for storing numbers

void changeTable (symtab* newtable);

/*** Global variables declared in cxx file****/

extern symtab* table;			// Current Symbbol Table
extern symtab* gTable;			// Global Symbbol Table
extern quads qarr;				// Quads
extern sym* currsym;			// Pointer to just encountered symbol

/** Attributes/Global for Boolean Expression***/

struct expr {
	bool isbool;				// Boolean variable that stores if the expression is bool

	// Valid for non-bool type
	sym* symp;					// Pointer to the symbol table entry

	// Valid for bool type
	lint truelist;				// Truelist valid for boolean
	lint falselist;				// Falselist valid for boolean expressions

	// Valid for statement expression
	lint nextlist;
};

struct statement {
	lint nextlist;				// Nextlist for statement
};

struct unary {
	type_e cat;
	sym* loc;					// Temporary used for computing array address
	sym* symp;					// Pointer to symbol table
	symtype* type;				// type of the subarray generated
};

// Utility functions
template <typename T> string tostr(const T& t) { 
	ostringstream os; 
	os<<t; 
	return os.str(); 
} 

expr* convert2bool (expr*);				// convert any expression to bool
expr* convertfrombool (expr*);			// convert bool to expression

// For debugging 
void printlist (lint list);				// Print the list of integers
#endif