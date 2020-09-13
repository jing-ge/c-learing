#include <stdio.h>
#include <string.h>

int main()
{
	char word[33],sub[4] = {'\0'};
	scanf("%s",word);
	int len = strlen(word);
	if(len>2)
	{
		strncpy(sub,word+len-2,2);
		sub[2] = '\0';
		if(strcmp(sub,"er")==0||strcmp(sub,"ly")==0)
			word[len-2] = '\0';
	}
	if(len>3)
	{
		strncpy(sub,word+len-3,3);
		sub[3] = '\0';
		if(strcmp(sub,"ing")==0)
			word[len-3] = '\0';
	}
	printf("%s\n",word);
	return 0;
}
