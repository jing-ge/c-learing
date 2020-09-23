#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mycon.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int who, money, i,total;
	int x[3],y[3],c[3];
	int end;
	
	total =10000;
	c[0] = 'A';
	c[1] = 'B';
	c[2] = 'C';
	
	set_size(80,25);
	set_color(3,0xa);
	cls();
	
	set_title("超级赌马大赛!");
	while(1)
	{
		end = 0;
		for(i=0;i<3;i++)
		{
			x[i] = 0;
		}
		y[0] = 8;
		y[1] = 11;
		y[2] = 14;
		gotoxy(33,1);
		printf("超级赌马大赛！");
		for(i=0;i<3;i++)
		{
			gotoxy(x[i],y[i]);
			printf("%c",c[i]);
		}
		for(i=6;i<=15;i++)
		{
			gotoxy(75,i);
			printf("||");
		}
		
		gotoxy(1,23);
		printf("你的赌资为：%d元！	",total);
		while (1)
		{
			gotoxy(30,23);
			printf("请下注：");
			scanf("%c %d",&who,&money);
			fflush(stdin);
			if(money<total)break;
			else{
				gotoxy(38,23);
				printf("         ");
			} 
		}
		srand((unsigned)time(NULL));
		
		hide_cursor();
		
		while(!end)
		{
			i = rand()%3;
			gotoxy(x[i],y[i]);
			printf(" ");
			x[i] = x[i] +2;
			if(x[i]>75){
				end = 1;
				gotoxy(50,23);
				printf("本次%c获胜！",c[i]);
				if((who==c[i])||(who==(c[i]+'a'-'A')))
				{
					total = total +money;
					printf("您赢了%d元！",money);
				}
				else
				{
					total = total -money;
					printf("您输了%d元！",money);
					if(total<0)
					{
						gotoxy(1,23);
						printf("你的赌资为：%d元！	",total);
						
						gotoxy(30,11);
						printf("可怜的娃，您输光了！");
						getkey();
						exit(0); 
					}
				}
				gotoxy(30,23);
				printf("        ");
			}
			gotoxy(1,23);
			printf("您的赌资现为：%d元！",total);
			for(i=0;i<3;i++)
			{
				gotoxy(x[i],y[i]);
				printf("%c",c[i]);
			}
			delay(100);
		}
		getkey();
		cls;
	}
	getkey();
	return 0;
	 
	return 0;
}
