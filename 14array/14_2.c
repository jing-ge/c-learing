#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int m,n;
	printf("输入m,n:\n");
	scanf("%d %d",&m,&n);

	int *g = (int *)malloc(sizeof(int)*(n+1));
	memset(g,0,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
			g[j]++;
	}
	int maxyn = 0;
	int flag = 0;
	for(int i = 0;i<m;i++)
	{
		if(g[i]>maxyn)
			maxyn = g[i];
	}
	for(int i = m;i<=n;i++)
	{
		if(g[i]>maxyn)
		{
			maxyn = g[i];
			if(flag)printf(",");
			printf("%d",i);
			flag = 1;
		}
	}
	if(flag==0)printf("NO\n");
	free(g);
	return 0;
}
