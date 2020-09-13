#include <stdio.h>
#define N 8
void QuickSort(int a[],int left,int right);
int Partition2(int a[],int left,int right);

int main()
{
	int a[N] = {6,2,8,3,9,1,4,7};
	QuickSort(a,0,N-1);
	for(int i=0;i<N;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
void QuickSort(int a[],int left,int right)
{
	if(left < right)
	{
		int pivot = Partition2(a,left,right);
		QuickSort(a,left,pivot-1);
		QuickSort(a,pivot+1,right);
	}
}


int Partition2(int a[],int left,int right)
{
	int temp = a[left];
	int i = left,j = right;
	while(i<j)
	{
		while(i<j&&a[j]>=temp)j--;
		if(i<j)
			a[i] = a[j];
		while(i<j&&a[i]<=temp)i++;
		if(i<j)a[j] = a[i];
	}
	a[i] = temp;
	//打印模拟过程
	printf("[");
	for(int j = left;j<i;j++)
		printf("%d ",a[j]);
	printf("]");
	printf("%d ",a[i]);
	printf("[");
	for(int j = i+1;j<=right;j++)
		printf("%d ",a[j]);
	printf("]\n");
	return i;
	
}
