#include <stdio.h>

int main()
{
	int a;
	printf("请输入一个整数：\n");
	scanf("%d",&a);
	if((a&1)==0)
		printf("%d 是一个偶数\n",a);
	else
		printf("%d 是一个奇数\n",a);
	return 0;
}
