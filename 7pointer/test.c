#include <stdio.h>

int main()
{
	int a =234;
	int const *f = &a;
	f = 0x321f;
	printf("%d\n",sizeof(long));
	unsigned char *p1;
	unsigned long *p2;
	p1 = (unsigned char*) 0x801000;
	p2 = (unsigned long*) 0x810000;
	printf("%x\n",p1+5);
	printf("%x\n",p2+5);
	return 0;
}
