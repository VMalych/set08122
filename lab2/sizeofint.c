#include <stdio.h>

int main(int argc, char** argv)
{
	int integerVariable;
	size_t size;
	size = sizeof(integerVariable);
	printf("Size of integer variable is %zu bytes\n", size);
}