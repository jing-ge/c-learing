#include <stdio.h>

double Add(double x,double y)
{
	return x+y;
}

int main()
{
	double (*funcPtr)(double,double);
	funcPtr = Add;
	double result = funcPtr(6.0,7.0);
	printf("%f\n",result);
	return 0;
}
