#include <stdio.h>

typedef struct
{
	int id;
	char name[30];
} employee;

int main(int argc, char** argv)
{
	employee e1 = {1, "Simon"};
	
	printf("ID: %d, Name: %s\n", e1.id, e1.name);
	printf("Size of employee: %zu, size of employee.id: %zu, size of employee.name: %zu\n", sizeof(e1), sizeof(e1.id), sizeof(e1.name));
	return 0;
}