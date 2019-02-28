#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void)
{
	int arr[SIZE];
	int idx, tmp, shift, cmp;
	
	srand(11);
	for (idx = 0; idx < SIZE; idx++)
	{
		arr[idx] = rand();
	}
	
	printf("Insertion Sort\n");
	printf("Before Sorting: \n");
	for (idx = 0; idx < SIZE; idx++)
	{
		printf("%d\t", arr[idx]);
	}
	printf("\n");
	
	//The Selection Sort
	for (cmp = 1; cmp < SIZE; cmp++)
	{
		for (idx = 0; idx < cmp; idx++)
		{
			if (arr[idx] > arr[cmp])
			{
				tmp = arr[idx];
				arr[idx] = arr[cmp];
				
				for (shift = cmp; shift > idx; shift--) arr[shift] = arr[shift - 1];
				arr[shift + 1] = tmp;
			}
		}
	}
	
	printf("After Sorting: \n");
	for (idx = 0; idx < SIZE; idx++)
	{
		printf("%d\t", arr[idx]);
	}
	printf("\n");
}