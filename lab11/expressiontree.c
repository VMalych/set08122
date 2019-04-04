#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 20

void insert(struct binary_tree_node **node, int num);
void traverse(struct binary_tree_node *node);
void search(struct binary_tree_node **root, int num, struct binary_tree_node** parent, struct binary_tree_node** found_node, int *found_status);
void delete(struct binary_tree_node** root, int num);

struct binary_tree_node
{
	struct binary_tree_node *left_child;
	struct binary_tree_node *right_child;
	int data;
};

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
	struct binary_tree_node* root;
	int i = 0, j = 0;
	root = NULL;
	char expression[100] = "";
	char temp[20] = "";
	struct stack numbers;
	
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
	return 0;
}

void insert(struct binary_tree_node **node, int num)
{
	if(*node == NULL)
	{
		*node = (struct binary_tree_node*)malloc(sizeof(struct binary_tree_node));
		(*node)->left_child = NULL;
		(*node)->right_child = NULL;
		(*node)->data = num;
	}
	else
	{
		if(num < (*node)->data) insert(&((*node)->left_child), num);
		else insert(&((*node)->right_child), num);
	}
}

void traverse(struct binary_tree_node *node)
{
	if(node != NULL)
	{
		traverse(node->left_child);
		printf("%d\t", node->data);
		traverse(node->right_child);
	}
}

void search(struct binary_tree_node **root, int num, struct binary_tree_node** parent, struct binary_tree_node** found_node, int *found_status)
{
	struct binary_tree_node* temp;
	temp = *root;
	*found_status = FALSE;
	*parent = NULL;
	
	while(temp != NULL)
	{
		if(temp->data == num)
		{
			*found_status = TRUE;
			*found_node = temp;
			return;
		}
		*parent = temp;
		if(temp->data > num) temp = temp->left_child;
		else temp = temp->right_child;
	}
}

void delete(struct binary_tree_node** root, int num)
{
	int found;
	struct binary_tree_node *parent, *search_node, *next;
	
	if(*root == NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	
	parent = search_node = NULL;
	search(root, num, &parent, &search_node, &found);
	
	if(found == FALSE)
	{
		printf("Data not found\n");
		return;
	}
	
	if(search_node->left_child != NULL && search_node->right_child != NULL)
	{
		parent = search_node;
		next = search_node->right_child;
		while(next->left_child != NULL)
		{
			parent = next;
			next = next->left_child;
		}
		search_node->data = next->data;
		search_node = next;
	}
	
	if(search_node->left_child == NULL && search_node->right_child == NULL)
	{
		if(parent->right_child == search_node) parent->right_child = NULL;
		else parent->left_child = NULL;
		
		free(search_node);
		return;
	}
	
	if(search_node->left_child == NULL && search_node->right_child != NULL)
	{
		if(parent->left_child == search_node) parent->left_child = search_node->right_child;
		else parent->right_child = search_node->right_child;
		
		free(search_node);
		return;
	}
	
	if(search_node->left_child != NULL && search_node->right_child == NULL)
	{
		if(parent->left_child == search_node) parent->left_child = search_node->left_child;
		else parent->right_child = search_node->left_child;
		
		free(search_node);
		return;
	}
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