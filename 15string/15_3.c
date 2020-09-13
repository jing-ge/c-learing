#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int charTonumber[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

int compare(const void *elem1,const void*elem2)
{
	return (strcmp((char*)elem1,(char*)elem2));
}

void output(char telNumbers[][9],int n);
void standardTel(char s1[],char s2[]);

int main()
{
	char a[80],b[10];
	char telNumbers[10000][9];
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		standardTel(a,b);
		strcpy(telNumbers[i],b);
		//printf("%s\n",b);
	}
	qsort(telNumbers,n,9,compare);
	/*
	printf("---------\n");
	for(int i=0;i<n;i++)
	{
		printf("%d:%s\n",i,telNumbers[i]);
	}
	printf("---------\n");
	*/
	output(telNumbers,n);
	return 0;
}


void output(char telNumbers[][9],int n)
{
	int flag = 1;
	int i = 0; 
	while(i<n) 
	{ 
		int j = i+1; 
		//printf("~~~~~~~~~~~\n");
		//printf("%s\n",telNumbers[i]);
		//printf("%s\n",telNumbers[j]);
		//printf("%d\n",strcmp(telNumbers[i],telNumbers[j]));
		//printf("~~~~~~~~~~~\n");
		while(j<n&&strcmp(telNumbers[i],telNumbers[j])==0)
			j++; 
		if(j-i>1) 
		{ 
			printf("%s %d\n",telNumbers[i],j-i);
			flag = 0;
		}
		i =j;
	}
	if(flag)printf("No dulicates.\n");
}
void standardTel(char s1[],char s2[])
{
	int len = strlen(s1),t;
	int phone_number = 0;
	for(int i=0;i<len;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')t = s1[i]-'0';
		else if(s1[i]>='A'&&s1[i]<='Z')t = charTonumber[s1[i]-'A'];
		else t=-1;
		if(t!=-1)phone_number = phone_number*10+t;
	}
	sprintf(s2,"%03d-%04d\n",phone_number/10000,phone_number%10000);
	s2[8] = '\0';
}
