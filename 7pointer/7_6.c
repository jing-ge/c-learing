#include <stdio.h>

int main(void)
{
	int a[5] = {1,3,5,7,9};
	int i=0;
	int *p = a;
	p[2] = 10;
	printf("a数组的首地址为:%p\n",a);

	for(int i=0;i<5;i++)
		printf("a[%d]的地址为：%p，a[%d]的值为：%d\n",i,p+i,i,*(p+i));
	return 0;
}
