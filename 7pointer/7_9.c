#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x = 5;
	int *p[3] = {NULL,NULL,NULL};
	p[0] = (int *)malloc(7 * sizeof(int));
	p[1] = (int *)malloc(5 * sizeof(int));
	p[2] = &x;
	for(int i=0;i<3;i++)
	{
		printf("%#X\n",p[i]);
	}
	
	char *weeks[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	for(int i=0;i<7;i++)
		printf("%s\n",weeks[i]);
	return 0;
	
}

