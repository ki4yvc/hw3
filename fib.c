#include <stdio.h>
int fib(int in);
int main() {
	int v = 6;

	printf("%d\n", fib(v));
}

int fib(int in) {
	if (in == 0 || in == 1)
	{	
	 	return 1;
	}
	printf("in was : %d\n", in);
	printf("in - 1 was : %d in - 2 was : %d\n", in-1, in-2);
	printf("-----------------------------\n");
	return fib(in - 1) + fib(in - 2);

}