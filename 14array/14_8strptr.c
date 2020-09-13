#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

int cmp(const void *a,const void *b)
{
	return strcmp(*(char **)a,*(char **)b);
}

int main(void)
{
	int n,i;
	char *s[N];
	printf("请输入字符的个数： ");
	scanf("%d",&n);
	printf("请输入%d个字符串：\n",n);
	for(int i=0;i<n;i++)
	{
		s[i] = (char *)malloc(21*sizeof(char));
		scanf("%s",s[i]);
	}
	printf("%d\n",sizeof(s[0]));
	qsort(s,n,sizeof(s[0]),cmp);
	printf("排序后结果为：\n");
	for(int i = 0;i<n;i++)
		printf("%s ",s[i]);
	printf("\n");
	for(int i = 0;i<n;i++)
		free(s[i]);
	return 0;
}
