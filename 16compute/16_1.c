#include <stdio.h>
#include <string.h>

#define MAXLEN 210

void Invert(char *a,int *b);

int main()
{
	char str1[MAXLEN],str2[MAXLEN],str[MAXLEN];
	int a[MAXLEN],b[MAXLEN],c[MAXLEN];
	printf("输入两个加数\n");
	scanf("%s %s",str1,str2);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	Invert(str1,a);
	Invert(str2,b);
	int len = strlen(str1)>strlen(str2)?strlen(str1):strlen(str2);
	for(int i=0;i<len;i++)
	{
		c[i] += a[i] + b[i];
		c[i+1] = c[i]/10;
		c[i] %= 10;
	}
	printf("-----------\n");
	while(len>=0&&c[len]==0)len--;
	memset(str,0,sizeof(str));
	int i=0;
	for(int j=len;j>=0;j--)
		str[i++] = c[j] + '0';
	if(strlen(str)==0)str[0] = '0';
	printf("%s + %s = %s\n",str1,str2,str);
	return 0;
}
void Invert(char *a,int *b)
{
	int len = strlen(a);
	int j = 0;
	for(int i=len-1;i>=0;i--)
	{
		b[j] = a[i]-'0';
		j++;
	}
}
