#include <stdio.h>

int IsLeap(int y);
void WeekValue(int y);
void MonCalendar(int y,int m);
int monthdays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int weekofmonth[13];
char months[13][15] = {"","January","Feburary","March","April","May","June","July","August","September","October","November","December"};
void MonCalendar(int y,int m)
{
	printf("\t%s(%d)\n",months[m],y);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for(int i=0;i<weekofmonth[m];i++)
	{
		printf("    ");
	}
	if(IsLeap(y)) monthdays[2] = 29;
	else monthdays[2] = 28;
	int k = weekofmonth[m];
	for(int i=1;i<=monthdays[m];i++)
	{
		printf("%3d ",i);
		k++;
		if(k%7==0)printf("\n");
	}
	printf("\n");
}
int main(void)
{
	int year, month;
	scanf("%d %d",&year, &month);
	WeekValue(year);
	MonCalendar(year,month);
	return 0;
}
int IsLeap(int y)
{
	return y%400==0||y%4==0&&y%100!=0;
}
void WeekValue(int y)
{
	int days = 0;
	for(int i=1900;i<y;i++)
	{
		if(IsLeap(i))
			days += 366%7;
		else
			days += 365%7;
	}
	if(IsLeap(y)) monthdays[2] = 29;
	for(int i = 1;i<=12;i++)
	{
		weekofmonth[i] = (days+1)%7;
		days += monthdays[i];
	}
	return;
}

