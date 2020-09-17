#include <stdio.h>

int main()
{
	int a = 0xff30;
	a &= ~(1<<15);
	printf("a = %#X\n",a);
	return 0;
}
