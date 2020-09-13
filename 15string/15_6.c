#include <stdio.h>
#include <string.h>

void ToLower(char *s);
char s1[1000000], s2[10000000];
int main()
{
	gets(s1);
	gets(s2);
	ToLower(s1);
	ToLower(s2);
	int t = 0;
	char *pch;
	int firstPos;
	pch = strtok(s2," ");
	while(pch !=NULL)
	{
		if(strcmp(pch,s1)==0)
		{
			t++;
			if(t==1)firstPos = pch-s2;
		}
		pch = strtok(NULL," ");
	}
	if(t>0)
		printf("%d %d\n",t,firstPos);
	else
		printf("-1\n");
	return 0;
}

void ToLower(char *s)
{
	int len = strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')s[i]+=32;
	}
}
