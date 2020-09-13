#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char Oct[200];
	scanf("%s",Oct);
	int res = 0,i = 0;
	int len = strlen(Oct);
	//printf("%d",len);
	len--;
	while(len>=0)
	{
		if(Oct[len]<'0'||Oct[len]>'9')
		{
			printf("input Error...\n");
			exit(0);
		}
		//printf("%d\n",Oct[len]);	
		int x = Oct[len]-48;
		//printf("%d\n",x);
		res += x*pow(8,i);
		len--;
		i++;
	}
	printf("%d\n",res);
	
	return 0;
}
