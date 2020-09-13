#include <stdio.h>
#include <stdlib.h>

typedef struct Rec
{
	char id[10];
	char name[20];
	float price;
	int count;
} Rec;


int main()
{
	char filename[20];
	FILE *fp;
	int m;
	Rec record;

	printf("请输入商品信息文件名:\n");
	scanf("%s",filename);
	fp = fopen(filename,"rb");
	if(fp==NULL)
	{
		printf("打开文件失败");
		exit(0);
	}
	while(fread(&record,sizeof(record),1,fp))
	{
		printf("%s %s %5.2f %d\n",record.id,record.name,record.price,record.count);
	}
	printf("请输入要读取的商品记录号：\n");
	scanf("%d",m);
	fseek(fp,(m-1)*sizeof(Rec),0);
	fread(&record,sizeof(Rec),1,fp);
	printf("第%d条记录：\n%s %s %5.2f %d\n",record.id,record.name,record.price,record.count);

	fclose(fp);
	return 0;

}
