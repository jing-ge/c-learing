#include <stdio.h>

typedef union
{
	long i;
	int k[5];
	char c;
}DATE;

struct data
{
	int cat;
	DATE cow;
	double dog;
}too;
DATE max;
int main()
{
	int k[5];
	printf("%d\n",sizeof(struct data));
	printf("%d\n",sizeof(max));
	printf("%d\n",sizeof(DATE));
	printf("%d\n",sizeof(k));
	struct t
	{
		int a:1;
	}T;
	T.a= 1;
	printf("%d\n",T.a);
	return 0;
}
