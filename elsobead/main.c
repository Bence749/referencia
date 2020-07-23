#include <stdio.h>
#include "elsobead.h"

int main(int argc, char **argv)
{
	int size;
	do  scanf("%d", &size); while(size < 1 || size > 100);
	int *futam = malloc(sizeof(int[size]));
    beolvasas(futam, size);



	free(futam);
	return 0;
}

