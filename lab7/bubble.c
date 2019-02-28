#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void)
{
	int arr[SIZE];
	int idx, target, tmp;
	
	srand(11);
	for (idx = 0; idx < SIZE; idx++)
	{
		arr[idx] = rand();
	}
	printf("Bubble Sort\n");
	printf("Before Sorting: \n");
	for (idx = 0; idx < SIZE; idx++)
	{
		printf("%d\t", arr[idx]);
	}
	printf("\n");
	
	//The Bubble Sort
	for (idx = 0; idx < SIZE - 1; idx++)
	{
		for (target = 0; target < (SIZE - 1) - idx; target++)
		{
			if (arr[target] > arr[target + 1])
			{
				tmp = arr[target];
				arr[target] = arr[target + 1];
				arr[target + 1] = tmp;
			}
			printf("During Sorting %d: \n", idx);
			for (int i = 0; i < SIZE; i++)
			{
				printf("%d\t", arr[i]);
			}
			printf("\n");
		}
	}
	
	printf("After Sorting: \n");
	for (idx = 0; idx < SIZE; idx++)
	{
		printf("%d\t", arr[idx]);
	}
	printf("\n");
}