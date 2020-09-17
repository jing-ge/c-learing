#include <stdio.h>

int CountOne(int a);

int main()
{
	int a;

	printf("输入一个整数：");
	scanf("%d",&a);
	printf("%d的二进制表示中1的个数是%d\n",a,CountOne(a));
	return 0;

}

int CountOne (int a)
{
	int c = 0;
	while(a)
	{
		c++;
		a&=a-1;
	}
	return c;
}
