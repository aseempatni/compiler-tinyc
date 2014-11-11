#include <stdio.h>
#include "myl.h"

void printStatus (int status) {
	if (status) printf("Error!\n");
	else printf("OK\n");
}
int main () {
	int n;

	int i;
	prints ("Enter an integer: ");
	printStatus (readi(&i));
	prints("Printing the read integer: ");
	n = printi(i);
	printf("\n%d characters printed\n",n);

	float f;
	prints ("Enter an float: ");
	printStatus (readf(&f));
	prints("Printing the read integer: ");
	n = printd(f);
	printf("\n%d characters printed\n",n);

	char s[10] = "abcdefg";
	i = prints(s);
	printf ("\ti = %d\n",i);

	return 0;
}