#define _CRT_SECURE_NO_WARNINGS

/*  Fibonacci Sequence */
// fib(n) = 0					... n=1
// fib(n) = 1					... n=2
// fib(n) = fib(n-1)*fib(n-1)	... otherwise

#include<stdio.h>

int Fibo(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 2) + Fibo(n - 1);
	
}

int main(void)
{
	int i;
	for (i = 1; i < 15; i++)
		printf("%d ", Fibo(i));

	return 0;
}