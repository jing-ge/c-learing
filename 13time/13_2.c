#include <stdio.h>

typedef struct Date
{
	int year,month,day;
}Date;
int IsLeap(int y);
int Days(Date dd);
void NextNDate(int days,Date *pd);
int monthdays[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
			{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int main()
{
	Date today;
	int n;
	scanf("%d-%d-%d %d",&today.year,&today.month,&today.day,&n);
	int sumdays = Days(today);
	NextNDate(sumdays+n,&today);

	printf("%d-%02d-%02d",today.year,today.month,today.day);
	return 0;
}
int IsLeap(int y)
{
	return y%400 == 0||y%4==0&&y%100!=0;
}
int Days(Date dd)
{
	int sum = 0,leap = 0;
	if(IsLeap(dd.year))leap = 1;
	for(int i=1;i<dd.month;i++)
	{
		sum += monthdays[leap][i];
	}
	sum +=dd.day;
	return sum;
}
void NextNDate(int days,Date *pd)
{
	int y,m,yeardays;
	y = pd->year;
	yeardays = 365;
	if(IsLeap(y))yeardays = 366;
	while(days>yeardays)
	{
		days -= yeardays;
		y++;
		yeardays = 365;
		if(IsLeap(y))yeardays = 366;
	}
	//printf("year:%d\n",y);
	//printf("left:days:%d\n",days);
	int leap = 0;
	if(IsLeap(y))leap = 1;
	m = 1;
	while(days>monthdays[leap][m])
	{
		days -= monthdays[leap][m];
	//	printf("days:%d\n",days);
		m++;
	}
	//printf("month:%d",m);
	
	//printf("days:%d\n",days);
	pd->year = y;
	pd->month = m;
	pd->day = days;
}
