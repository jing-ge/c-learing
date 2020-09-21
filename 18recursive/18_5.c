#include <stdio.h>

int q(int n,int m);

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",q(n,n));
	return 0;
}
int q(int n,int m)
{
	if(n<1||m<1)return 0;
	if(n==1||m==1)return 1;
	if(n<m)return q(n,n);
	if(n==m)return q(n,m-1)+1;
	return q(n,m-1)+q(n-m,m);
}
