#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char *text;
	struct node *next;
} node;

void initialize(node *n, char *value);
void add(node *n, char *value);
char* get(node *n, int index);

int main(int argc, char **argv)
{
	node *list = NULL;
	list = malloc(sizeof(node));
	if (list == NULL) {
		return 1;
	}

	list->text = "hi";
	list->next = NULL;
	//initialize(list, "My");
	
	add(list, "Hello");
	add(list, "World");
	
	printf("OUTPUT: %s %s\n", get(list, 0), get(list, 1));
	
	return 0;
}

void initialize(node *n, char *value)
{
	n = NULL;
	n = malloc(sizeof(node));
	n->text = value;
	n->next = NULL;
}

void add(node *n, char *value)
{
	if(n->next == NULL)
	{
		n->next = NULL;
		n->next = malloc(sizeof(node));
		n->next->text = value;
		n->next->next = NULL;
	}
	else add(n->next, value);
}

char* get(node *n, int index)
{
	if(index == 0) return n->text;
	else
	{
		if(n->next == NULL) return "NOT FOUND IN LIST";
		index--;
		return get(n->next, index);
	}
}