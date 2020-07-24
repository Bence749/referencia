#include "function.h"
#include <stdio.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort(int *arr, int size)
{
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
}
