#include <stdlib.h>
#include <stdio.h>

int compare(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int values[] = {40,10,1000,60,70,20};

	qsort(values,6,sizeof(int),compare);

	for (int i=0;i<6;i++)
	{
		printf("%d ",values[i]);
	}
	return 0;
}
