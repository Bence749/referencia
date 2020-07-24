#include <stdio.h>
#include <stdlib.h>
#include "fugg.c"


int main(int argc, char **argv)
{
	int size = 200;
	int* t1 = (int*)calloc(size, sizeof(int)); 
	int* t2 = (int*)calloc(size, sizeof(int)); 
	int* t3 = (int*)calloc((2*size), sizeof(int));
	for(int i = 0; i < size; i++)
	{
		t1[i] = i;
		t2[i] = i+50; 
	}
	int newSize = sort(t1, ARRAY_SIZE(t1), t2, ARRAY_SIZE(t2), t3, ARRAY_SIZE(t3)); 
	t3 = (int*)realloc(t3, newSize);
	for(int i = 0; i < ARRAY_SIZE(t3); i++)
		printf("%d\n", t3[i]);
	free(t1);
	free(t2);
	free(t3);
	return 0;
}

