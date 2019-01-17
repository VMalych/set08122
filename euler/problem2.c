#include <stdio.h>

int main(int argc, char** argv)
{
	int f1 = 1, f2 = 1, ft = 0;
	int sum = 0;
	
	while (f1 < 4000000 && f2 < 4000000)
	{
		ft = f1 + f2;
		f1 = f2;
		f2 = ft;
		if (ft % 2 == 0) sum += ft;
	}
	
	printf("%d\n", sum);
	
	return 0;
}