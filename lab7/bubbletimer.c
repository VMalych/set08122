#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void code(int* arr, int n)
{
	int idx, target, tmp;
	for (idx = 0; idx < n - 1; idx++)
	{
		for (target = 0; target < (n - 1) - idx; target++)
		{
			if (arr[target] > arr[target + 1])
			{
				tmp = arr[target];
				arr[target] = arr[target + 1];
				arr[target + 1] = tmp;
			}
		}
	}
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