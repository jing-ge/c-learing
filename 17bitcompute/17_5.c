#include <stdio.h>

int main()
{
	int a = 0xACF71;
	unsigned tmp;
	tmp = a & (0x7ff<<7);
	tmp >>=7;
	tmp += 17;
	a &= ~(0x7ff<<7);
	a |= tmp << 7;
	printf("a = %#X\n",a);
	return 0;
}
