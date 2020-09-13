#include <stdio.h>

struct Date
{
	unsigned int month:4;
	unsigned int day:5;
	signed int year:22;
	_Bool isDST:1;
};

int main()
{
	struct Date birthday = {12,3,1980,0};
	struct Date d;
	printf("%d\n",sizeof(d));
	d.day = 1;
	d.month = 2;
	d.year = 2019;
	d.isDST = 0;

	printf("%02d-%02d-%04d\n",d.month,d.day,d.year);
	return 0;
}
