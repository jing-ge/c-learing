#include <stdio.h>

#define N 6
void Input(int r[],int n);
void Output(int r[],int n);
void BubbleSort(int r[],int n);
void swap(int *a,int *b);

int main(void)
{
	int a[N];
	printf("输入数组的%d个元素：\n",N);
	Input(a,N);
	printf("排序前的数组a的元素为:\n");
	Output(a,N);
	BubbleSort(a,N);
	printf("排序后的数组a的元素为:\n");
	Output(a,N);
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
