#include <stdio.h>
#include <math.h>

int main()
{

	double x;
	x = ldexp(1.0,128) / 1000000 /(365 * 24 * 60 *60);
	printf("%e\n",x);
	return 0;
}
