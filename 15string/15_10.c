#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int shu[1000];
	char str[500];
	scanf("%s",str);
	int k = 0;
	int len =strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i] <'0'||str[i]>'9')
			str[i] = ' ';
	}
	char *pch = strtok(str," ");
	while(pch)
	{
		shu[k++] = atoi(pch);
		pch = strtok(NULL," ");
	}
	for(int i = 0;i<k;i++)
		printf("%d\n",shu[i]);
		return 0;
}
