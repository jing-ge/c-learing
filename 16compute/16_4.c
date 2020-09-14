#include <stdio.h>
#include <string.h>
#define MAXLEN 1010
char str1[MAXLEN];

int main()
{
	int b;
	printf("输入被除数和除数：\n");
	scanf("%s %d",str1,&b);
	int a[MAXLEN],c[MAXLEN];
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	int len1 = strlen(str1);
	for(int i = 0;i<len1;i++)
		a[i] = str1[i]-'0';
	int x = 0;
	for(int i = 0;i<len1;i++)
	{
		c[i] = (x * 10+a[i])/b;
		x = (x * 10 + a[i]) % b;
	}
	int len = 0;
	while(c[len]==0&&len<len1)
		len++;
	char str[MAXLEN];
	memset(str,0,MAXLEN);
	for(int i = len,j=0;i<len1;i++)
		str[j++] = c[i]+'0';
	printf("%s ÷ %d =  %s\n",str1,b,str);
	return 0;
}
