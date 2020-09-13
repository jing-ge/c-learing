#include <stdio.h>

int IsLeap(int y);
int monthdays[2][13] = {{0,31,28,31,30},{0,31,29,31,30}};

int main()
{
	int year;
	printf("输入要求哪一年的母亲节：");
	scanf("%d",&year);
	int days = 0,i;
	for(int i=1900;i<year;i++)
	{
		if(IsLeap(i))
			days += 366;
		else
			days += 365;
	}
	int leap = 0;
	if(IsLeap(year))leap = 1;
	for(int i =1;i<5;i++)
	{
		days += monthdays[leap][i];
	}
	int dayofweek,motherday;
	dayofweek = days %7;
	motherday = (14-dayofweek);
	printf("%d年5月%d号是母亲节\n",year,motherday);
	return 0;
}
int IsLeap(int y)
{
	if(y%400==0||y%4==0&&y%100!=0)
		return 1;
	else
		return 0;
}
