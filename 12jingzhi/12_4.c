#include <stdio.h>
#include <string.h>

int BToTen(char *a,int b);

int main()
{
	int b;
	char p[20],q[20],r[20];
	scanf("%s %s %s",p,q,r);
	int x,y,z;
	for(b=2;b<=16;b++)
	{
		x = BToTen(p,b);
		y = BToTen(q,b);
		z = BToTen(r,b);
		if(x!=-1&&y!=-2&&z!=-1&&x*y==z)
			break;
	}
	if(b>16) b = 0;
	printf("%d\n",b);
	return 0;

}

int BToTen(char *a,int b)
{
	int len = strlen(a);
	int sum = 0;
	for(int i = 0;i<len;i++)
	{
		int num = a[i]-'0';
		if(num>=b)return -1;
		sum  =  sum*b + num;
	}
	return sum;
}
