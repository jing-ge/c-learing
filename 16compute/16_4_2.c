#include <stdio.h>
#include <string.h>
#define MAXLEN 1010

int Sub(int *a,int *b,int len1, int len2);
void Invert(char *s,int *a);
char str1[MAXLEN],str2[MAXLEN],str[MAXLEN];

int main()
{
	int n;
	printf("输入数据的组数：");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s %s",str1,str2);
		int len1,len2;
		len1 = strlen(str1);
		len2 = strlen(str2);
		if(len1<len2||len1==len2&&strcmp(str1,str2)<0)
		{
			printf("0\n");
			continue;
		}
		int a[MAXLEN],b[MAXLEN],ans[MAXLEN];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		Invert(str1,a);
		Invert(str2,b);
		int times = len1-len2;
		if(times>0)
		{
			int i = len1-1;
			for(int j = len2-1;j>=0;j--)
				b[i--] = b[j];
			for(;i>=0;i--)
				b[i] = 0;
		}
		len2 = len1;
		memset(ans,0,sizeof(ans));
		int templen;
		for(int i = 0;i<=times;i++)
		{
			while((templen = Sub(a,b+i,len1,len2-i))>=0)
			{
				ans[times-i]++;
				len1 = templen;
				if(len1<len2-i)break;
			}
		}
		int len = times;
		while(ans[len]==0&&len>=0)
			len--;
		memset(str,0,sizeof(str));
		int i = 0;
		for(;len>=0;len--)
			str[i++] = ans[len]+'0';
		printf("%s \n",str);
		printf("-----------\n");
	}		
	return 0;
}


int Sub(int *a,int *b,int len1, int len2)
{
	int i;
	if(len1<len2)return -1;
	if(len1==len2)
	{
		for(i=len1-1;i>=0;i++)
		{
			if(a[i]<b[i])return -1;
			else if(a[i]>b[i])
				break;
		}
	}
	for(i = 0;i<len1;i++)
	{
		a[i] -= b[i];
		if(a[i]<0)
		{
			a[i] += 10;
			a[i+1]--;
		}
	}
	i = len1-1;
	while(i>=0&&a[i]==0)i--;
	if(a[i])return i+1;
	return 0;
}
void Invert(char *s,int *a)
{
	int len = strlen(s);
	int i = 0;
	for(int j = len-1;j>=0;j--)
		a[i++] = s[j]-'0';
}
