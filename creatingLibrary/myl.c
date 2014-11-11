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
	if(s[i] != '\0') 
		while(s[i]!='\0') i++;
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
		) ; // $3: read, $1: on stdin
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
	int sign=1;
	if (f<0) sign = -1;
	int ret = 0;
	ret += printi(a);					// Print integer part
	char dot[2] =".";
	prints (dot);
	f = f-a;
	f*=sign;
	while (f-(int)f != 0) f*=10; 		// Ectract decimal part
	ret += printi(f);					// Print decimal part
	return ret+1;
}
int readf (float *fP) {
	int x = 0, frac = 0, zero='0';
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
		if (i==0 && c=='-') sign = -1;
		else {
			if (c=='.') {
				if (readi(&frac)) return ERR;
				break;
			}
			if (c=='\n') break;
			if (c>'9' || c<'0') return ERR;
			x = x*10 + (int) (c - zero);
		}
		i++;
	}
	float f = frac;
	while ((int)f !=0) f/=10;			// fractional part
	f+=x;								// int part
	f*=sign;							// Sign
	*fP = f;
	return OK;
}
