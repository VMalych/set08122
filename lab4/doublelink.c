#include <stdio.h>

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

int count(struct node* list);
void display(struct node* list);
void append(struct node** list, int num);
void prepend(struct node** list, int num);
void insert_after(struct node* list, int location, int num);
void delete(struct node** list, int num);

int main(int argc, char** argv)
{
	struct node* list;
	list = NULL;
	
	printf("No of elements in linked list = %d\n", count(list));
	
	append(&list, 14);
	append(&list, 30);
	append(&list, 25);
	append(&list, 42);
	append(&list, 17);
	printf("No of elements in linked list = %d\n", count(list));
	display(list);
	
	prepend(&list, 999);
	prepend(&list, 888);
	prepend(&list, 777);
	printf("No of elements in linked list = %d\n", count(list));
	display(list);
	
	insert_after(list, 1, 0);
	insert_after(list, 2, 1);
	insert_after(list, 5, 99);
	printf("No of elements in linked list = %d\n", count(list));
	display(list);
	
	insert_after(list, 99, 10);
	printf("No of elements in linked list = %d\n", count(list));
	display(list);
	
	delete(&list, 99);
	delete(&list, 1);
	printf("No of elements in linked list = %d\n", count(list));
	display(list);
	
	delete(&list, 10);
	printf("No of elements in linked list = %d\n", count(list));
	display(list);
	
	return 0;
}

int count(struct node* list)
{
	int count = 0;
	while(list != NULL)
	{
		list = list->next;
		count++;
	}
	return count;
}

void display(struct node* list)
{
	while(list != NULL)
	{
		printf("%2d\t", list->data);
		list = list->next;
	}
	printf("\n");
}

void append(struct node** list, int num)
{
	struct node *temp, *current = *list;
	if(*list == NULL)
	{
		*list = (struct node*)malloc(sizeof(struct node));
		(*list)->data = num;
		(*list)->next = NULL;
		(*list)->prev = NULL;
	}
	else
	{
		while(current->next != NULL) current = current->next;
		*list = (struct node*)malloc(sizeof(struct node));
		(*list)->data = num;
		(*list)->next = NULL;
		(*list)->prev = current;
		current->next = temp;
	}
}

void prepend(struct node** list, int num)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = num;
	temp->next = *list;
	
	(*list)->prev = temp;
	*list = temp;
}

void insert_after(struct node* list, int location, int num)
{
	struct node* temp;
	int i;
	
	for(i = 0; i < location; i++)
	{
		list = list->next;
		if(list == NULL)
		{
			printf("Length of list is %d but supplied location is %d\n", i, location);
			return;
		}
	}
	list = list->prev;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = num;
	temp->prev = list;
	temp->next = list->next;
	temp->next->prev = temp;
	list->next = temp;
}

void delete(struct node** list, int num)
{
	struct node *temp = *list;
	while(temp != NULL)
	{
		if(temp->data == num)
		{
			if(temp == *list)
			{
				*list = (*list)->next;
				(*list)->prev = NULL;
			}
			else
			{
				if(temp->next == NULL) temp->prev->next = NULL;
				else
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
				}
				free(temp);
			}
			return;
		}
		temp = temp->next;
	}
	printf("Element %d not found in the supplied list\n", num);
}