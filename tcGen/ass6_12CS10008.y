 %{ 
/*	
*	parse.y
* 	Author: Aseem Patni
*/
 	/* C Declarations and Definitions */
	#include <string.h>
	#include <stdio.h>
	#include "ass6_12CS10008_translator.h"
	extern	int yylex();
	void yyerror(const char *s);
	extern type_e TYPE;
	extern bool gDebug;
	vector <string> allstrings;
%}


%union {
	char charval;
	int intval;
	int instr;
	char* strval;
	float floatval;
	sym* symp;
	expr* exp;
	lint* nl;
	symtype* st;
	statement* stat;
	unary* A;
	char uop;	//unary operator
}

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM
%token BREAK CASE CONTINUE DEFAULT DO IF ELSE FOR GOTO WHILE SWITCH SIZEOF
%token RETURN

%token ELLIPSIS RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN
%token DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN RIGHT_OP LEFT_OP 
%token INC_OP DEC_OP PTR_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP

%token <strval> STRING_LITERAL
%token <symp>IDENTIFIER  PUNCTUATORS COMMENT
%token <intval>INT_CONSTANT 
	
%token <strval> FLOAT_CONSTANT
	ENU_CONSTANT 
%token <charval>CHAR_CONSTANT

%start translation_unit
   	
// Expressions
%type <A> postfix_expression
	unary_expression
	cast_expression
%type <exp>
	expression
	primary_expression 
	multiplicative_expression
	additive_expression
	shift_expression
	relational_expression
	equality_expression
	and_expression
	exclusive_or_expression
	inclusive_or_expression
	logical_and_expression
	logical_or_expression
	conditional_expression
	assignment_expression
	expression_statement

%type <uop> unary_operator
%type <symp> constant initializer

%type <instr> M
%type <exp> N
%type <st> pointer
%type <symp> direct_declarator init_declarator declarator
%type <intval> argument_expression_list

%type <stat>  statement
	labeled_statement 
	compound_statement
	
	selection_statement
	iteration_statement
	jump_statement
	block_item
	block_item_list

%%
primary_expression
	: IDENTIFIER {
		$$ = new expr();
		$$->symp = $1;
		$$->isbool = false;
	}
	| constant {
		$$ = new expr();
		$$->symp = $1;
	}
	| STRING_LITERAL {
		$$ = new expr();
		$$->symp = gentemp(PTR, $1);
		$$->symp->type->ptr = new symtype(_CHAR);
		$$->symp->initialize($1);
		allstrings.push_back($1);
		emit(EQUALSTR, $$->symp->name, tostr (allstrings.size()-1));
	}
	| '(' expression ')' {
		$$ = $2;
	}
	;

constant
	: INT_CONSTANT {
		$$ = gentemp(_INT, NumberToString($1));
		emit(EQUAL, $$->name, $1);
	}
	| FLOAT_CONSTANT {
		$$ = gentemp(_DOUBLE, *new string ($1));
		emit(EQUAL, $$->name, *new string($1));
	}
	| ENU_CONSTANT {	/* Ignored */
	}
	| CHAR_CONSTANT{
		$$ = gentemp(_CHAR, tostr($1));
		emit(EQUALCHAR, $$->name,tostr((int)$1));
	}
	;

postfix_expression
	: primary_expression  {
		$$ = new unary ();
		$$->symp = $1->symp;
		$$->loc = $$->symp;
		$$->type = $1->symp->type;
	}
	| postfix_expression '[' expression ']' {
		$$ = new unary();
		
		$$->symp = $1->symp;			// copy the base
		$$->type = $1->type->ptr;		// type = type of element
		$$->loc = gentemp(_INT);		// store computed address
		
		// New address = already computed + $3 * new width
		if ($1->cat==ARR) {		// if something already computed
			sym* t = gentemp(_INT);
 			emit(MULT, t->name, $3->symp->name, NumberToString(sizeoftype($$->type)));
			emit (ADD, $$->loc->name, $1->loc->name, t->name);
		}
 		else {
	 		emit(MULT, $$->loc->name, $3->symp->name, NumberToString(sizeoftype($$->type)));
 		}

 		// Mark that it contains array address and first time computation is done
		$$->cat = ARR;
	}
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')' {
		$$ = new unary();
		$$->symp = gentemp($1->type->cat);
		emit(CALL, $$->symp->name, $1->symp->name, tostr($3));
	}
	| postfix_expression '.' IDENTIFIER /* Ignored */
	| postfix_expression PTR_OP IDENTIFIER  /* Ignored */
	| postfix_expression INC_OP {
		$$ = new unary();

		// copy $1 to $$
		$$->symp = gentemp($1->symp->type->cat);
		emit (EQUAL, $$->symp->name, $1->symp->name);

		// Increment $1
		emit (ADD, $1->symp->name, $1->symp->name, "1");
	}
	| postfix_expression DEC_OP {
		$$ = new unary();

		// copy $1 to $$
		$$->symp = gentemp($1->symp->type->cat);
		emit (EQUAL, $$->symp->name, $1->symp->name);

		// Decrement $1
		emit (SUB, $1->symp->name, $1->symp->name, "1");
	}
	| '(' type_name ')' '{' initializer_list '}' { /* Ignored */
		$$ = new unary();
		$$->symp = gentemp(_INT, "0");
		$$->loc = gentemp(_INT, "0");
	}
	|  '(' type_name ')' '{' initializer_list ',' '}' { /* Ignored */
		$$ = new unary();
		$$->symp = gentemp(_INT, "0");
		$$->loc = gentemp(_INT, "0");
	}
	;

argument_expression_list
	: assignment_expression {
		emit (PARAM, $1->symp->name);
		$$ = 1;
	}
	| argument_expression_list ',' assignment_expression {
		emit (PARAM, $3->symp->name);
		$$ = $1+1;
	}
	;

unary_expression
	: postfix_expression {
		$$ = $1;
//		debug ($$->symp);
	}
	| INC_OP unary_expression {
		// Increment $1
		emit (ADD, $2->symp->name, $2->symp->name, "1");

		// Use the same value
		$$ = $2;
	}
	| DEC_OP unary_expression {
		// Decrement $1
		emit (SUB, $2->symp->name, $2->symp->name, "1");

		// Use the same value
		$$ = $2;
	}
	| unary_operator cast_expression {
		$$ = new unary();
		switch ($1) {
			case '&':
				$$->symp = gentemp(PTR);
				$$->symp->type->ptr = $2->symp->type; 
				emit (ADDRESS, $$->symp->name, $2->symp->name);
				break;
			case '*':
				$$->cat = PTR;
				debug ($2->symp->name);
				$$->loc = gentemp ($2->symp->type->ptr);
				emit (PTRR, $$->loc->name, $2->symp->name);
				$$->symp = $2->symp;
				break;
			case '+':
				$$ = $2;
				break;
			case '-':
				$$->symp = gentemp($2->symp->type->cat);
				emit (UMINUS, $$->symp->name, $2->symp->name);
				break;
			case '~': /* Ignored */
				$$->symp = gentemp($2->symp->type->cat);
				emit (BNOT, $$->symp->name, $2->symp->name);
				break;
			case '!':
				$$->symp = gentemp($2->symp->type->cat);
				emit (LNOT, $$->symp->name, $2->symp->name);
				break;
			default:
				break;
		}
	}
	| SIZEOF unary_expression {	/* Ignored */
		$$ = $2;
	}
	| SIZEOF '(' type_name ')' {	/* Ignored */
		$$->symp = gentemp(_INT, tostr(sizeoftype(new symtype (TYPE))));
	}
	;

unary_operator
	: '&' {
		$$ = '&';
	}
	| '*' {
		$$ = '*';
	}
	| '+' {
		$$ = '+';
	}
	| '-' {
		$$ = '-';
	}
	| '~' {
		$$ = '-';
	}
	| '!' {
		$$ = '!';
	}
	;

cast_expression
	: unary_expression  {
		$$ = $1;
	}
	| '(' type_name ')' cast_expression  /* Ignored */
	{$$ = $4;}
	;

multiplicative_expression
	: cast_expression {
		// Now the cast expression can't go to LHS of assignment_expression
		// So we can safely store the rvalues of pointer and arrays in temporary
		// We don't need to carry lvalues anymore
		$$ = new expr();
		if ($1->cat==ARR) { // Array
			$$->symp = gentemp($1->loc->type);
			emit(ARRR, $$->symp->name, $1->symp->name, $1->loc->name);
		}
		else if ($1->cat==PTR) { // Pointer
			$$->symp = $1->loc;
		}
		else { // otherwise
			$$->symp = $1->symp;
		}
	}
	| multiplicative_expression '*' cast_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			$$ = new expr();
			$$->symp = gentemp($1->symp->type->cat);
			emit (MULT, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	| multiplicative_expression '/' cast_expression{
		if (typecheck ($1->symp, $3->symp) ) {
			$$ = new expr();
			$$->symp = gentemp($1->symp->type->cat);
			emit (DIVIDE, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	| multiplicative_expression '%' cast_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			$$ = new expr();
			$$->symp = gentemp($1->symp->type->cat);
			emit (MODOP, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

additive_expression
	: multiplicative_expression {$$ = $1;}
	| additive_expression '+' multiplicative_expression {
		if (typecheck($1->symp, $3->symp)) {
			$$ = new expr();
			$$->symp = gentemp($1->symp->type->cat);
			emit (ADD, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	| additive_expression '-' multiplicative_expression {
		if (typecheck($1->symp, $3->symp)) {
			$$ = new expr();
			$$->symp = gentemp($1->symp->type->cat);
			emit (SUB, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

shift_expression /* Ignored */
	: additive_expression {$$ = $1;}
	| shift_expression LEFT_OP additive_expression {
		if ($3->symp->type->cat == _INT) {
			$$ = new expr();
			$$->symp = gentemp (_INT);
			emit (LEFTOP, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	| shift_expression RIGHT_OP additive_expression {
		if ($3->symp->type->cat == _INT) {
			$$ = new expr();
			$$->symp = gentemp (_INT);
			emit (RIGHTOP, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

relational_expression
	: shift_expression { $$ = $1;}
	| relational_expression '<' shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			$$->isbool = true;

			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			emit(LT, "", $1->symp->name, $3->symp->name);
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
	| relational_expression '>' shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			$$->isbool = true;

			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			emit(GT, "", $1->symp->name, $3->symp->name);
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
	| relational_expression LE_OP shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			$$->isbool = true;

			$$->truelist = makelist (nextinstr()); 
			$$->falselist = makelist (nextinstr()+1);
			emit(LE, "", $1->symp->name, $3->symp->name);
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
	| relational_expression GE_OP shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			$$->isbool = true;
			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			emit(GE, "", $1->symp->name, $3->symp->name);
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
	;

equality_expression
	: relational_expression {$$ = $1;}
	| equality_expression EQ_OP relational_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// If any is bool get its value
			convertfrombool ($1);
			convertfrombool ($3);
			
			$$ = new expr();
			$$->isbool = true;
			
			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			emit (EQOP, "", $1->symp->name, $3->symp->name);
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
	| equality_expression NE_OP relational_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// If any is bool get its value
			convertfrombool ($1);
			convertfrombool ($3);
			
			$$ = new expr();
			$$->isbool = true;
			
			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			emit (NEOP, $$->symp->name, $1->symp->name, $3->symp->name);
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
	;

and_expression /* Ignored */
	: equality_expression {$$ = $1;}
	| and_expression '&' equality_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			$$ = new expr();
			$$->isbool = false;

			$$->symp = gentemp (_INT);
			emit (BAND, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

exclusive_or_expression /* Ignored */
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// If any is bool get its value
			convertfrombool ($1);
			convertfrombool ($3);

			$$ = new expr();
			$$->isbool = false;

			$$->symp = gentemp (_INT);
			emit (XOR, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

inclusive_or_expression /* Ignored */
	: exclusive_or_expression {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// If any is bool get its value
			convertfrombool ($1);
			convertfrombool ($3);

			$$ = new expr();
			$$->isbool = false;
			
			$$->symp = gentemp (_INT);
			emit (INOR, $$->symp->name, $1->symp->name, $3->symp->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression N AND_OP M inclusive_or_expression {
		convert2bool($5);

		// N to convert $1 to bool
		backpatch($2->nextlist, nextinstr());
		convert2bool($1);

		$$ = new expr();
		$$->isbool = true;

		backpatch($1->truelist, $4);
		$$->truelist = $5->truelist;
		$$->falselist = merge ($1->falselist, $5->falselist);
	}
	;

logical_or_expression
	: logical_and_expression {$$ = $1;}
	| logical_or_expression N OR_OP M logical_and_expression {
		convert2bool($5);

		// N to convert $1 to bool
		backpatch($2->nextlist, nextinstr());
		convert2bool($1);

		$$ = new expr();
		$$->isbool = true;

		backpatch ($1->falselist, $4);
		$$->truelist = merge ($1->truelist, $5->truelist);
		$$->falselist = $5->falselist;
	}
	;

M 	: %empty{	// To store the address of the next instruction for further use.
		$$ = nextinstr();
	};

N 	: %empty { 	// Non terminal to prevent fallthrough by emitting a goto
		debug ("n");
		$$  = new expr();
		$$->nextlist = makelist(nextinstr());
		emit (GOTOOP,"");
		debug ("n2");
	}

conditional_expression
	: logical_or_expression {$$ = $1;}
	| logical_or_expression N '?' M expression N ':' M conditional_expression {
//		convert2bool($5);
		$$->symp = gentemp();
		$$->symp->update($5->symp->type);
		emit(EQUAL, $$->symp->name, $9->symp->name);
		lint l = makelist(nextinstr());
		emit (GOTOOP, "");

		backpatch($6->nextlist, nextinstr());
		emit(EQUAL, $$->symp->name, $5->symp->name);
		lint m = makelist(nextinstr());
		l = merge (l, m);
		emit (GOTOOP, "");

		backpatch($2->nextlist, nextinstr());
		convert2bool ($1);
		backpatch ($1->truelist, $4);
		backpatch ($1->falselist, $8);
		backpatch (l, nextinstr());
	}
	;

assignment_expression
	: conditional_expression {
		$$ = $1;
	}
	| unary_expression assignment_operator assignment_expression {
		switch ($1->cat) {
			case ARR:
				$3->symp = conv($3->symp, $1->type->cat);
				emit(ARRL, $1->symp->name, $1->loc->name, $3->symp->name);	
				break;
			case PTR:
				emit(PTRL, $1->symp->name, $3->symp->name);	
				break;
			default:
				$3->symp = conv($3->symp, $1->symp->type->cat);
				emit(EQUAL, $1->symp->name, $3->symp->name);
				break;
		}
		$$ = $3;
	}
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression {
		$$ = $1;
	}
	| expression ',' assignment_expression
	{printf("expression\n");}
	;

constant_expression
	: conditional_expression
	{printf("constant_expression\n");}
	;

/*** Declaration ***/

declaration
	: declaration_specifiers ';' {

	}
	| declaration_specifiers init_declarator_list ';' {
		debug ("declaration");
	}
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	| function_specifier 
	| function_specifier declaration_specifiers
	{printf("declaration_specifiers\n");}
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator {
		debug("init_declarator_list");
	}
	;

init_declarator
	: declarator {
		$$ = $1;
	}
	| declarator '=' initializer {
		debug ($1->name);
		debug ($3->name);
		debug ($3->init);

		if ($3->init!="") $1->initialize($3->init);
		emit (EQUAL, $1->name, $3->name);
		debug ("here init");
	}
	;

storage_class_specifier
	: EXTERN
	| STATIC
	| AUTO
	| REGISTER
	{printf("storage_class_specifier\n");}
	;

type_specifier
	: VOID {
		TYPE = _VOID;
	}
	| CHAR {
		TYPE = _CHAR;
	}
	| SHORT
	| INT {
		TYPE = _INT;
	}
	| LONG
	| FLOAT
	| DOUBLE {
		TYPE = _DOUBLE;
	}
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY
	| enum_specifier
	{printf("type_specifier\n");}
	;



specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	{printf("specifier_qualifier_list\n");}
	;


enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	{printf("enum_specifier\n");}
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	{printf("enumerator_list\n");}
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	{printf("enumerator\n");}
	;

type_qualifier /* Ignored */
	: CONST
	| VOLATILE
	| RESTRICT
	{printf("type_qualifier\n");}
	;

function_specifier /* Ignored */
	: INLINE
	{printf("function_specifier\n");}
	;

declarator
	: pointer direct_declarator {
		symtype * t = $1;
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = $2->type;
		$$ = $2->update($1);
	}
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER {
		$$ = $1->update(TYPE);
		debug ("currsym: "<< $$->name);
		currsym = $$;
	}
	| '(' declarator ')' {
		$$ = $2;
	}
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' assignment_expression ']' {
		symtype * t = $1 -> type;
		symtype * prev = NULL;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}
		if (prev==NULL) {
			int x = atoi($3->symp->init.c_str());
			symtype* s = new symtype(ARR, $1->type, x);
			int y = sizeoftype(s);
			$$ = $1->update(s);
		}
		else {
			prev->ptr =  new symtype(ARR, t, atoi($3->symp->init.c_str()));
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator '[' ']' {
		symtype * t = $1 -> type;
		symtype * prev = NULL;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}
		if (prev==NULL) {
			symtype* s = new symtype(ARR, $1->type, 0);
			int y = sizeoftype(s);
			$$ = $1->update(s);
		}
		else {
			prev->ptr =  new symtype(ARR, t, 0);
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '(' CST parameter_type_list ')' {
		table->tname = $1->name;

		if ($1->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");
			s->update($1->type);		
		}

		$1 = $1->linkst(table);

		table->parent = gTable;
		changeTable (gTable);				// Come back to globalsymbol table
	
		debug ("currsym: "<< $$->name);
		currsym = $$;						
	}
	| direct_declarator '(' identifier_list ')' { /* Ignored */

	}
	| direct_declarator '(' CST ')' {		
		table->tname = $1->name;			// Update function symbol table name

		if ($1->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");// Update type of return value
			s->update($1->type);
		}
		
		$1 = $1->linkst(table);		// Update type of function in global table
	
		table->parent = gTable;
		changeTable (gTable);				// Come back to globalsymbol table
	
		debug ("currsym: "<< $$->name);
		currsym = $$;
	}
	;

CST : %empty { // Used for changing to symbol table for a function
		if (currsym->nest==NULL) changeTable(new symtab(""));	// Function symbol table doesn't already exist
		else {
			changeTable (currsym ->nest);						// Function symbol table already exists
			emit (FUNC, table->tname);
		}
	}
	;

pointer
	: '*' {
		$$ = new symtype(PTR);
	}
	| '*' type_qualifier_list {} /* Ignored */
	| '*' pointer {
		$$ = new symtype(PTR, $2);
	}
	| '*' type_qualifier_list pointer /* Ignored */
	{printf("pointer\n");}
	;

type_qualifier_list /* Ignored */
	: type_qualifier
	| type_qualifier_list type_qualifier
	{printf("type_qualifier_list\n");}
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	{printf("parameter_type_list\n");}
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration {
		debug("parameter_list");
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		debug ("here");
		$2->category = "param";
	}
	| declaration_specifiers
	{printf("parameter_declaration\n");}
	;

identifier_list
	: IDENTIFIER 
	| identifier_list ',' IDENTIFIER
	{printf("identifier_list\n");}
	;

type_name
	: specifier_qualifier_list
	{printf("type_name\n");}
	;


initializer
	: assignment_expression {
		$$ = $1->symp;
	}
	| '{' initializer_list '}' {}
	| '{' initializer_list ',' '}'
	{printf("initializer\n");}
	;

initializer_list
	: initializer
	| designation initializer
	| initializer_list ',' initializer
	|  initializer_list ',' designation initializer
	{printf("initializer_list\n");}
	;

designation
	: designator_list '='
	{printf("designation\n");}
	;

designator_list
	: designator
	| designator_list designator
	{printf("designator_list\n");}
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	{printf("designator\n");}
	;

statement
	: labeled_statement /* Skipped */
	| compound_statement {
		$$ = $1;
		debug("Compound Statement");
	}
	| expression_statement {
		$$ = new statement();
		$$->nextlist = $1->nextlist;
		debug("Expression Statement");
	}
	| selection_statement {
		$$ = $1;
		debug("selection statement\n");
	}
	| iteration_statement {
		$$ = $1;
		debug("iteration statement");
	}
	| jump_statement {
		$$ = $1;
		debug("jump statement");
	}
	;

labeled_statement /* Ignored */
	: IDENTIFIER ':' statement {$$ = new statement();}
	| CASE constant_expression ':' statement {$$ = new statement();}
	| DEFAULT ':' statement {$$ = new statement();}
	;

compound_statement
	: '{' '}' { $$ = new statement();}
	| '{' block_item_list '}' {
		$$ = $2;
	}
	;

block_item_list
	: block_item {
		$$ = $1;		
	}
	| block_item_list M block_item {
		$$ = $3;
	/*	
		debug ("M.instruction = " << $2);

		if (gDebug) {
			debug ("1 contains: ");
			printlist($1->nextlist);
		} 

		if (gDebug) {
			debug ("3 contains: ");
			printlist($3->nextlist);
		} 
	*/
		backpatch ($1->nextlist, $2);
	//	debug ("backpatching 1 done");
	}
	;

block_item
	: declaration { 
		$$ = new statement();
	/*	debug ("-------------------------------------------------");
		debug ("declaration next instruction");
		if (gDebug) {
			printlist($$->nextlist);
		} 
	*/
	}
	| statement {
		$$ = $1;
	/*	debug ("-------------------------------------------------");
		debug ("statement next instruction");
		if (gDebug) {
			printlist($$->nextlist);
		} 
	*/
	}
	;

expression_statement
	: ';' {	$$ = new expr();}
	| expression ';' {
		$$ = $1;
	}
	;

selection_statement
	: IF '(' expression N ')' M statement N {
		backpatch ($4->nextlist, nextinstr());
		convert2bool($3);
		$$ = new statement();
		backpatch ($3->truelist, $6);
		lint temp = merge ($3->falselist, $7->nextlist);
		$$->nextlist = merge ($8->nextlist, temp);
		
	}
	| IF '(' expression N ')' M statement N ELSE M statement {
		backpatch ($4->nextlist, nextinstr());
		convert2bool($3);
		$$ = new statement();
		backpatch ($3->truelist, $6);
		backpatch ($3->falselist, $10);
		lint temp = merge ($7->nextlist, $8->nextlist);
		$$->nextlist = merge (temp, $11->nextlist);
	}
	| SWITCH '(' expression ')' statement /* Skipped */
	{printf("selection_statement\n");}
	;

iteration_statement 	
	: WHILE M '(' expression ')' M statement { 
		$$ = new statement();
		convert2bool($4);
		// M1 to go back to boolean again
		// M2 to go to statement if the boolean is true
		backpatch($7->nextlist, $2);
		backpatch($4->truelist, $6);
		$$->nextlist = $4->falselist;
		// Emit to prevent fallthrough
		emit (GOTOOP, tostr($2));
	}
	| DO M statement M WHILE '(' expression ')' ';' {
		$$ = new statement();
		convert2bool($7);
		// M1 to go back to statement if expression is true
		// M2 to go to check expression if statement is complete
		backpatch ($7->truelist, $2);
		backpatch ($3->nextlist, $4);

		// Some bug in the next statement
		$$->nextlist = $7->falselist;

	}
	| FOR '(' expression_statement M expression_statement ')' M statement {
		$$ = new statement();
		convert2bool($5);
		backpatch ($5->truelist, $7);
		backpatch ($8->nextlist, $4);
		emit (GOTOOP, tostr($4));
		$$->nextlist = $5->falselist;
	}
	| FOR '(' expression_statement M expression_statement M expression N ')' M statement {
		$$ = new statement();
		convert2bool($5);
		backpatch ($5->truelist, $10);
		backpatch ($8->nextlist, $4);
		backpatch ($11->nextlist, $6);
		emit (GOTOOP, tostr($6));
		$$->nextlist = $5->falselist;
	//	debug ("for done");
	}
	;

jump_statement /* Ignored except return */
	: GOTO IDENTIFIER ';' {$$ = new statement();}
	| CONTINUE ';' {$$ = new statement();}
	| BREAK ';' {$$ = new statement();}
	| RETURN ';' {
		$$ = new statement();
		emit(_RETURN,"");
	}
	| RETURN expression ';'{
		$$ = new statement();
	//	if (table->lookup("retVal")->type->cat==$2->symp->type->cat) {
			emit(_RETURN,$2->symp->name);
	//	}
	//	else yyerror("Wrong return type\n");			

	}
	;

translation_unit
	: external_declaration 
	| translation_unit external_declaration {
//		if (gDebug) table->printall();
	}
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list CST compound_statement {

	}
	| declaration_specifiers declarator CST compound_statement {
//		table->tname = $2->name;
		
		emit (FUNCEND, table->tname);
		table->parent = gTable;
		changeTable (gTable);
	}
	;
declaration_list
	: declaration
	| declaration_list declaration
	{printf("declaration_list\n");}
	;

%%

void yyerror(const char *s) {
	printf ("ERROR: %s",s);
}
