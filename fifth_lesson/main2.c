#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define BOOL int

#define SUM(x, y) (x + y)
#define SQ(x) (x * x)
#define NEGYZET(x) ((x) * (x))

#define GET_ARRAY_SIZE(array) sizeof(array) / sizeof(array[0])

BOOL is_div(int n, int m)
{
	return (n % m == 0) ? TRUE : FALSE;
}

int main(int argc, char **argv)
{
	/*for(int i = 1; i < 10; i++)
		if(is_div(i + 3, i)) printf("%d osztoja %d (nak/nek)\n", i, (i+3));
		else printf("%d nem osztoja %d (nak/nek)\n", i, (i+3));
		
	printf("Sum of 10 and 20: %d\n", SUM(10,20));
	printf("Sq of 5 is: %d\n", SQ(5));
	printf("Sq of 2 + 6 is: %d\n", SQ(SUM(2, 6)));
	printf("Sq of 2 + 6 is (bad): %d\n", SQ(2 + 6));
	printf("Sq of 2 + 6 is (good): %d\n", NEGYZET(2 + 6));*/
	
	int arr[20];
	printf("Array size: %d\n", GET_ARRAY_SIZE(arr));
	return 0;
}

