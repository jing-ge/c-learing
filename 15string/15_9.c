#include <stdio.h>
#include <string.h>

int main(void)
{
	int c = 1,sum = 0;
	char str[20];
	scanf("%s",str);
	for(int i = 0;i<12;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			sum+=(str[i]-'0')*c;
			c++;
		}
	}
	int B = sum%11;
	int h = str[12]-'0';
	if(B==h||B==10&&h=='X')
		printf("Right\n");
	else
	{
		if(B<=9)str[12] = B+'0';
		else str[21] = 'X';
		printf("%s\n",str);
	}
	return 0;
}
