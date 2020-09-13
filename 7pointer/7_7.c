#include <stdio.h>

int search(const int *p,int n,int x);

int main(void)
{

	int a[6] = {1,5,2,3,9,7};
	int x;
	printf("请输入查找的元素：");
	scanf("%d",&x);
	int k = search(a,6,x);
	if (k==-1)
		printf("未找到！\n");
	else
		printf("找到了，是数组中第%d个元素\n",k+1);
	return 0;
}


int search(const int *p,int n,int x)
{
	int pos = -1;
	for (int i=0;i<n;i++)
	{
		if (p[i]==x)
		{
			pos = i;
			break;
		}
	}
	return pos;
}
