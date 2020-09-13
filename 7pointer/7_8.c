#include <stdio.h>

int main(void)
{
	int a[5][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
	int (*p)[3] = a;
	int sum = 0;
	for(int i=0;i<5;i++)
	{
		for(int j = 0;j<3;j++)
		{
			sum += *(*p+j);
		}
		p++;
	}
	printf("sum = %d\n",sum);
	return 0;
}
