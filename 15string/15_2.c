#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	char str[101];
	while(n--)
	{
		int sum = 0;
		scanf("%s",str);
		for(int i = 0;str[i];i++)
		{
			sum+=str[i]-'0';
		}
		if(sum%3==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
