#include <stdio.h>
long long f(int h,int y);

int main()
{
	int h,y;
	scanf("%d %d",&h,&y);
	printf("%ld\n",f(h,y));
	return 0;
}

long long f(int h,int y)
{
	if(h==0)return y+1;
	return 2*f(h-1,y);	
}
