#include <stdio.h>

int main(int argc, char **argv)
{
	int* ptr;
	int val = 28;
	int* ptr_2 = &val;
	
	ptr = &val;
	
	val = 15;
	
	*ptr_2 = 17;
	
	printf("ptr = %d | ptr2 = %d | val = %d\n", *ptr, *ptr_2, val);
	//printf("ptr addr : %x | val = %x\n", &ptr, &val);
	return 0;
}

