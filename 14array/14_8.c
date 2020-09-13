#include <stdio.h>
#include <stdlib.h>
#define N 20

int cmp(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}

//一定要返回整数
//若对字符进行排序
int cmp2(const void *a,const void *b)
{
	return (*(double *)a>*(double *)b?1:-1);
}

int main()
{
	int s[N],n,i;
	printf("请输入元素个数：");
	scanf("%d",&n);
	printf("请输入%d个整数：\n",n);
	for(int i = 0;i<n;i++)
		scanf("%d",&s[i]);
	qsort(s,n,sizeof(int),cmp);
	printf("排序后的结果为：");
	for(int i = 0;i<n;i++)
		printf("%d ",s[i]);
	printf("\n");
	return 0;
}
