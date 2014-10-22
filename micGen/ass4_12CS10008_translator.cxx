/*
* 	translator.cxx
* 	Author: Aseem Patni
*/

#include "ass4_12CS10008_translator.h"

/************ Global variables *************/
symtab table("Global");									// Global Symbbol Table
quads qarr;												// Quads

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
int sizeoftype (symtype *t){
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
			return t->size * sizeoftype (t->ptr);
		case FUNC:
			return 0;
	}
}
string to_string (const symtype* t){
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
			return "ptr("+ to_string(t->ptr)+")";
		case ARR:
			return "array("+ t->size + to_string (t->ptr) + ")";
		case FUNC:
			return "function";
		default:
			return "type";
	}
}
sym* symtab::lookup (string name) {
	sym* s;
	int i;
	for (i=0; i<table.size(); i++) {
		if (table[i].name == name ) break;
	}
	if (i!=table.size() ) {
		return &table[i];
	}
	else {
		table.push_back (*( new sym (name)));
		return &table.back();
	}
}
sym* symtab::gentemp (type_e t,symtype* ptr, int size) {
	char n[20];
	sprintf(n, "t%02d", tcount++);
	sym* s = new sym (n, t, ptr, size);
	s->offset = offset;
	s->size = sizeoftype(s->type);
	offset += s->size;
	s->nest = NULL;
	table.push_back ( *s);
	return &table.back();
}
void symtab::print() {
	cout << "=== " << "Symbol Table: " << this -> tname << " ===" << endl;
	cout << "Name\t" << "Type\t" << "Initial Value\t" << "Size\t" << "Offset\t" << "Nested Table" << endl;
	for (vector <sym>::iterator it = table.begin(); it!=table.end(); it++) {
		cout << &*it;
	}
}
ostream& operator<<(ostream& os, const symtype* t) {
	type_e cat = t->cat;
	string stype = to_string(t);
	os << stype;
	return os;
}
ostream& operator<<(ostream& os, const sym* it) {
	os << it->name << "\t";
	os << it->type << "\t";
	os << it->init << "\t" << "\t";
	os << it->size << "\t";
	os << it->offset << "\t";
	if (it->nest == NULL) {
		os << "null" <<  endl;	
	}
	else {
		os << it->nest->tname <<  endl;
	}
	return os;
}
quad::quad (string result, string arg1, int op, string arg2): result (result), arg1(arg1) { 
	this -> arg2 = arg2;
	this -> op = op;
}
void quad::print () {
	if (arg2.empty()) {
		if (op== 0) 
			cout << result << " = " << arg1 << endl;
		else 
			cout << result << " = " << optostr(op) << arg2 << endl;
	}
	else {
		cout << result << " = " << arg1 << optostr(op) << arg2 << endl;
	}
}
void quads::printtab() {
	cout << "+++ Quad Table +++" << endl;
	cout << "index" << "\t;" << "op" << "\t" << "arg 1" << "\t" << "arg 2" << "\t" << "result" << endl;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << it - array.begin() << "\t"; 
		cout << optostr(it->op) << "\t";
		cout << it->arg1 << "\t";
		cout << it->arg2 << "\t";
		cout << it->result << endl;
	}
}
void quads::backpatch (list <int> l, int addr) {
	for (list<int>::iterator it= l.begin(); it!=l.end(); it++) array[*it].result = addr;
}
void quads::print () {
	cout << "+++ Quad Translation +++" << endl;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << it - array.begin() << ": ";
		it->print();
	}
}
void quads::emit(string result, string arg1, int op, string arg2){
	array.push_back(*(new quad(result,arg1,op,arg2)));
}
string optostr (int op) {
	switch(op) {
		case PLUS:
			return " + ";
		case SUB:
			return " - ";
		case MULT:
			return " * ";
		case DIVIDE:
			return " / ";
		default:
			return " op ";
	}
}
int  main (){
	int n, x;
	cin >>
	 n;
	 if (n==10) yyparse();
	while (n--) {
		cin >> x;
		if(x==1) {
			table.gentemp(_DOUBLE);
			table.print();
		}
		else if (x==2) {
			qarr.emit("a", "b", PLUS, "c");
			qarr.printtab();
		}
	}
};
list<int> makelist (int i) {
	list<int> l(1,i);
	return l;
}
list<int> merge (list<int> &a, list <int> &b){
	a.merge(b);
	return a;
}