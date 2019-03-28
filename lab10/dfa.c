#include <stdio.h>

enum state {s0 = 0, s1 = 1, s2 = 2, s3 = 3};

int main(int argc, char** argv)
{
	char* input;
	enum state currentState = s0;
	
	if (argc == 1)
	{
		input = "";
	}
	else 
	{
		input = (char*)malloc(sizeof(argv[1]));
		strcpy(input, argv[1]);
	}
	for (int i = 0; i < strlen(input); i++)
	{
		printf("State: %d, letter: %c\n", currentState, input[i]);
		if (input[i] < 'a' || input[i] > 'z')
		{
			printf("Invalid string\n");
			break;
		}
		switch(currentState)
		{
			case s0:
				if (input[i] == 'a') currentState = s1;
				else currentState = s3;
				break;
			case s1:
				if (input[i] == 'e') currentState = s2;
				else currentState = s1;
				break;
			case s2:
				if (input[i] == 'e') currentState = s2;
				else currentState = s1;
				break;
			case s3:
				currentState = s3;
				break;
			default:
				printf("How did you get out of the states?\n");
				break;
		}
	}
	
	if (currentState == s0 || currentState == s2) printf("EXIT_SUCCESS\n");
	else printf("EXIT_FAILURE\n");
	
	return 0;
}