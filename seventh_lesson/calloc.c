#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int size; 
	printf("Size: ");
	scanf("%d", &size);
	
	int* arr = (int*)calloc(size, sizeof(int));
	for(int i = 0; i < size; i++)
	{
		printf("[%d] = %d\n", i, arr[i]);
	}
	
	printf("Give elements of array: ");
	for(int i = 0; i < size; i++)
	{
		printf("Value: ");
		scanf("%d", &arr[i]);
		printf("%d inserted at index %d\n", arr[i], i);
	}
	
	for(int i = 0; i < size; i++)
	{
		printf("[%d] = %d\n", i, arr[i]);
	}
	
	free(arr);
	return 0;
}

