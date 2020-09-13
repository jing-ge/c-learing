#include <stdio.h>

double Add(double x,double y);
double Sub(double x,double y);
double Mul(double x,double y);
double Div(double x,double y);

double(*funTable[4])(double,double) = {Add,Sub,Mul,Div};
char *msgTable[4] = {"sum","Difference","Product","Quotient"};
int main()
{
	double x =0,y = 0;
	printf("输入两个运算数：\n");
	scanf("%lf %lf",&x,&y);
	for(int i=0;i<4;i++)
	printf("%10s:%6.2f\n",msgTable[i],funTable[i](x,y));
	return 0;
}
double Add(double x,double y)
{
	return x+y;
}
double Sub(double x,double y)
{
	return x-y;
}
double Mul(double x,double y)
{
	return x*y;
}
double Div(double x,double y)
{
	return x/y;
}
