#include <stdlib.h>
#include <stdio.h>

typedef struct _person
{
	int age;	
}person;

int main(int argc, char **argv)
{
	/*person p;
	scanf("%d", &p.age);
	printf("Az életkorom: %d\n", p.age);*/
	
	person p = {
		.age = 20
	};
	printf("Az életkorom: %d\n", p.age);
	return 0;
}

