/*
* ass1.c Generate assembly code of x86-32 and comment
*/
#include <stdio.h>
#define ORD 20
void cs(int n, int data[][ORD]);
void po(int n, int data[][ORD], int type, int ind);
int main() {
	int n, i, j ;
	int data[ORD][ORD];
	printf("Enter the order of the square matrix: ");
	scanf("%d", &n);
	printf("Enter the matrix in row-major order:\n");
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j) scanf("%d", &data[i][j]);
	printf("The input matrix is:\n");
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j) printf("%d ", data[i][j]);
			putchar('\n');
	}
	printf("In cs order:\n");
	cs(n,data);
	return 0;
}
void cs(int n, int data[][ORD]){
	if(n == 0) {
		putchar('\n');
		return;
	}
	if(n == 1) {
		printf("%d\n", data[0][0]);
		return ;
	}
	po(n, data, 1, 0);
	cs(n-2, (int (*)[ORD])(&data[1][1]));
}

void po(int n, int data[][ORD], int type, int ind){
	switch(type){
		case 1:
		if(ind == n-1) po(n, data, 2, 0);
		else {
			printf("%d ", data[0][ind]);
			po(n, data, 1, ind+1);
		}
		return ;
		case 2:
		if(ind == n-1) po(n, data, 3, n-1);
		else {
			printf("%d ", data[ind][n-1]);
			po(n, data, 2, ind+1);
		}
		return ;
		case 3:
		if(ind == 0) po(n, data, 4, n-1);
		else {
			printf("%d ", data[n-1][ind]);
			po(n, data, 3, ind-1);
		}
		return ;
		case 4:
		if(ind == 0) return ;
		else {
			printf("%d ", data[ind][0]);
			po(n, data, 4, ind-1);
		}
		return ;
	}
}