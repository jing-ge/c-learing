#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Compute(int x,char op,int y);

int main()
{
	int n,k;
	int a,b,ans,yans;
	char op;

	printf("输入题目数以及运算符：\n");
	scanf("%d %c",&n,&op);
	srand(time(NULL));
	while(n--)
	{
		a = rand()%10 +1;
		b = rand()%10 +1;
		ans = Compute(a,op,b);
		k = 3;
		while(k--)
		{
			printf("%d %c %d = ",a,op,b);
			scanf("%d",&yans);
			if(ans==yans)break;
			else printf("no \n");
		}
		if(yans!=ans)
			printf("%d %c %d = %d\n",a,op,b,ans);
		else
			printf("ok!\n");


	}
	return 0;
}

int Compute(int x,char op,int y)
{
	int res;
	switch(op)
	{
		case '+': res = x+y;break;
		case '-': res = x-y;break;
		case '*': res = x*y;break;
		case '/': res = x/y;break;
	}
	return res;
}
