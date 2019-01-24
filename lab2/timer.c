#include <time.h>
#include <stdio.h>

void code()
{
	for (int i = 0; i < 10000; i++)
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
	FILE* report;
	
	report = fopen("report.csv", "w");
	
	if (argc > 1) iterations = atoi(argv[1]);
	
	for (int i = 0; i < iterations; i++)
	{
		fprintf(report, "iteration,%d\n", i+1);
		fprintf(report, "start,%d\n", (int)(t=clock()));
	
		code();
	
		fprintf(report, "stop,%d\n", (int)(t=clock()-t));
		fprintf(report, "ElapsedSec,%f\n", (double)t / CLOCKS_PER_SEC);
		avgTicks += t;
		avgSec += (double)t / CLOCKS_PER_SEC;
	}		
	avgTicks /= iterations;
	avgSec /= iterations;
	
	fprintf(report, "avgticks,%d\n", avgTicks);
	fprintf(report, "avgsec,%f\n", avgSec);
	
	fclose(report);
	return 0;
}