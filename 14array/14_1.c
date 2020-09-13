#include <stdio.h>
#include <string.h>
#define N 100

int main()
{
	int prime[N+1] = {0};
	int n;
	scanf("%d",&n);
	memset(prime,0,sizeof(prime));
	prime[1] = 1;
	for(int i=2;i*i<=n;i++)
	{
		if(prime[i]==0)
		{
			for(int j = 2*i;j<=n;j+=i)
				prime[j] = 1;
		}
	}
	int t = 0;
	for(int i = 1;i<=n;i++)
	{
		if(prime[i]==0)
		{
			printf("%2d ",i);
			t++;
			if(t%5==0)printf("\n");
		}
	}
	return 0;
}
