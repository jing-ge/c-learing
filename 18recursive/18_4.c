#include <stdio.h>
int f(int a,int m);

int main()
{
	int n,a;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		printf("%d\n",f(a,2));
	}	
}
int f(int a,int m)
{
	if(a == 1)return 1;
	if(a<m)return 0;
	int s=0;
	for(int i=m;i<=a;i++)
	{
		if(a%i==0)s+=f(a/i,i);
	}
	return s;
}
