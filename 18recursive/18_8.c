#include <stdio.h>
#include <stdlib.h>

int take[5];
int n = 0;
int like[5][5] = {{0,0,1,1,0},{1,1,0,0,1},{0,1,1,0,1},{0,0,0,1,0},{0,1,0,0,1}};

int book[5] = {0,0,0,0,0};

void Try(int i);

int main()
{
	Try(0);
	return 0;
}

void Try(int i)
{
	int j,k;
	for(j=0;j<5;j++)
	{
		if(like[i][j]==1&&book[j]==0)
		{
			take[i] = j;
			book[j] = 1;
		if(i==4)
		{
			n++;
			printf("第%d个方案\n",n);
			for(int k = 0;k<=4;k++)
			{
				printf("%d 号书分给%c\n",take[k],(char)(k+65));
			}
			printf("\n");
		}
		else
			Try(i+1);
		book[j] = 0;
		}
	}
}
