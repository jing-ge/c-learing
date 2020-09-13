#include <stdio.h>

void ReadFile(FILE *fp);
void WriteFile(FILE *fp);

int main()
{
	FILE *fp;
	char inputfile[30];

	printf("请输入文件名：");
	scanf("%s",inputfile);
	fp = fopen(inputfile,"w+");
	if(fp == NULL)
	{
		printf("打开文件失败");
		return 0;
	}
	else
	{
		printf("%s 打开文件成功\n",inputfile);
		WriteFile(fp);
		ReadFile(fp);
		fclose(fp);
	}
	return 0;
}

void WriteFile(FILE *fp)
{
	char ch;
	printf("请输入文件内容以#结束！ \n");
	while((ch=getchar())!='#')
	{
		fputc(ch,fp);
	}
	rewind(fp);//文件指针重新置于开头
}

void ReadFile(FILE *fp)
{
	char ch;
	printf("文件内容：\n");
	ch = fgetc(fp);
	while(ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	printf("\n 文件读取结束");
}
