#include "fugg.h"
#include <stdio.h>

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

int sort(int* x, int xSize, int* y, int ySize, int* z, int zSize)
{
	int i = 0, j = 0, k = 0, newSize = zSize;
	while(i < xSize || j < ySize)
		{
			if((j >= xSize || i < ySize && x[i] <= y[j]))
			{
				if(contain(z, zSize, x[i]) == 0)
				{
					z[k] = x[i];
					k++;
				}
				else
					newSize--;
				i++;
			} else
			{
				if(contain(z, zSize, y[j]) == 0)
				{
					z[k] = y[j];
					k++;
				}	
				else
					newSize--;
				j++;
			}

		}
	return newSize;
}

int contain(int* x, int xSize, int a)
{
	for(int i = 0; i < xSize; i++)
		if(x[i] == a)
			return 1;
	return 0;
}
