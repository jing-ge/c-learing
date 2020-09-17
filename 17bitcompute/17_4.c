#include <stdio.h>

int main()
{
	int a = 0xACF71;
	a &= ~(0x7ff<<7);
	a |= 937<<7;
	printf("a = %#X\n",a);
	return 0;
}
