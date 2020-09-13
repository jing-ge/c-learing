#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{

	int x,ns;
	if (argc!=3)
	{
		printf("用法:convert x (8/16)\n");
		exit(1);
	}
	x = atoi(argv[1]);
	ns = atoi(argv[2]);

	switch(ns)
	{
		case 8:
			printf("%d转化为八进制为%o\n",x,x);
			break;
		case 16:
			printf("%d转化为十六进制为%x\n",x,x);
			break;
		dafault:
			printf("输入错误！");
	}
	return 0;
}
