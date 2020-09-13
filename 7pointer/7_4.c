#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int *a = NULL;
	printf("数组长度为:");
	scanf("%d",&n);

	a = (int *)malloc(n*sizeof(int));
	for (int i=0;i<n;i++)
		scanf("%d", &a[i]);

	int x,sum=0;
	printf("计数的数字：");
	scanf("%d",&x);
	for(int i=0;i<n;i++)
		if (a[i]==x)sum++;
	printf("一共有%d个\n",sum);
	free(a);
	return 0;
}
