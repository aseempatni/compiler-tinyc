// Test Expressions
int testfile = 1;
int main () {
	int a=1, b=2, c;
	c = a + b;
	a++;
	int check = a==b;
	if (check < c) 
		c = a|b;
}