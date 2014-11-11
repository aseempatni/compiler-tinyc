#include <stdio.h>
#include "y.tab.h"
extern "C" {
  char* yytext;
  int yyparse();
}
int main() {
  int token;
  yyparse();
  return 0;
}