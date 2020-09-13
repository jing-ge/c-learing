#include <stdio.h>

typedef struct student
{
	char name[21];
	int aveScore;
	int classScore;
	char leader;
	char west;
	int articles;
}Student;

int main()
{
	Student stu[100];
	int n;
	scanf("%d",&n);
	int sum = 0;
	int maxjin = 0, k = 0;
	for(int i=0;i<n;i++)
	{
		int jiangjin = 0;
		scanf("%s %d %d %c %c %d",stu[i].name,&stu[i].aveScore,&stu[i].classScore,&stu[i].leader,&stu[i].west,&stu[i].articles);
		if(stu[i].aveScore > 80 && stu[i].articles>=1)jiangjin += 8000;
		if(stu[i].aveScore > 85 && stu[i].classScore>=80)jiangjin += 4000;
		if(stu[i].aveScore > 90)jiangjin += 2000;
		if(stu[i].aveScore > 85 && stu[i].west=='Y')jiangjin += 1000;
		if(stu[i].classScore > 80 && stu[i].leader=='Y')jiangjin += 850;
		sum += jiangjin;
		if (maxjin<jiangjin)
		{
			k = i;
			maxjin = jiangjin;
		}

	}
	printf("%s\n%d\n%d\n",stu[k].name,maxjin,sum);

}
