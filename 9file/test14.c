#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
	char id[10];
	char name[20];
	double score;
}Stu;

int cmp(const void *s1,const void *s2)
{
	Stu *a = (Stu *)s1;
	Stu *b = (Stu *)s2;
	return a->score < b->score;
}

int main()
{
	FILE *fp;
	char filename[20];
	printf("请输入文件名称：\n");
	scanf("%s",filename);
	fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	printf("请输入要记录的学生数目:");
	int m;
	scanf("%d",&m);
	Stu s;
	for(int i=1;i<=m;i++)
	{
		scanf("%s %s %lf",s.id,s.name,&s.score);

		//printf("%s %s %5.2lf\n",s.id,s.name,s.score);
		fwrite(&s,sizeof(s),1,fp);
	}
	fclose(fp);
	fp = fopen(filename,"rb");
	Stu stu[20];
	int i = 0;
	while(fread(&s,sizeof(Stu),1,fp))
	{
		stu[i] = s;
		printf("%s %s %5.2lf\n",stu[i].id,stu[i].name,stu[i].score);
		i++;
	}
	qsort(stu,i,sizeof(Stu),cmp);
	fclose(fp);
	fp = fopen(strcat(filename,"score.txt"),"w");
	if(fp==NULL)
	{
		printf("打开失败！");
		exit(0);
	}
	fprintf(fp,"%s %s %s\n","id","name","score");
	for(int j=0;j<i;j++)
	{
		fprintf(fp,"%s %s %5.2lf\n",stu[j].id,stu[j].name,stu[j].score);
	}
	fclose(fp);
	return 0;

}
