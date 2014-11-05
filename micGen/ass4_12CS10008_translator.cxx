/*
* 	translator.cxx
* 	Author: Aseem Patni
*/

#include "ass4_12CS10008_translator.h"

/************ Global variables *************/

symtab* gTable;					// Global Symbbol Table
quads qarr;						// Quads
type_e TYPE;					// Stores latest type specifier
bool gDebug = false;			// Debug mode
symtab* table;					// Points to current symbol table
sym* currsym; 					// points to latest function entry in symbol table

/* Singleton Design Pattern */
Singleton* Singleton::pSingleton= NULL;
Singleton::Singleton() {
   // do init stuff
}
Singleton* Singleton::GetInstance() {
	if (pSingleton== NULL) {
		pSingleton = new Singleton();
	}
	return pSingleton;
}
int sizeoftype (symtype* t){
	switch (t->cat) {
		case _VOID:
			return 0;
		case _CHAR:
			return size_of_char;
		case _INT:
			return size_of_int;
		case _DOUBLE:
			return size_of_double;
		case PTR:
			return size_of_pointer;
		case ARR:
			return t->width * sizeoftype (t->ptr);
		case FUNC:
			return 0;
	}
}
string convert_to_string (const symtype* t){
	if (t==NULL) return "null";
	switch (t->cat) {
		case _VOID:
			return "void";
		case _CHAR:
			return "char";
		case _INT:
			return "int";
		case _DOUBLE:
			return "double";
		case PTR:
			return "ptr("+ convert_to_string(t->ptr)+")";
		case ARR:
			return "arr(" + tostr(t->width) + ", "+ convert_to_string (t->ptr) + ")";
		case FUNC:
			return "funct";
		default:
			return "type";
	}
}
symtype::symtype(type_e cat, symtype* ptr, int width): 
	cat (cat), 
	ptr (ptr), 
	width (width) {};
sym* symtab::lookup (string name) {
	sym* s;
	list <sym>::iterator it;
	for (it = table.begin(); it!=table.end(); it++) {
		if (it->name == name ) break;
	}
	/*
	for (i=0; i<table.size(); i++) {
		if (table[i].name == name ) break;
	}
	*/
	if (it!=table.end() ) {
		if (gDebug) cout << name << " already present" << endl;
		return &*it;
	}
	else {
		s =  new sym (name);
		s->category = "local";
		table.push_back (*s);
		if (gDebug) print();
		return &table.back();
	}
}
sym* gentemp (type_e t, string init) {
	char n[20];
	sprintf(n, "t%02d", table->tcount++);
	sym* s = new sym (n, t);
	s-> init = init;
	s->category = "temp";
	table->table.push_back ( *s);
	if (gDebug) table->print();
	return &table->table.back();
}
sym* gentemp (symtype* t, string init) {
	char n[20];
	sprintf(n, "t%02d", table->tcount++);
	sym* s = new sym (n);
	s->type = t;
	s-> init = init;
	s->category = "temp";
	table->table.push_back ( *s);
	if (gDebug) table->print();
	return &table->table.back();
}
symtab::symtab (string name): tname (name), tcount(0) {}
void symtab::print() {
	cout << "=== " << "Symbol Table: " << this -> tname << " ===" << endl;
	cout << "Name\t" ;
	cout << left << setw(16) << "Type";
	cout << left << setw(12) << "Category";
	cout << left << setw(12) << "Init Val";
	cout << left  << "Size\t" << "Offset\t" << "Nested Table" << endl;
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {
		cout << &*it;
	}
}
void symtab::printall() {
	list<symtab*> tablelist;
	cout << "=== " << "Symbol Table: " << this -> tname << " ===" << endl;
	cout << "Name\t" ;
	cout << left << setw(16) << "Type";
	cout << left << setw(12) << "Category";
	cout << left << setw(12) << "Init Val";
	cout << left  << "Size\t" << "Offset\t" << "Nested Table" << endl;
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {
		cout << &*it;
		if (it->nest!=NULL) tablelist.push_back (it->nest);
	}
	for (list<symtab*>::iterator iterator = tablelist.begin();
			iterator != tablelist.end();
			++iterator) {
	    (*iterator)->print();
	}
}
void symtab::computeOffsets() {
	list<symtab*> tablelist;
	int off;
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {
		if (it==table.begin()) {
			it->offset = 0;
			off = it->size;
		}
		else {
			it->offset = off;
			off = it->offset + it->size;
		}
		if (it->nest!=NULL) tablelist.push_back (it->nest);
	}
	for (list<symtab*>::iterator iterator = tablelist.begin(); 
			iterator != tablelist.end(); 
			++iterator) {
//	    debug ("computing for child");
	    (*iterator)->computeOffsets();
//		if (gDebug) (*iterator)->print();
	}
}
sym* sym::linkst(symtab* t) {
	this->nest = t;
	this->category = "function";
}

ostream& operator<<(ostream& os, const symtype* t) {
	type_e cat = t->cat;
	string stype = convert_to_string(t);
	os << stype;
	return os;
}
ostream& operator<<(ostream& os, const sym* it) {
	os << it->name << "\t";
	os << left << setw(16) << it->type;
	os << left << setw(12) << it->category;
	os << left << setw(12) << it->init;
	os << left << it->size << "\t";
	os << it->offset << "\t";
	printf("%p\t", it);
	if (it->nest == NULL) {
		os << "null" <<  endl;	
	}
	else {
//		os << "not null" << endl;
		os << it->nest->tname <<  endl;
	}
	return os;
}
quad::quad (string result, string arg1, optype op, string arg2):
	result (result), arg1(arg1), arg2(arg2), op (op){};

quad::quad (string result, int arg1, optype op, string arg2):
	result (result), arg2(arg2), op (op) {
		this ->arg1 = NumberToString(arg1);
	}
sym::sym (string name, type_e t, symtype* ptr, int width): name(name)  {
	type = new symtype (symtype(t, ptr, width));
	nest = NULL;
	init = "";
	category = "";
	offset = 0;
	size = sizeoftype(type);
}
sym* sym::initialize (string init) {
	this->init = init;
}
sym* sym::update(symtype* t) {
	type = t;
	this -> size = sizeoftype(t);
	if (gDebug) table->print();
	return this;
}
sym* sym::update(type_e t) {
	this->type = new symtype(t);
	this->size = sizeoftype(this->type);
	if (gDebug) table->print();
	return this;
}
void quad::update (int addr) {	// Used for backpatching address
	this ->result = addr;
}
void quad::print () {
	switch(op) {
		case ADD:			cout << result << " = " << arg1 << " + " << arg2;				break;
		case SUB:			cout << result << " = " << arg1 << " - " << arg2;				break;
		case MULT:			cout << result << " = " << arg1 << " * " << arg2;				break;
		case DIVIDE:		cout << result << " = " << arg1 << " / " << arg2;				break;
		case EQUAL:			cout << result << " = " << arg1 ;								break;
		case EQOP:			cout << "if " << arg1 <<  " == " << arg2 << " goto " << result;				break;
		case NEOP:			cout << "if " << arg1 <<  " != " << arg2 << " goto " << result;				break;
		case LT:			cout << "if " << arg1 <<  " < "  << arg2 << " goto " << result;				break;
		case GT:			cout << "if " << arg1 <<  " > "  << arg2 << " goto " << result;				break;
		case GE:			cout << "if " << arg1 <<  " >= " << arg2 << " goto " << result;				break;
		case LE:			cout << "if " << arg1 <<  " <= " << arg2 << " goto " << result;				break;
		case GOTOOP:		cout << "goto " << result;						break;
		//Unary Operators
		case ADDRESS:		cout << result << " = &" << arg1;				break;
		case PTRR:			cout << result	<< " = *" << arg1 ;				break;
		case PTRL:			cout << "*" << result	<< " = " << arg1 ;				break;
		case UMINUS:		cout << result 	<< " = -" << arg1;				break;
		case BNOT:			cout << result 	<< " = ~" << arg1;				break;
		case LNOT:			cout << result 	<< " = !" << arg1;				break;

		case ARRR:	 		cout << result << " = " << arg1 << "[" << arg2 << "]";			break;
		case _RETURN: 		cout << "ret";							break;
		case PARAM: 		cout << "param " << arg1;				break;
		case CALL: 			cout << "call " << arg1;				break;
		default:			cout << "op";							break;
	}
	cout << endl;
	/*
	if (arg2.empty()) {
		if (op== 0) // Copy Assignment Instruction
			cout << result << " = " << arg1 << endl;
		else // Unary Assignment Instruction
			cout << result << " = " << optostr(op) << arg2 << endl;
	}
	else { // Binary assignment Instruction
		cout << result << " = " << arg1 << optostr(op) << arg2 << endl;
	}
	*/
}
void quads::printtab() {
	cout << "=== Quad Table ===" << endl;
	cout << setw(8) << "index";
	cout << setw(8) << " op";
	cout << setw(8) << "arg 1";
	cout << setw(8) << "arg 2";
	cout << setw(8) << "result" << endl;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << left << setw(8) << it - array.begin(); 
		cout << left << setw(8) << optostr(it->op);
		cout << left << setw(8) << it->arg1;
		cout << left << setw(8) << it->arg2;
		cout << left << setw(8) << it->result << endl;
	}
}
void backpatch (list <int> l, int addr) {
	for (list<int>::iterator it= l.begin(); it!=l.end(); it++) qarr.array[*it].result = tostr(addr);
	if (gDebug) qarr.printtab();
}
void quads::print () {
	cout << "+++ Quad Translation +++" << endl;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << it - array.begin() << ": ";
		it->print();
	}
}
void emit(optype op, string result, string arg1, string arg2) {
	qarr.array.push_back(*(new quad(result,arg1,op,arg2)));
	if (gDebug) qarr.print();
}
void emit(optype op, string result, int arg1, string arg2) {
	qarr.array.push_back(*(new quad(result,arg1,op,arg2)));
	if (gDebug) qarr.print();
}
string optostr (int op) {
	switch(op) {
		case ADD:				return " + ";
		case SUB:				return " - ";
		case MULT:				return " * ";
		case DIVIDE:			return " / ";
		case EQUAL:				return " = ";
		case EQOP:				return " == ";
		case NEOP:				return " != ";
		case LT:				return " < ";
		case GT:				return " > ";
		case GE:				return " >= ";
		case LE:				return " <= ";
		case GOTOOP:			return " goto ";
		//Unary Operators
		case ADDRESS:			return " &";
		case PTRR:				return " *R";
		case PTRL:				return " *L";
		case UMINUS:			return " -";
		case BNOT:				return " ~";
		case LNOT:				return " !";

		case ARRR:	 			return " =[]R";
		case _RETURN: 			return " ret";
		case PARAM: 			return " param ";
		case CALL: 				return " call ";
		default:				return " op ";
	}
}
list<int> makelist (int i) {
	list<int> l(1,i);
	return l;
}
list<int> merge (list<int> &a, list <int> &b) {
	a.merge(b);
	return a;
}
int nextinstr() {
	return qarr.array.size();
}
string NumberToString ( int Number ) {
	ostringstream ss;
	ss << Number;
	return ss.str();
}
expr* convert2bool (expr* e) {	// Convert any expression to bool
	if (!e->isbool) {
		debug ("converting");
		e->falselist = makelist (nextinstr());
		emit (EQOP, "", 0, e->symp->name);
		e->truelist = makelist (nextinstr());
		emit (GOTOOP, "");
	}
}
bool typecheck(sym* s1, sym* s2){ 	// Check if the symbols have same type or not
	symtype* type1 = s1->type;
	symtype* type2 = s1->type;
	return typecheck (type1, type2);
}
bool typecheck(symtype* t1, symtype* t2){ 	// Check if the symbol types are same or not
	return true;
	if (t1 != NULL || t2 != NULL) {
		if (t1==NULL) return false;
		if (t2==NULL) return false;
		if (t1->cat==t2->cat) return (t1->ptr, t2->ptr);
		else return false;
	}
	return true;
}

void changeTable (symtab* newtable) {	// Change current symbol table
	if (gDebug)	cout << "Symbol table changed from " << table->tname;
	table = newtable;
	if (gDebug)	cout << " to " << table->tname << endl;
} 


// Functions for debugging 
void printlist (lint l) {	// Print integers in list l 
	for (list<int>::iterator iterator = l.begin(); iterator != l.end(); ++iterator) {
	    if (gDebug) cout << *iterator << " ";
	}
	cout << endl;
}

int  main (int argc, char* argv[]){
	if (argc>1) gDebug = true;
	gTable = new symtab("Global");
	table = gTable;
	yyparse();
	table->computeOffsets();
	table->printall();
//	qarr.printtab();
	qarr.print();
	int n, x;
	cin >> n;
	if (n==10) {
		while (n--) {
			cin >> x;
			if(x==1) {
				gentemp(_DOUBLE);
			}
			else if (x==2) {
				emit(ADD, "a", "b", "c");
			}
		}	
	}

};
