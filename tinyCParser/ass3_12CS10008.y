%{ /* C Declarations and Definitions */
	#include <string.h>
	#include <stdio.h>

	extern int yylex();
	void yyerror(char *s);
%}

%union {
int intval;
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

%token IDENTIFIER STRING_LITERAL PUNCTUATORS COMMENT
%token INT_CONSTANT FLOAT_CONSTANT ENU_CONSTANT CHAR_CONSTANT

%start translation_unit

%%

primary_expression
	: IDENTIFIER
	| constant
	| STRING_LITERAL
	| '(' expression ')'
	{printf("primary_expression\n");}
	;

constant
	: INT_CONSTANT 
	| FLOAT_CONSTANT 
	| ENU_CONSTANT 
	| CHAR_CONSTANT
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	|  '(' type_name ')' '{' initializer_list ',' '}'
	{printf("postfix_expression\n");}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	{printf("argument_expression_list\n");}
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	{printf("unary_expression\n");}
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	{printf("unary_operator\n");}
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	{printf("cast_expression\n");}
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	{printf("multiplicative_expression\n");}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	{printf("additive_expression\n");}
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	{printf("shift_expression\n");}
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	{printf("relational_expression\n");}
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	{printf("equality_expression\n");}
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	{printf("and_expression\n");}
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	{printf("exclusive_or_expression\n");}
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	{printf("inclusive_or_expression\n");}
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	{printf("logical_and_expression\n");}
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	{printf("logical_or_expression\n");}
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	{printf("conditional_expression\n");}
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	{printf("assignment_expression\n");}
	;

assignment_operator
	: '='
	{printf("assignment_operator\n");}
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
	{printf("assignment_operator\n");}
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	{printf("expression\n");}
	;

constant_expression
	: conditional_expression
	{printf("constant_expression\n");}
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	{printf("declaration\n");}
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
	| init_declarator_list ',' init_declarator
	{printf("init_declarator_list\n");}
	;

init_declarator
	: declarator
	| declarator '=' initializer
	{printf("init_declarator\n");}
	;

storage_class_specifier
	: EXTERN
	| STATIC
	| AUTO
	| REGISTER
	{printf("storage_class_specifier\n");}
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
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

type_qualifier
	: CONST
	| VOLATILE
	| RESTRICT
	{printf("type_qualifier\n");}
	;
function_specifier
	: INLINE
	{printf("function_specifier\n");}
	;
declarator
	: pointer direct_declarator
	| direct_declarator
	{printf("declarator\n");}
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '['  type_qualifier_list_opt assignment_expression_opt ']'
	| direct_declarator '[' STATIC type_qualifier_list_opt assignment_expression ']'
	| direct_declarator '[' type_qualifier_list_opt '*' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	{printf("direct_declarator\n");}
	;

type_qualifier_list_opt
	: %empty
	| type_qualifier_list
	{printf("type_qualifier_list_opt\n");}
	;
assignment_expression_opt
	: %empty
	| assignment_expression
	{printf("assignment_expression_opt\n");}
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	{printf("pointer\n");}
	;

type_qualifier_list
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
	| parameter_list ',' parameter_declaration
	{printf("parameter_list\n");}
	;

parameter_declaration
	: declaration_specifiers declarator
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
	: assignment_expression
	| '{' initializer_list '}'
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
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	{printf("statement\n");}
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	{printf("labeled_statement\n");}
	;

compound_statement
	: '{' '}'
	| '{' block_item_list '}'
	{printf("compound_statement\n");}
	;

block_item_list
	: block_item
	| block_item_list block_item
	{printf("block_item_list\n");}
	;

block_item
	: declaration
	| statement
	{printf("block_item\n");}
	;


expression_statement
	: ';'
	| expression ';'
	{printf("expression_statement\n");}
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	{printf("selection_statement\n");}
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	{printf("iteration_statement\n");}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	
	{printf("jump_statement\n");}
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	{printf("translation_unit\n");}
	;

external_declaration
	: function_definition
	| declaration
	{printf("external_declaration\n");}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	{printf("function_definition\n");}
	;
declaration_list
	: declaration
	| declaration_list declaration
	{printf("declaration_list\n");}
	;

%%
void yyerror(char *s) {
	printf ("ERROR: %s",s);
}