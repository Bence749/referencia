#include <stdio.h>

#ifdef SIZE
#define HELLO "Hello World!"


int main(int argc, char **argv)
{
	/*	printf("%s\n", HELLO);
	 *	printf("%s\n", "Hello world!");*/
	 
	/*int arr[20];
	 *
	 *for(int i = 0; i < 20; i++)
	 *{
	 *	scanf("%d", &arr[i]);
	 *	#ifdef DEBUG
	 *	printf("You inserted value: %d at index: %d\n/", arr[i], i);
	 *	#endif
	 *}
	 */
	
	/* int arr[SIZE];
	
	#ifdef DEBUG
	printf("Array size: %d\n", SIZE);
	#endif
	
	for(int i = 0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
		#ifdef DEBUG
		printf("You inserted value: %d at index: %d \n", arr[i], i);
		#endif
	}*/
	
	
	return 0;
}
#endif
