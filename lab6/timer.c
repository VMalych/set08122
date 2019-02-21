#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void code(int* array, int n, int numb)
{
	int start = 0, end = n - 1, mid = 0;
	for (mid = (start + end)/2; start <= end; mid = (start + end)/2)
	{
		if (array[mid] == numb)
		{
			printf("%d at position %d\n", array[mid], mid);
			return;
		}
		if (array[mid] > numb) end = mid - 1;
		else start = mid + 1;
	}
	printf("%d is not in array", numb);
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
	
	int array[10000];
	int n = 100;
	
	for (int i = 0; i < iterations; i++)
	{
		t=clock();
		printf("%d\n", (int)t);
		
		srand(i);
		for (int i = 0; i < n; i++)
		{
			array[i] = i;
		}
		code(array, n, 42);
		n += 100;
		
		t=clock()-t;
		printf("%d\n\n", (int)t);
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