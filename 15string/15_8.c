#include <stdio.h>
#include <string.h>

int main()
{
	char str[202];
	gets(str);
	int i = 0,j = 0;
	int flag = 1;
	while(str[j])
	{
		if(str[j]!=' ')
		{
			str[i++] = str[j];
			flag = 1;
		}
		else if(str[j]==' '&&flag)
		{
			str[i++] = str[j];
			flag = 0;
		}
		j++;
	}
	str[i] = '\0';
	printf("%s",str);
	return 0;
}
