#include <stdio.h>
#include <string.h>
#define MAXLEN 1001

void Invert(char *s,int *a);
char str1[MAXLEN],str2[MAXLEN],str[2*MAXLEN];
int a[MAXLEN],b[MAXLEN];
int c[2*MAXLEN];

int main()
{
	printf("输入两个乘数：\n");
	scanf("%s %s",str1,str2);
	int len1 = strlen(str1),len2 = strlen(str2);
	int sign = 1,k;//符号
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	k = 0;
	if(str1[0]=='-')
	{
		len1--;
		sign*=-1;
		k++;
	}
	Invert(str1+k,a);
	k = 0;
	if(str2[0]=='-')
	{
		len2--;
		sign*=-1;
		k++;
	}
	Invert(str2+k,b);

	memset(c,0,sizeof(c));
	for(int i=0;i<len2;i++)
	{
		for(int j=0;j<len1;j++)
			c[i+j] += a[j]*b[i];
	}
	for(int i=0;i<len1+len2;i++)
	{
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
	int i = len1+len2-1,j=0;
	while(c[i]==0)i--;
	memset(str,0,sizeof(str));
	for(;i>=0;i--)
		str[j++] = c[i]+'0';
	if(strlen(str)==0)str[0] = '0';
	printf("%s * %s = ",str1,str2);
	if(sign==-1)printf("-");
	printf("%s",str);
	return 0;
}
void Invert(char *s,int *a)
{
	int len = strlen(s);
	int j = 0;
	for(int i=len-1;i>=0;i--)
		a[j++] = s[i]-'0';
}
