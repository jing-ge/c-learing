#include <stdio.h>

int main(void)
{
	int *p;
	int a = 5;
	p = &a;
	printf("变量a的值是%d,变量a的地址是%x\n",a,&a);
	printf("变量p的值是%x,变量p指向的空间的值是%d\n",p,*p);
	printf("变量p的地址是%x,变量p所占用空间大小是%d个字节\n",&p,sizeof(p));

	return 0;
}
