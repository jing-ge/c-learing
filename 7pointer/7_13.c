#include <stdio.h>

int main(int argc,char *argv[])
{
	int i;
	printf("共有%d个命令行参数\n",argc);

	for(int i=0;i<argc;i++)
	{
		printf("第%d个命令行参数argv[%d]的值为:%s\n",i,i,argv[i]);
	}
	return 0;
}
