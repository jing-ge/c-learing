#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 10
#define K 1e6

void Ftick(double (*fp)(double *,int ,double));
double Ployf1(double a[],int n,double x);
double Ployf2(double a[],int n,double x);
double Ployf3(double a[],int n,double x);
double Ployf4(double a[],int n,double x);

clock_t start,end;
double dur;
double a[N+1],x = 1.1;

int main()
{
	for(int i=0;i<=N;i++)
		a[i] = i;
	Ftick(Ployf1);
	Ftick(Ployf2);
	Ftick(Ployf3);
	Ftick(Ployf4);

	return 0;
}



void Ftick(double (*fp)(double *,int ,double))
{
	double sum;
	start = clock();
	for(int i=1;i<=K;i++)
	{
		sum = fp(a,N,x);
	}
	end = clock();
	dur = (double)(end-start)/CLK_TCK/K;
	printf("f(x) = %f,time = %6.2e\n",sum,dur);
}
double Ployf1(double a[],int n,double x)
{
	double sum = 0;
	for(int i=0;i<=n;i++)
	{
		sum += a[i]*pow(x,i);
	}
	return sum;
}
double Ployf2(double a[],int n,double x)
{
	double sum = a[0];
	for(int i=1;i<=n;i++)
	{
		double tmp = 1;
		for (int j=1;j<=i;j++)
		{
			tmp *= x;
		}
		sum += a[i]*tmp;
	}
	return sum;
}
double Ployf3(double a[],int n,double x)
{
	double sum = a[0];
	double tmp = 1;
	for(int i = 1;i<=n;i++)
	{
		tmp *=x;
		sum += a[i]*tmp;
	}
	return sum;
}
double Ployf4(double a[],int n,double x)
{
	double sum = a[n];
	for(int i=n-1;i>=0;i--)
	{
		sum = sum*x+a[i];
	}
	return sum;
}
