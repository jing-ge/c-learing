#include <stdio.h> 

struct Date
{
	unsigned int month:4;  //�����е��� 
	unsigned int day:5;    //�����е��� 
	signed int year:22;    //�����е��� 
          _Bool isDST:1;         //���������ʱ 
};
int main(void) 
{ 
	struct Date birthday = {12,3,1980}; //��ʼ���б�ʽ��ʼ������ 
	struct Date d;
	printf("%d\n",sizeof(d)); 
	d.day = 1;
	d.month = 2;
	d.year = 2019;
	d.isDST = 0; 
	
	printf("%02d-%02d-%04d\n",d.month,d.day,d.year);
	
	return 0; 
}

