#include <stdio.h>
#include <stdlib.h>
#define N 20
typedef struct Student
{
	int sno;
	int age;
}Student;
int cmp(const void *a,const void *b)
{
	Student *aa = (Student *)a;
	Student *bb = (Student *)b;
	if(aa->age!=bb->age)
		return aa->age-bb->age;
	else
		return aa->sno-bb->sno;
}

int main(void)
{
	int n,i;
	Student s[N];
	printf("请输入元素个数:");
	scanf("%d",&n);
	printf("请输入%d个学生的信息（学号 年龄）:\n",n);
	for(int i = 0;i<n;i++)
		scanf("%d %d",&s[i].sno,&s[i].age);
	qsort(s,n,sizeof(s[0]),cmp);
	printf("排序后结果为：\n");
	for(int i = 0;i<n;i++)
		printf("%d %d\n",s[i].sno,s[i].age);
	printf("\n");
	return 0;
}
