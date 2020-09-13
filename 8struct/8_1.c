#include <stdio.h>
#include <math.h>
#include <string.h>

struct coord
{
	int x;
	int y;
};

struct book
{
	char title[100];
	char author[100];
	float price;
	int pages;
};
int main()
{
	struct coord first,second;
	double distance;

	printf("输入第一个点坐标：\n");
	scanf("%d %d",&first.x,&first.y);
	printf("输入第二个点坐标：\n");
	scanf("%d %d",&second.x,&second.y);

	int xDiff = first.x - second.x;
	int yDiff = first.y - second.y;
	distance = sqrt(xDiff*xDiff+yDiff*yDiff);
	printf("两点之间距离为：%f\n",distance);

	struct book mybook,*ptbook;
	ptbook = &mybook;
	strcpy(ptbook->title,"my First book");
	strcpy(ptbook->author,"feng bo jing");
	ptbook->price = 30.9999;
	ptbook->pages = 99;
	printf("book info:\n");
	printf("book  title:%s\n",ptbook->title);
	printf("book author:%s\n",ptbook->author);
	printf("book  price:%f\n",ptbook->price);
	printf("book  pages:%d\n",ptbook->pages);
	return 0;
}
