#include <stdio.h>

int main()
{
	int n,i,j;
	printf("输入n,i,j:\n");
	scanf("%d %d %d",&n,&i,&j);
	for(int col=1;col<=n;col++)
		printf("(%d,%d) ",i,col);
	printf("\n");
	for(int row=1;row<=n;row++)
		printf("(%d,%d) ",row,j);
	printf("\n");
	for(int row = 1;row<=n;row++)
	{
		int col = row-i+j;
		if(col>=1 &&col<=n)
			printf("(%d,%d) ",row,col);
	}
	printf("\n");
	for(int row = n;row>=1;row--)
	{
		int col = -row+i+j;
		if(col>=1 &&col<=n)
			printf("(%d,%d) ",row,col);
	}
	printf("\n");
	return 0;
}
