%{
#include "ass6_12CS10008_translator.h"

#include "y.tab.h"
#include <math.h>
void yyerror (char *);  /* prints grammar violation message */
void count(void);
void comment (void);
%}

/* Regular Expression Definitions */

D					[0-9]
L 			 		[a-zA-Z_]
ID 					{L}({L}|{D})*
nonzero-digit		[1-9]
E					([Ee][+-]?{D}+)
IC 					[0]|{nonzero-digit}{D}*
FC 					({FRC}{E}?)|({D}+{E})
FRC 				(({D}+)?\.{D}+)|(({D}+)\.)
 
EC 					{ID}
ESC_SEQ				\\['"?\\abfnrtv]
cchar 				[^'\\\n]|{ESC_SEQ}
CC 					'({cchar})+'

schar 				[^"\\\n]|{ESC_SEQ}
SC 					\"({schar}+)\"

WS  				[ \t\v\n\f]
%%

"/*"			{ comment(); }
"//".*  	   	{  /* consume //-comment */ }

"auto"			{ return AUTO; }
"break"         { return BREAK; }
"case"          { return CASE; }
"char"          { return CHAR; }
"const"         { return CONST; }
"continue"      { return CONTINUE; }
"default"       { return DEFAULT; }
"do"            { return DO; }
"double"        { return DOUBLE; }
"else"          { return ELSE; }
"enum"          { return ENUM; }
"extern"        { return EXTERN; }
"float"         { return FLOAT; }
"for"           { return FOR; }
"goto"          { return GOTO; }
"if"            { return IF; }
"inline"        { return INLINE; }
"int"           { return INT; }
"long"          { return LONG; }
"register"      { return REGISTER; }
"restrict"      { return RESTRICT; }
"return"        { return RETURN; }
"short"         { return SHORT; }
"signed"        { return SIGNED; }
"sizeof"        { return SIZEOF; }
"static"        { return STATIC; }
"struct"        { return STRUCT; }
"switch"        { return SWITCH; }
"typedef"       { return TYPEDEF; }
"union"         { return UNION; }
"unsigned"      { return UNSIGNED; }
"void"          { return VOID; }
"volatile"      { return VOLATILE; }
"while"         { return WHILE; }
"_Bool"         { return BOOL; }
"_Complex"      { return COMPLEX; }
"_Imaginary"    { return IMAGINARY; }

{SC} 			{ 	yylval.strval = yytext;
					return STRING_LITERAL; }
{ID}			{	yylval.symp = table->lookup(yytext);
					return IDENTIFIER;  }
{IC} 			{ 	yylval.intval = atoi(yytext);
					return INT_CONSTANT; }
{FC} 			{ 	yylval.strval = yytext;
					return FLOAT_CONSTANT; }
{CC} 			{ 	yylval.charval = yytext[1];
					return CHAR_CONSTANT; }

"["				{ return '['; }
"]"				{ return ']'; }
"("				{ return '('; }
")"				{ return ')'; }
"{"				{ return '{'; }
"}"				{ return '}'; }
"."				{ return '.'; }
"->"			{ return PTR_OP; }

"++"			{ return INC_OP; }
"--"			{ return DEC_OP; }
"&"				{ return '&'; }
"*"				{ return '*'; }
"+"				{ return '+'; }
"-"				{ return '-'; }
"~"				{ return '~'; }
"!"				{ return '!'; }

"/"				{ return '/'; }
"%"				{ return '%'; }
"<<"			{ return LEFT_OP; }
">>"			{ return RIGHT_OP; }
"<"				{ return '<'; }
">"				{ return '>'; }
"<="			{ return LE_OP; }
">="			{ return GE_OP; }
"=="			{ return EQ_OP; }
"!="			{ return NE_OP; }
"^"				{ return '^'; }
"|"				{ return '|'; }
"&&"			{ return AND_OP; }
"||"			{ return OR_OP; }

"?"				{ return '?'; }
":"				{ return ':'; }
";"				{ return ';'; }
"..."			{ return ELLIPSIS; }

"="				{ return '='; }
"*="			{ return MUL_ASSIGN; }
"/="			{ return DIV_ASSIGN; }
"%="			{ return MOD_ASSIGN; }
"+="			{ return ADD_ASSIGN; }
"-="			{ return SUB_ASSIGN; }
"<<="			{ return LEFT_ASSIGN; }
">>="			{ return RIGHT_ASSIGN; }
"&="			{ return AND_ASSIGN; }
"^="			{ return XOR_ASSIGN; }
"|="			{ return OR_ASSIGN; }

","				{ return ','; }
"#"				{ return '#'; }

{WS}			{ /* whitespace separates tokens */ }
%%

int column = 0;
void count(void) {
	int i;
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n') column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	ECHO;
}
void comment(void) {
	char c, prev = 0;
	while ((c = getchar()) != 0) {     /* (EOF maps to 0) */
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
//	yyerror("unterminated comment");
}