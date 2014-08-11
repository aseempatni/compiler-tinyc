#include "myl.h"
#define BUFF 20
int printi(int n){
	char buff[BUFF], zero='0';
	int i=0, j, k, bytes;
	if(n == 0) buff[i++]=zero;
	else{
		if(n < 0) {
			buff[i++]='-';
			n = -n;
		}
		while(n) {
			int dig = n%10;
			buff[i++] = (char)(zero+dig);
			n /= 10;
		}
		if(buff[0] == '-') j = 1;
		else j = 0;
		k=i-1;
		while(j<k){
			char temp=buff[j];
			buff[j++] = buff[k];
			buff[k--] = temp;
		}
	}
	bytes = i;
	__asm__ __volatile__ (
		"movl $4, %%eax \n\t"
		"movl $1, %%ebx \n\t"
		"int $128 \n\t"
		:
		:"c"(buff), "d"(bytes)
	) ; // $4: write, $1: on stdin
	return bytes;
}
int prints (char* s) {
	int i=0, bytes;
	if(s[i] == '\0') bytes =1;
	else{
		while(s[i]!='\0') {
			i++;
		}
	}
	bytes = i+1;
	__asm__ __volatile__ (
		"movl $4, %%eax \n\t"
		"movl $1, %%ebx \n\t"
		"int $128 \n\t"
		:
		:"c"(s), "d"(bytes)
	) ; // $4: write, $1: on stdin
	return bytes;
}
int readi (int* eP) {
	int x=0,zero='0';
	int i=0, sign=1;
	char c='\0';
	while (1) {
		__asm__ __volatile__ (
			"movl $3, %%eax \n\t"
			"movl $0, %%ebx \n\t"
			"int $128 \n\t"
			:
			:"c"(&c), "d"(1)
		) ; // $4: write, $1: on stdin
		if (i==0 && c=='-') {
			sign = -1;
		}
		else {
			if (c=='\n') break;
			if (c>'9' || c<'0') return ERR;
			x = x*10 + (int) (c - zero);
		}
		i++;
	}
	x = sign*x;
	*eP = x;
	return OK;
}
int printd (float f) {
	int a = f/1;
	printi(a);
	char dot[2] =".";
	prints (dot);
	int b=0;
	f = f-a;
	float g=f;
	while ( g != 0) {
		f *= 10;
		a = f/1;
		g = f-a;
	}
	b=f;
	printi(b);
	return OK;
}

int readf (float *fP) {
	int i=0,j,k,dot=-1,dcount=0;
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
				return ERR;
		}
	}

	if(buff[0]=='-'){
		if(dot==-1){
			sum=0;
			for(j=1;j<i;j--){
				sum+=(buff[j]-48) + sum*10;
			}
			sum=sum*(-1);
			*fP=sum;
			return OK;
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
			sum=0;
			for(j=0;j<i;j--){
				sum+=(buff[j]-48) + sum*10;
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