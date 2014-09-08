#include <stdio.h>
#include "y.tab.h"
extern char* yytext;
extern int yyparse();
int main() {
  int token;
  yyparse();
  return 0;
  /*
  while (token = yylex()) {
    switch (token) {
      // Identifier
      case IDENTIFIER: printf("<IDENTIFIER, %d, %s>\n",
        token, yytext); break;
      // Constant
      case INT_CONSTANT: printf("<INT_CONSTANT, %d, %s>\n",
        token, yytext); break;
      case FLOAT_CONSTANT: printf("<FLOAT_CONSTANT, %d, %s>\n",
        token, yytext); break;
      case ENU_CONSTANT: printf("<ENU_CONSTANT, %d, %s>\n",
        token, yytext); break;
      case CHAR_CONSTANT: printf("<CHAR_CONSTANT, %d, %s>\n",
        token, yytext); break;
      // String Literals
      case STRING: printf("<STRING LITERAL, %d, %s>\n",
        token, yytext); break;
      case PUNCTUATORS: printf("<PUNCTUATORS, %d, %s>\n",
        token, yytext); break;
      // Comments // Multi line comments are ignored
      case COMMENT: 
        printf("<COMMENT, %d>\n",token); break;
      // Keyword
      case BREAK:
      case AUTO:
      case CASE:
      case CHAR:
      case CONST:
      case CONTINUE:
      case DEFAULT:
      case DO:
      case DOUBLE:
      case ELSE:
      case ENUM:
      case EXTERN:
      case FLOAT:
      case FOR:
      case GOTO:
      case IF:
      case INLINE:
      case INT:
      case LONG:
      case REGISTER:
      case RESTRICT:
      case RETURN:
      case SHORT:
      case SIGNED:
      case SIZEOF:
      case STATIC:
      case STRUCT:
      case SWITCH:
      case TYPEDEF:
      case UNION:
      case UNSIGNED:
      case VOID:
      case VOLATILE:
      case WHILE:
      case BOOL:
      case COMPLEX:
      case IMAGINARY:
      printf("<KEYWORD, %d, %s>\n",token, yytext); break;
    // Punctuators
      default: printf("<PUNCTUATOR, %d, %s>\n",
        token, yytext); break;
    }
  }
  */
}