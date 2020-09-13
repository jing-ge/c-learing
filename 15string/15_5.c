#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100],s2[40];
	char temp[100] = {0};
	scanf("%s %s",s1,s2);
	if(strlen(s1)<strlen(s2))
	{
		strcpy(temp,s1);
		strcpy(s1,s2);
		strcpy(s2,temp);
	}
	strcpy(temp,s1);
	strcat(temp,s1);
	char *p = strstr(temp,s2);
	if(p)
		printf("True\n");
	else 
		printf("False\n");
	return 0;
}
