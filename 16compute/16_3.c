#include <stdio.h>
#include <string.h>
#define N 3000
int result[N];

int main()
{
	int n;
	printf("计算n！，输入n的值：\n");
	scanf("%d",&n);
	memset(result,0,N);
	result[0] = 1;
	int digits = 1;
	for(int i = 2;i<=n;i++)
	{
		int jw = 0;
		for(int j = 0;j<digits;j++)
		{
			int total = result[j]*i+jw;
			result[j] = total %10;
			jw = total/10;
			if(j==digits-1&&jw)digits++;
		}
	}
	char factarr[N];
	memset(factarr,0,N);
	for(int i = digits-1,j=0;i>=0;i--)
	{
		factarr[j++] = result[i]+'0';
	}
	printf("%d! = %s",n,factarr);

	return 0;
}
