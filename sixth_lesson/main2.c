#include <stdio.h>
#include "function.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

int main(int argc, char **argv)
{
	int array[] = {3, 5, 7, 3, 8, 12, 54};
	sort(array, ARRAY_SIZE(array));
	for(int i = 0; i < ARRAY_SIZE(array); i++)
		printf("%d ", array[i]);
	return 0;
}
