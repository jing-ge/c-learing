#include <stdio.h>
#include <stdlib.h>
int Search(int a[],int n,int x);

int main()
{
	int M,N;
	scanf("%d %d",&M,&N);
	int *a = (int *)malloc(sizeof(int)*M);
	int n = 0,k = 0;
	int x;
	int times = 0;
	while(N--)
	{
		scanf("%d",&x);
		if(!Search(a,n,x))
		{
			times++;
			a[k] = x;
			k = (k+1)%M;
			if(n<M)n++;
		}
	}
	printf("%d\n",times);
	free(a);
	return 0;
}
int Search(int a[],int n,int x)
{
	int i = 0;
	while(i<n)
	{
		if(a[i]==x)return 1;
		i++;
	}
	return 0;
}
