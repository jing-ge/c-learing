#include <stdio.h>
void SubSet(int *a,int i);

int main()
{
	int a[] = {1,2,3},N;
	N = sizeof(a)/sizeof(int);
	int t = 1<<N;
	for(int i=1;i<t;i++)
		SubSet(a,i);
	return 0;
}

void SubSet(int *a,int i)
{
	int k,flag = 0;
	printf("{");
	k = 0;
	while(i)
	{
		if(i&1)
		{
			if(flag) printf(",");
			printf("%d",a[k]);
			flag = 1;
		}
		i>>=1;
		k++;
	}
	printf("}\n");
}
