#define _CRT_SECURE_NO_WARNINGS

/*  Recursive Factorial */ 
// f(n) = n*f(n-1)	... n>=1
// f(n) = 1			... n=0

#include<stdio.h>

int Factorial(int num)
{
	if (num == 0) {
		return 1;
	}
	else
	{
		return num * Factorial(num - 1);
	}
}

int main(void) 
{
	int num;

	scanf("%d", &num);
	printf("%d! = %d",num,Factorial(num));

	return 0;
}
