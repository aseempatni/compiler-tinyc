#include <stdio.h>
#include "myl.h"

int main () {
	int i = printi(1234);
	printf ("\ti = %d\n",i);

	float f = 12.12;
	i = printd(f);
	printf ("\ti = %d\n",i);

	char s[10] = "abcdefg";
	i = prints(s);
	printf ("\ti = %d\n",i);
/*
	int a;
	i = readi(&a);
	printf ("\ti = %d\n",i);
	printf ("\ta = %d\n",a);
*/

	return 0;
}