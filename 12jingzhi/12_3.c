#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Bin2Hex(char *bin,char *hex);

int main()
{
	char bin[30];
	char hex[10];
	scanf("%s",bin);
	Bin2Hex(bin,hex);
	printf("%s",hex);
	return 0;
}

void Bin2Hex(char *bin,char *hex)
{
	int len = strlen(bin);
	int r = len/4 + 1;
	int flag = 4-len%4;
	char newbin[200];
	newbin[0] = '\0';
	for(int i=0;i<flag;i++)
	{
		strcat(newbin,"0");
	}
	strcat(newbin,bin);
	//printf("%s\n",newbin);
	int i=0;
	while(i<r)
	{
		int res = 0;
		int start = 4*i;
		char ch;
		if(newbin[start]=='1')res+=8;
		if(newbin[start+1]=='1')res+=4;
		if(newbin[start+2]=='1')res+=2;
		if(newbin[start+3]=='1')res+=1;
		if(res<10)ch = res+'0';
		else ch = res - 10 +'A';
		hex[i] = ch;
		i++;
	}
	hex[i] = '\0';

}
