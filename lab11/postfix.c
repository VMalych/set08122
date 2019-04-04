#include <stdio.h>
#include <string.h>

#define MAX 20

struct stack
{
	int array[20];
	int top;
};

void init_stack(struct stack *s);
void push(struct stack *s, int item);
int *pop(struct stack *s);

int main(int argc, char** argv)
{
	char expression[100] = "";
	char temp[MAX] = "";
	struct stack numbers;
	int i = 0, j = 0;
	int x = 0, y = 0;
	int len;
	
	init_stack(&numbers);
	printf("Enter expression: ");
	fgets(expression, 100, stdin);
	len = strlen(expression);
	while(i <= len)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			temp[j] = expression[i];
			j++;
		}
		else
		{
			if (expression[i] == ' ' && j > 0)
			{
				push(&numbers, atoi(temp));
				memset(temp, 0, sizeof temp);
				j = 0;
			}
			if (expression[i] == '+')
			{
				x = *pop(&numbers);
				y = *pop(&numbers);
				x = y + x;
				push(&numbers, x);
			}
			if (expression[i] == '-')
			{
				x = *pop(&numbers);
				y = *pop(&numbers);
				x = y - x;
				push(&numbers, x);
			}
			if (expression[i] == '*')
			{
				x = *pop(&numbers);
				y = *pop(&numbers);
				x = y * x;
				push(&numbers, x);
			}
			if (expression[i] == '/')
			{
				x = *pop(&numbers);
				y = *pop(&numbers);
				x = y / x;
				push(&numbers, x);
			}
		}
		i++;
	}
	printf("The answer is: %d\n", *pop(&numbers));
}

void init_stack(struct stack *s)
{
	s->top = -1;
}

void push(struct stack *s, int item)
{
	if(s->top == MAX-1)
	{
		printf("Stack is full. Couldn't push '%d' onto stack\n", item);
		return;
	}
	s->top++;
	s->array[s->top] = item;
}

int *pop(struct stack *s)
{
	int *data;
	if(s->top == -1)
	{
		printf("Stack is empty\n");
		return NULL;
	}
	data = &s->array[s->top];
	s->top--;
	return data;
}