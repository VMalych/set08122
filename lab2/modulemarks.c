#include <stdio.h>

int main(int argc, char** argv)
{
	int moduleMarks[6];
	moduleMarks[0] = 92;
	moduleMarks[1] = 80;
	moduleMarks[2] = 96;
	moduleMarks[3] = 86;
	moduleMarks[4] = 98;
	moduleMarks[5] = 40;
	
	char moduleMarks2[20][24];
	char buffer[20];
	
	for (int i = 0; i < 6; i++)
	{
		sprintf(buffer, "%d", moduleMarks[i]);
		strcat(buffer, " 40321576");
		strcpy(moduleMarks2[i], buffer);
	}
	
	for (int i = 0; i < 6; i++)
	{
		printf("%s\n", moduleMarks2[i]);
	}
	
	size_t size = sizeof(moduleMarks);
	printf("Size of moduleMarks is %zu bytes\n", size);
	
	size_t num = size/sizeof(int);
	printf("moduleMarks has space for %zu elements\n", num);
	
	size = sizeof(moduleMarks2);
	printf("Size of moduleMarks is %zu bytes\n", size);
	
	num = size/sizeof(char[20]);
	printf("moduleMarks has space for %zu elements\n", num);
	
	return 0;
}