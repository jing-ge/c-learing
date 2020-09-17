#include <stdio.h>

int main()
{
	int a,b;
	a = 10;b = 20;
	a = a^b;
	b = b^a;
	a = a^b;
	printf("a = %d,b = %d\n",a,b);
	return 0;
}
