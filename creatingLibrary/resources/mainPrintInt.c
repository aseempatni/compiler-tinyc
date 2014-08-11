/* 
 * main_print_int.c 
 * A system call to print an integer 
 */
#include <stdio.h>
#include "printInt.h"
int main()
{ 
    int n;

    printf("Enter an integer: ");     
    scanf("%d", &n);
    print_int(n);
    return 0;
}
