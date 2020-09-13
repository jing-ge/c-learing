#include <stdio.h>
const int N = 6;
void InsertSort(int *r,int n);

int main()
{
	int a[] = {5,2,4,6,1,3};

	printf("排序前的序列为：");
	int n = sizeof(a)/sizeof(int);
	for(int i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	InsertSort(a,n);
	printf("排序后的序列为：");
	for(int i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

void InsertSort(int *r,int n)
{
	int x;
	for(int i=1;i<n;i++)
	{
		x = r[i];
		int j = i-1;
		while(j>=0&&x<r[j])
		{
			r[j+1] = r[j];
			j--;
		}
		r[j+1] = x;
		//排序算法结束
		printf("第%d躺：插入元素%d后，有序区变化：",i,r[i]);
		for(int k = 0;k<n;k++)
		{
			printf("%d ",r[k]);
			if(k==i)printf("|");
		}
		printf("\n");
	}
}
