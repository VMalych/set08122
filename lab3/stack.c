#include <stdio.h>

#define MAX 5

struct stack
{
	int array[MAX];
	int top;
};

void init_stack(struct stack *s);
void push(struct stack *s, int item);
int *pop(struct stack *s);

int main(int argc, char** argv)
{
	struct stack test;
	
	init_stack(&test);
	
	push(&test, 11);
	push(&test, 23);
	push(&test, -8);
	push(&test, 42);
	push(&test, 55);
	push(&test, 47);
	
	int *i = NULL;
	
	i = pop(&test);
	if(i) printf("Item popped: %d\n", *i);
	
	i = pop(&test);
	if(i) printf("Item popped: %d\n", *i);
	
	i = pop(&test);
	if(i) printf("Item popped: %d\n", *i);
	
	i = pop(&test);
	if(i) printf("Item popped: %d\n", *i);
	
	i = pop(&test);
	if(i) printf("Item popped: %d\n", *i);
	
	i = pop(&test);
	if(i) printf("Item popped: %d\n", *i);
	
	return 0;
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