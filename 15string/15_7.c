#include <stdio.h>
#include <string.h>

int main()
{
	char str[100],t[100];
	int a[100],k;
	const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while(scanf("%s",str)!=EOF)
	{
		scanf("%d",&k);
		int len = strlen(str);
		for(int i = 0;i<len;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<len;i++)
			str[i] = table[(str[i]-'A'+k)%26];
		for(int i=0;i<len;i++)
			t[i] = str[a[i]-1];
		t[len] = '\0';
		printf("%s\n",t);
	}
	return 0;
}
