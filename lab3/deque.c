#include <stdio.h>

#define MAX 5

struct deque
{
	int array[MAX];
	int head;
	int tail;
};

void initialize(struct deque *d);
void addHead(struct deque *d, int value);
void removeHead(struct deque *d);
int getHead(struct deque *d);
void addTail(struct deque *d, int value);
void removeTail(struct deque *d);
int getTail(struct deque *d);

int main(int argc, char **argv)
{
	struct deque d;
	
	initialize(&d);
	
	addHead(&d, 1);
	addHead(&d, 2);
	addHead(&d, 3);
	addHead(&d, 4);
	addHead(&d, 5);
	
	for(int i = 0; i < d.tail; i++)
	{
		printf("%d\n", d.array[i]);
	}
	printf("\n");
	
	removeHead(&d);
	addTail(&d, 42);
	
	for(int i = 0; i < d.tail; i++)
	{
		printf("%d\n", d.array[i]);
	}
	printf("\n");
	
	addTail(&d, 45);
	removeTail(&d);
	removeTail(&d);
	
	for(int i = 0; i < d.tail; i++)
	{
		printf("%d\n", d.array[i]);
	}
	printf("\n");
	
	addTail(&d, 45);
	addTail(&d, 54);
	
	for(int i = 0; i < d.tail; i++)
	{
		printf("%d\n", d.array[i]);
	}
	printf("\n");
	
	printf("Head: %d, tail: %d\n", getHead(&d), getTail(&d));
	
	return 0;
}

void initialize(struct deque *d)
{
	d->head = -1;
	d->tail = 0;
}

void addHead(struct deque *d, int value)
{
	if(d->head == -1) 
	{
		d->head = 0;
		d->tail = 0;
	}
	if(d->tail < MAX - 1)
	{
		for(int i = d->tail; i > 0; i--)
		{
			d->array[i] = d->array[i-1];
		}
		d->array[d->head] = value;
		d->tail++;
	}
	else if(d->tail == MAX - 1) 
	{
		for(int i = d->tail; i > 0; i--)
		{
			d->array[i] = d->array[i-1];
		}
		d->array[d->head] = value;
		d->tail++;
	}
	else printf("Deque is full\n");
	printf("Head: %d, tail: %d\n", d->head, d->tail);
}

void removeHead(struct deque *d)
{
	if(d->tail == -1) printf("Deque is empty\n");
	else
	{
		for(int i = 0; i < MAX; i++)
		{
			d->array[i] = d->array[i+1];
		}
		d->tail--;
	}
}

int getHead(struct deque *d)
{
	if(d->tail == -1) 
	{
		printf("Deque is empty\n");
		return -1;
	}
	else return d->array[d->head];
}

void addTail(struct deque *d, int value)
{
	if(d->tail == -1) 
	{
		d->head = 0;
		d->tail = 1;
	}
	if(d->tail < MAX - 1)
	{
		d->array[d->tail] = value;
		d->tail++;
	}
	else if(d->tail == MAX - 1) 
	{
		d->array[d->tail] = value;
		d->tail++;
	}
	else printf("Deque is full\n");
}

void removeTail(struct deque *d)
{
	if(d->tail == -1) printf("Deque is empty\n");
	else
	{
		d->tail--;
	}
}

int getTail(struct deque *d)
{
	if(d->tail == -1) 
	{
		printf("Deque is empty\n");
		return -1;
	}
	else return d->array[d->tail-1];
}

