#include <stdio.h>
int Isop(char op)
{
	if(op=='+'||op=='-'||op=='*'||op=='/')
	return 1;
	return 0;	
}
int Compute(int a,char op,int b)
{
	int res;
	switch(op)
	{
		case '+':res = a+b;break;
		case '-':res = a-b;break;
		case '*':res = a*b;break;
		case '/':res = a/b;break;
	}
	return res;
}
int Priority(char op)
{
	int res;
	switch(op)
	{
		case '+':
		case '-': res = 1;break;
		case '*': 
		case '/': res = 2;break;
	}
	return res;
}
int main()
{
	int a,b,c;
	char op1,op2;
	printf("输入表达式 = 结束\n");
	a = 0;
	op1 = '+';
	scanf("%d",&b);
	while(1)
	{
		op2 = getchar();
		if(op2=='=')break;
		else scanf("%d",&c);
		if(!Isop(op2))
		{
			printf("Error\n");
			return 0;
		}
		if(Priority(op1)>= Priority(op2))
		{
			if(op1 == '/'&& b==0)
			{
				printf("divided by 0\n");
				return 0;
			}
			a = Compute(a,op1,b);
			op1 = op2;
			b = c;
		}
		else
		{
			if(op2=='/'&&c==0)
			{
				printf("divided by 0\n");
				return 0;
			}
			b = Compute(b,op2,c);
		}
		//printf("%d %d\n",a,b);
	}
	if(op1=='/'&&b==0)
	{
		printf("divided by 0\n");
		return 0;
	}
	a = Compute(a,op1,b);
	printf("%d\n",a);
	return 0;
}
