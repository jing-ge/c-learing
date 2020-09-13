#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int WordNum(char* word,char *filename)
{
	FILE *fp = fopen(filename,"r");
	if(fp==NULL)
	{
		printf("打开文件失败！");
		exit(0);
	}
	int i = 0,num = 0;
	char r[30];
	while(!feof(fp))
	{
		char ch = fgetc(fp);
		if(ch>='a'&& ch<='z'||ch>='A'&&ch<='Z')
		{
			r[i++] = ch;	
		}
		else
		{
			r[i] = '\0';
			i= 0;
			if(!strcmp(word,r))
				num++;
		}
	}
	fclose(fp);
	return num;
}

int main()
{
	char filename[20];
	char word[10];
	printf("请输入文件名：\n");
	scanf("%s",filename);	
	printf("请输入要查找的单词：\n");
	scanf("%s",word);
	int res = WordNum(word,filename);	
	printf("%s中有单词%s的数目为：%d",filename,word,res);
	return 0;
}
