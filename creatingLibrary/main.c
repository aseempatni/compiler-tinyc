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

int readf (float *fP) {
	int BUFF=20,i=0,j,k,dot=-1,dcount=0;
	char buff[BUFF];
	float sum;
	buff[0]='\0';
	while(1){
		__asm__ __volatile__ (
			"movl $3, %%eax \n\t"
			"movl $0, %%ebx \n\t"
			"int $128 \n\t"
			:
			:"c"(buff+i), "d"(1)
           ) ;  // $3: read, $1: on stdin
		if(buff[i]=='\n')
			break;
		if(buff[i]==46){
			dcount++;
			dot=i;
		}
		i++;
	}
	if(dcount>=2 || dot==0 || dot==i-1)
		return ERR;
	if(dot==-1 && buff[0]=='0')
		return ERR;
	int count=i-1;
	for(i=1;i<=count;i++){
		if(!(buff[i]>=48 && buff[i]<=57)){
			if(buff[i]!=46)
				return 1;
		}
	}

	if(buff[0]=='-'){
		if(dot==-1){
			sum=0;k=0;
			for(j=i-1;j>=1;j--){

				sum+=(buff[j]-48)*power(10,k);
				k++;
			}
			sum=sum*(-1);
			*fP=sum;
			return 0;
		}
		sum=0;k=dot-2;
		for(j=1;j<=i-1;j++){

			if(buff[j]==46){
				continue;
			}
			sum+=(buff[j]-48)*powerf(10,k);
			k--;
		}
		sum=sum*(-1);
		*fP=sum;

		return OK;
	}

	else{
		if(dot==-1){
			sum=0;k=0;
			for(j=i-1;j>=0;j--){
				sum+=(buff[j]-48)*power(10,k);
				k++;
			}
			*fP=sum;
			return OK;
		}
		sum=0;k=dot-1;
		for(j=0;j<=i-1;j++){
			if(buff[j]==46){
				continue;
			}
			sum+=(buff[j]-48)*powerf(10,k);
			k--;
		}
		*fP=sum; 
		return OK;
	}
}