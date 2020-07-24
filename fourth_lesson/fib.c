#include "fib.h"
#include <stdio.h>

int fibonacci(int n)
{
	if(n <= 1) return n;
	else return (fibonacci(n - 1) + fibonacci(n - 2));
}

int max(int a, int b)
{
	/*if(a > b) return a;
	else return b;*/
	
	return (a > b) ? a : b;
}

int isPalidron(int x)
{
	int n = x, reverse = 0;
	while (n != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + n % 10;
		n = n / 10;
	}
	return (x == reverse) ? 1 : 0;
}

void tillNotOne(int input)
{
	if (input < 1)
		printf("Anyáddal szórakozz!!!!\n");
	while(input != 1 && input >= 1)
	{
		(input % 2 == 0) ? (input /= 2) : (input = 3 * input + 1);
		printf("%d\n", input);
	}
	
}
