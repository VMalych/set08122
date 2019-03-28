#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void code(int n, int numb)
{
	for (int i = 0; i < n; i++)
	{
		printf(".");
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	clock_t t;
	clock_t avgTicks = 0;
	double avgSec = 0;
	int iterations = 1;
	int tElapsed = 0;
	double sElapsed = 0;
	FILE* report;
	
	report = fopen("report.csv", "w");
	fprintf(report, "iteration,inputSize,elapsedTicks,elapsedSec\n");
	if (argc > 1) iterations = atoi(argv[1]);
	
	int array[100];
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
	}
	
	for (int i = 0; i < iterations; i++)
	{
		t=clock();
	
		code();
		
		t=clock()-t;
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