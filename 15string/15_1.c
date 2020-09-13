#include <stdio.h>

int main()
{
	char str[1001];
	int count[26] = {};

	scanf("%s",str);
	for(int i=0;str[i];i++)
	{
		count[str[i]-'a']++;
	}
	int max = 0;
	for(int i=1;i<26;i++)
	{
		if(count[max]<count[i])max =i; 
	}
	printf("%c %d",max+'a',count[max]);
	return 0;
}
