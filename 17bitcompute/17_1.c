#include <stdio.h>

int main()
{
	int a = 0XC3;
	a |= 1<<5;
	printf("a = %X\n",a);
	return 0;
}
