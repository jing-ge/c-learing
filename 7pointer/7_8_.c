#include <stdio.h>

int sum(int (*p)[3],int n);

int main(void)
{
	int a[5][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
	
	printf("sum = %d\n",sum(a,5));
	return 0;
}

int sum(int (*p)[3],int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		for(int j = 0;j<3;j++)
		{
			sum += *(*p+j);
		}
		p++;
	}
	return sum;
}
