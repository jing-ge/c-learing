#include <stdio.h>

int main()
{
	int a = 0xFBA;
	a &= 0x3F<<3;
	a >>= 3;

	printf("a = %#X\n",a);
	return 0;
}
