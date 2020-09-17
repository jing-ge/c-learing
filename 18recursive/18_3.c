#include <stdio.h>
void Move(int n,char x,char y,char z);
int sum = 0;
int main()
{
	int n;
	printf("请输入盘子数：");
	scanf("%d",&n);
	printf("移动步骤如下：\n");
	Move(n,'A','B','C');
	printf("一共进行了%d次移动\n",sum);
	return 0;
}

void Move(int n,char x,char y,char z)
{
	sum++;
	if(n==1)
		printf("%d# from %c to %c\n",n,x,z);
	else
	{
		Move(n-1,x,z,y);
		printf("%d# from %c to %c\n",n,x,z);
		Move(n-1,y,x,z);
	}
}
