#include <stdio.h>

int monthdays[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
    			 {0,31,28,31,30,31,30,31,31,30,31,30,31}};
int days[2][13];
int IsLeap(int year)
{
	return (year %4==0&&year%100!=0||(year%400==0));
}

void DaysF();
void print();

int main()
{
	int year,ans=0;
	int yeardays [2] = {365,366};
	DaysF();
	printf("输入年份：");
	scanf("%d",&year);
	int leap = 0;
	if(IsLeap(year))leap = 1;
	for(int i = 1;i<=12;i++)
	{
		int n = (year-1)*365 +(year-1)/4-(year-1)/100+(year-1)/400;
		if((n+days[leap][i])%7==5)
		{
			printf("%d-%d-13\n",year,i);
			ans++;
		}
	}
	if(ans)
	{
		printf("%d年有%d个黑色星期五\n",year,ans);
	}
	else
	{
		printf("%d年没有黑色星期五\n");
	}
	return 0;
}

void DaysF()
{
	for(int leap = 0;leap<=1;leap++)
	{
		days[leap][0] = 13;
		for(int m = 1;m<=12;m++)
		{
			days[leap][m] = days[leap][m-1]+monthdays[leap][m-1];
		}
	}
}
void print()
{
	for(int m = 0;m<=12;m++)
		printf("%d\t",days[0][m]);
	printf("\n");
	for(int m = 0;m<=12;m++)
		printf("%d\t",days[1][m]);
	printf("\n");
}
