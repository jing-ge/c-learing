#include <stdio.h>

#define N 6
void Input(int r[],int n);
void Output(int r[],int n);
void BubbleSort(int r[],int n);
int BinSearch(int a[],int n,int x);
void swap(int *a,int *b);

int main(void)
{
	int a[N],x;
	printf("输入数组的%d个元素：\n",N);
	Input(a,N);
	BubbleSort(a,N);
	printf("排序后的数组a的元素为:\n");
	Output(a,N);
	printf("输入查找的元素x：");
	scanf("%d",&x);
	int t = BinSearch(a,N,x);
	if(t!=0)printf("查找%d成功，序号为%d\n",x,t);
	else printf("查找%d失败！\n",x);
	return 0;
}
void Input(int r[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&r[i]);
}
void Output(int r[],int n)
{
	for(int i = 0;i<n;i++)
		printf("%d ",r[i]);
	printf("\n");
}
void BubbleSort(int r[],int n)
{
	int swapflag = 1;
	for(int i = 0;swapflag&&i<n;i++)
	{
		for(int j = 0;j<n-i-1;j++)
		{
			if(r[j]>r[j+1])
			{
				swap(&r[j],&r[j+1]);
			}
		}
	}

}
void swap(int *a ,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int BinSearch(int a[],int n,int x)
{
	int low,high,mid;
	low = 0;
	high = n-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		//printf("%d\n",mid);
		if(x==a[mid])return mid+1;
		else if(x<a[mid])high = mid-1;
		else low = mid+1;
	}
	return 0;
}
