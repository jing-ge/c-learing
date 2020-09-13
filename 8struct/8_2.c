#include <stdio.h>

struct Sample
{
	short int n;
	char c[10];
	float f;
	double b;
}s;
int main(void)
{
	printf("变量s所占的字节数为: %d 个字节\n",sizeof(s));
	printf("结构成员   地址\n");
	printf("   n       %X\n",&s.n);
	printf("   c       %X\n",&s.c);
	printf("   f       %X\n",&s.f);
	printf("   b       %X\n",&s.b);
	return 0;
}
