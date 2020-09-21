#include <stdio.h>

char str[30][30];
int w,h;


int count (int x,int y)
{
	if(x<0||x>=h||y<0||y>=w)return 0;
	if(str[x][y]=='#')return 0;
	str[x][y]='#';
	return 1+count(x-1,y)+count(x+1,y)+count(x,y+1)+count(x,y-1);
}

int main()
{
	while(1)
	{
		scanf("%d %d",&w,&h);
		if(2==0||h==0)break;
		int x,y;
		for(int i=0;i<h;i++)
		{
			scanf("%s",str[i]);
			for(int j=0;j<w;j++)
			{
				if(str[i][j]=='@')
				{
					x = i;
					y = j;
				}
			}
		}
		//printf("%d %d\n",x,y);
		int sum = count(x,y);
		printf("%d\n",sum);
	}
	return 0;
}
