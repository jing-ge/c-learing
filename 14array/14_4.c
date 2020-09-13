#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m;
	printf("请输入猴子数量和出圈猴子报道的数：");
	scanf("%d %d",&n,&m);
	int *a = (int *)malloc(sizeof(int)*n);
	for(int i = 0;i<n;i++)
		a[i] = i+1;
	printf("%d个猴子出圈的顺序是：",n-1);
	int j = n-1;
	for(int i = 1;i<n;i++)
	{
		int k = 0;
		do
		{
			j = (j+1)%n;
			if(a[j]!=0)k++;
		}while(k<m);
		printf("%d ",a[j]);
		a[j] = 0;
	}
	printf("\n最后圈内剩下的猴子编号为：");
	for(int i = 0;i<n;i++)
	{
		if(a[i]!=0)printf("%d",a[i]);
	}
	free(a);
	return 0;
}
