int prints(char *c);
int printi(int i);
int readi(int *eP);
int main () {
	int a = 5, b = 2, c;
	c = a+b;
	c = a-b;
	c = a*b;
	c = a/b;
	if (a<b) {
		a++;
	}
	else {
		c = a+b;
	}
	return;
}
//int a = 5;
//char c = 'a';
int add (int a, int b) {
	int c = 2, d, arr[10];
	int*p;
	int read;
	read = 5;
	c = printi(read);
	if (a>=d) {
		a++;
	}
	else {
		c = a+b;
	}
	b=*p;
	a++;
	*p=a;
	c = add(a,b);
	a = -a;
	arr[d] = a;
	arr[2] = a;
	a = arr[c];
	return c;
}