#include <stdio.h>

int main()
{
	FILE *fp;
	char inputfile[20];
	printf("请输入要打开的文件名字：\n");
	scanf("%s",inputfile);
	fp = fopen(inputfile,"r");
	if(fp == NULL)
	{
		printf("\n%s 打开失败！\n");
		return 0;
	}
	printf("%s 文件内容：\n",inputfile);
	while(!feof(fp))
		putchar(fgetc(fp));
	printf("\n");
	fclose(fp);
	return 0;

}
