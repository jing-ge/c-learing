#include <stdio.h>

typedef struct Rec
{
	char id[10];
	char name[20];
	float price;
	int count;
} Rec;

void WriteFile(FILE *fp,int n);
void ReadFile(FILE *fp,int n);

int main()
{
	char filename[20];
	int n;
	FILE *fp;
	printf("请输入目标文件名:\n");
	scanf("%s",filename);
	fp = fopen(filename,"w+");
	printf("请输入商品数目：");
	scanf("%d",&n);
	WriteFile(fp,n);
	ReadFile(fp,n);
	fclose(fp);
	return 0;

}

void WriteFile(FILE *fp,int n)
{
	int i;
	Rec record;
	printf("********请输入商品数据********\n");
	for(i = 1;i<=n;i++)
	{
		printf("请输入序号:");
		scanf("%s",record.id);
		printf("请输入名称:");
		scanf("%s",record.name);
		printf("请输入价格:");
		scanf("%f",&record.price);
		printf("请输入数量:");
		scanf("%d",&record.count);
		printf("\n");
		fprintf(fp,"%s %s %5.2f %d\n",record.id,record.name,record.price,record.count);
	}
}

void ReadFile(FILE *fp,int n)
{
	Rec record;
	double total = 0;
	rewind(fp);
	while(fscanf(fp,"%s %s %f %d\n",record.id,record.name,&record.price,&record.count)!=EOF)
	{
		printf("%s %s %5.2f %d\n",record.id,record.name,record.price,record.count);
		printf("序号：%s 名称：%s 价格：%5.2f 数量：%d\n",record.id,record.name,record.price,record.count);
		total += record.price*record.count;
	}
	printf("合计：%5.2f\n",total);;
}
