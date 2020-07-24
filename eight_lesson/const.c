#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AGECMP(x, y) (x.age == y.age ? 0 : x.age < y.age ? 1 : (-1))
typedef enum{
	ONLINE = 0,
	OFFLINE = 1,
	BANNED = 2,
	INACTIVE = 3,
	VAC = 4
} status;
typedef struct user {
	const char username[20];
	int age;
	status user_status;
} User;

typedef enum{
	MALE,
	FEMALE
	}gender;
typedef struct Person {
	char name[20];
	int age;
	gender nem;
} Person;

void swap(Person* x, Person* y)
{
	Person z = *x;
	*x = *y;
	*y = z;
}

void sort(Person people[], int size)
{
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size - i - 1; j++)
			if(AGECMP(people[j], people[j+1]) == (1))
				swap(&people[j], &people[j+1]);
}


int main(int argc, char **argv)
{
	/*User user1 = {
		.username = "Hackerman",
		.age = 12,
		.user_status = VAC
	};
	
	printf("Username : %s, age : %d\n", user1.username, user1.age);
	switch(user1.user_status)
	{
		case ONLINE: 
			printf("User status online\n");
			break;
		case OFFLINE: 
			printf("User status offline\n");
			break;
		case BANNED: 
			printf("User status banned\n");
			break;
		case INACTIVE: 
			printf("User status inactive\n");
			break;
		case VAC: 
			printf("User status VAC-banned\n");
			break;
	}*/
	
	int peopleCount;
	printf("Hány ember adatát adod meg?: ");
	scanf("%d", &peopleCount);
	
	Person* people = (Person*)malloc(peopleCount);
	
	for(int i = 0; i < peopleCount; i++)
	{
		scanf("%s", &people[i].name);
		scanf("%d", &people[i].age);
		char gend[10];
		scanf("%s", &gend);
		if(strcmp(gend, "MALE"))
			people[i].nem = MALE;
		else
			people[i].nem = FEMALE;
	}
	
	sort(people, peopleCount);
	
	for(int i = 0; i < peopleCount; i++)
	{
		printf("%s %d\n", people[i].name, people[i].age);
	}
	
	
	free(people);
	return 0;
}

