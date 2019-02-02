#include <stdio.h>

#define MAX 5

void insert(int* array, int pos, int num);
void delete(int* array, int pos);
void update(int* array, int pos, int num);
void reverse(int* array);
void init(int* array);
void display(int* array);
void search(int* array, int num);
void sizer(int* array, int size);

int main(void)
{
	int array[MAX];
	
	init(array);
	
	insert(array, 1, 11);
	insert(array, 2, 12);
	insert(array, 3, 13);
	insert(array, 4, 14);
	insert(array, 5, 15);
	
	printf("Array Contents: \n");
	display(array);
	
	update(array, 3, 33);
	
	printf("Array Update: \n");
	display(array);
	
	delete(array, 3);
	
	printf("Array Deletion: \n");
	display(array);
	
	insert(array, 5, 42);
	
	printf("Array Insertion: \n");
	display(array);
	
	reverse(array);
	
	printf("Array Reversed: \n");
	display(array);
	
	search(array, 43);
	search(array, 42);
	
	sizer(array, 2);
	insert(array, 6, 16);
	insert(array, 7, 17);
	int idx;
	
	for(idx = 0; idx < 7; idx++)
	{
		printf("%d\t", idx);
	}
	printf("\n");
	
	for(idx = 0; idx < 7; idx++)
	{
		printf("%d\t", array[idx]);
	}
	printf("\n");
	
	return 0;
}

void insert(int* array, int pos, int num)
{
	int idx;
	
	for(idx = MAX-1; idx >= pos; idx--)
	{
		array[idx] = array[idx-1];
	}
	array[idx] = num;
}

void delete(int* array, int pos)
{
	int idx;
	for(idx = pos; idx < MAX; idx++)
	{
		array[idx-1] = array[idx];
	}
	array[idx-1] = 0;
}

void update(int* array, int pos, int num)
{
	array[pos-1] = num;
}

void reverse(int* array)
{
	int idx;
	for(idx = 0; idx < MAX/2; idx++)
	{
		int temp = array[idx];
		array[idx] = array[MAX-1-idx];
		array[MAX-1-idx] = temp;
	}
}

void init(int* array)
{
	int idx;
	for(idx = 0; idx < MAX; idx++)
	{
		array[idx] = 0;
	}
}

void display(int* array)
{
	int idx;
	
	for(idx = 0; idx < MAX; idx++)
	{
		printf("%d\t", idx);
	}
	printf("\n");
	
	for(idx = 0; idx < MAX; idx++)
	{
		printf("%d\t", array[idx]);
	}
	printf("\n");
}

void search(int* array, int num)
{
	int idx;
	for(idx = 0; idx < MAX; idx++)
	{
		if(array[idx] == num)
		{
			printf("%d found in position %d\n", num, idx+1);
			return;
		}
	}
	if(idx == MAX) printf("%d not found in array\n", num);
}

void sizer(int* array, int elem)
{
	array = realloc(array, (sizeof(array) + elem*sizeof(int)));
}