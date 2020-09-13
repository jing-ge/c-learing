#include <stdio.h>
#include <string.h>

int ToDec(char *a,int base);
void DecToM(int src,int base,char* res);
void M2N(char *src,char*des,int M,int N);
int main()
{
	char a[20];
	int res ;
	scanf("%s",a);
	/*res = ToDec(a,8);
	printf("%d\n",res);
	DecToM(res,8,a);
	printf("--------------");
	*/
	char des[20];
	M2N(a,des,8,16);
	printf("%s\n",des);

	return 0;
}
int ToDec(char *a,int base)
{
	int sum = 0;
	int len = strlen(a);
	for(int i=0;i<len;i++)
	{
		sum = sum*base + a[i]-'0';
	}
	return sum;

}
void DecToM(int src,int base,char* res)
{
	int i=0;
	int yu=0;
	while(src!=0)
	{
		yu = src%base;
		src = src/base;
		res[i] = yu + '0';
		i++;
	}
	res[i] = '\0';
	i--;
	int j=0;
	while(j<i)
	{
		char ch = res[j];
		res[j] = res[i];
		res[i] = ch;
		i--;j++;
	}
}
void M2N(char *src,char *des,int M,int N)
{
	int res = ToDec(src,M);
	DecToM(res,N,des);

}
