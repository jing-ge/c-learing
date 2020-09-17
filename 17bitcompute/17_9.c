#include <stdio.h>
#include <stdlib.h>

int AppearOnce(int *a,int n);
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int *a = (int *)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int OnceNum = AppearOnce(a,n);
		printf("%d\n",OnceNum);
		free(a);
	}
	return 0;

}

int AppearOnce(int *a,int n)
{
	int num = 0;
	for(int i=0;i<n;i++)
	{
		num^=a[i];
	}
	return num;
}
