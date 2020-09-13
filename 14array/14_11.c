#include <stdio.h>

const int N =11;
int AnDian(int a[][N], int n, int m, int *r ,int *c);


int main()
{
	int a[N][N];
	int r,c,n,m;
	printf("输入n,m以及n*m个元素：\n");
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	}
	int res = AnDian(a,n,m,&r,&c);
	if(res)
		printf("%d %d %d",r,c,a[r][c]);
	else 
		printf("not found");
}
int AnDian(int a[][N], int n, int m, int *r ,int *c)
{
	int flag = 0;
	for(int row=1;row<=n;row++)
	{
		int col = 1,j;
		for(j = 2;j<=m;j++)
		{
			if(a[row][j]>a[row][col])col = j;
		}
		for(j = 1;j<=n;j++)
		{
			if(a[j][col]<a[row][col])
				break;
		}
		if(j==n+1)
		{
			flag = 1;
			*r = row;
			*c = col;
			break;
		}
	}
	return flag;
}

