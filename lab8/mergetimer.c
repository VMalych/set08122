#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void mergesort(int data[], int left, int right);
void merge(int data[], int left, int middle, int right);

void code(int* arr, int n)
{
	mergesort(arr, 0, n - 1);
}

int main(int argc, char** argv)
{
	clock_t t;
	clock_t avgTicks = 0;
	double avgSec = 0;
	int iterations = 1;
	clock_t tElapsed = 0;
	double sElapsed = 0;
	FILE* report;
	
	report = fopen("report.csv", "w");
	fprintf(report, "iteration,inputSize,elapsedTicks,elapsedSec\n");
	if (argc > 1) iterations = atoi(argv[1]);
	
	int array[20000];
	int n = 100;
	
	for (int i = 0; i < iterations; i++)
	{
		t=clock();
		printf("Current tick: %d\n", (int)t);
		
		srand(i);
		for (int idx = 0; idx < n; idx++)
		{
			array[idx] = rand();
		}
		
		printf("Before Sorting: \n");
		for (int idx = 0; idx < n; idx++)
		{
			printf("%d\t", array[idx]);
		}
		printf("\n");
		
		code(array, n);
		
		printf("After Sorting: \n");
		for (int idx = 0; idx < n; idx++)
		{
			printf("%d\t", array[idx]);
		}
		printf("\n");
		
		n += 100;
		
		t=clock()-t;
		printf("Tick difference: %d\n\n", (int)t);
		tElapsed = t;
		sElapsed = (double)t / CLOCKS_PER_SEC;
		avgTicks += t;
		avgSec += sElapsed;
		fprintf(report, "%d,%d,%d,%f\n", i+1, n, tElapsed, sElapsed);
	}		
	avgTicks /= iterations;
	avgSec /= iterations;
	
	fprintf(report, "avgticks,%d\n", avgTicks);
	fprintf(report, "avgsec,%f\n", avgSec);
	
	fclose(report);
	return 0;
}

void mergesort(int data[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left)/2;
		
		mergesort(data, left, middle);
		mergesort(data, middle + 1, right);
		
		merge(data, left, middle, right);
	}
}

void merge(int data[], int left, int middle, int right)
{
	int left_idx, right_idx, merged_idx;
	int left_size = middle - left + 1;
	int right_size = right - middle;
	
	int tmp_left[left_size], tmp_right[right_size];
	
	for (left_idx = 0; left_idx < left_size; left_idx++) tmp_left[left_idx] = data[left + left_idx];
	for (right_idx = 0; right_idx < right_size; right_idx++) tmp_right[right_idx] = data[middle + 1 + right_idx];
	
	left_idx = 0;
	right_idx = 0;
	merged_idx = left;
	
	while (left_idx < left_size && right_idx < right_size)
	{
		if (tmp_left[left_idx] <= tmp_right[right_idx])
		{
			data[merged_idx] = tmp_left[left_idx];
			left_idx++;
		}
		else
		{
			data[merged_idx] = tmp_right[right_idx];
			right_idx++;
		}
		merged_idx++;
	}
	
	while (left_idx < left_size)
	{
		data[merged_idx] = tmp_left[left_idx];
		left_idx++;
		merged_idx++;
	}
	
	while (right_idx < right_size)
	{
		data[merged_idx] = tmp_right[right_idx];
		right_idx++;
		merged_idx++;
	}
}