#include <stdio.h>
#include <stdlib.h>
#include <mycon.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define LEFT 0
#define UP 1
#define RIGHT 2
#define N 3
#define DTIME (200/N)

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80

int px,py;
int rx,ry,rc;
int score;
int x[N],y[N],on[N];
int w[N];


void draw_up()
{
	gotoxy(px-1,py-1);
	printf("      ");
	gotoxy(px,py-1);
	printf("|");
	gotoxy(px,py);
	printf("0"); 
}

void draw_left()
{
	gotoxy(px-1,py-1);
	printf("      ");
	gotoxy(px-1,py-1);
	printf("\\");
	gotoxy(px,py);
	printf("0"); 
}

void draw_right()
{
	gotoxy(px-1,py-1);
	printf("      ");
	gotoxy(px+1,py-1);
	printf("/");
	gotoxy(px,py);
	printf("0"); 
}

void draw(int direct)
{
	switch(direct)
	{
		case UP:
			draw_up();
			break;
		case LEFT:
			draw_left();
			break;
		case RIGHT:
			draw_right();
	}
}

void fire(int direct)
{
	int i;
	srand(time(NULL));
	ry = py-2;
	rc = 'o';
	switch(direct)
	{
		case UP:
			rx = px;
			break;
		case LEFT:
			rx = px-1;
			break;
		case RIGHT:
			rx = px+1;
	}
//	play_sound("Boing.wav");
	while(1)
	{
		for(i=0;i<N;i++)
		{
			if((x[i]>74)||(!on[i])) 
			{
				x[i] = rand()%20;
				on[i] = 1;
				w[i] = rand()%2;
			}
			if((rx-x[i]<=4)&&(rx>x[i])&&(y[i]==ry))
			{
				on[i] = 0;
				if(!w[i])
				{
					score++;
				}
				else
				{
					score--;
					if(score < 0)
					{
						score = 0;
					}
				}
				return;
			}
		}
		gotoxy(rx,ry);
		printf("o");
		delay(100);
		gotoxy(rx,ry);
		printf(" ");
		ry--;
		if(ry<0)
		{
			return;
		}
		switch(direct)
		{
			case RIGHT:
				rx++;
				break;
			case LEFT:
				rx--;
		}
	}
}

int main(int argc, char *argv[]) 
{
	int key;
	int i;
	
	int direction;
	score = 0;
	direction = UP;
	px = 40;
	py = 24;
	
	srand(time(NULL));
	
	for(i=0;i<N;i++)
	{
		on[i] = 1;
		x[i] = rand()%20;
		y[i] = i*2+5;
		w[i] = rand()%2;
	}

	set_color(3,0xa);
	cls();
	set_size(80,25);
	set_title("我的简单空战游戏！空格键发射炮弹，光标控制大炮方向！");
	hide_cursor();
	
	draw_up();
	while(1)
	{
		for(i = 0;i<N;i++)
		{
			gotoxy(x[i],y[i]);
			if(!w[i])
			{
				printf("<>-->");
			}
			else
			{
				printf(">>>>>");
			}
		}
		delay(DTIME);
		for(i=0;i<N;i++)
		{
			gotoxy(x[i],y[i]);
			printf("     ");
			x[i]++;
			if((x[i]>74)||(!on[i]))
			{
				x[i] = rand()%20;
				on[i] = 1;
				w[i] = rand()%2;
			}
		}
		gotoxy(2,24);
		printf("击中：%d",score);
		if(kbhit())
		{
			key = getkey();
//			gotoxy(1,1);
//			printf("%d",key);
			switch(key)
			{
				case KEY_LEFT:
					if(direction==UP)
					{
						direction = LEFT;
						draw(LEFT);
					}
					else if(direction ==RIGHT)
					{
						direction = UP;
						draw(UP);
					}
					break;
				case KEY_RIGHT:
					if(direction==UP)
					{
						direction = RIGHT;
						draw(RIGHT);
					}
					else if(direction ==LEFT)
					{
						direction = UP;
						draw(UP);
					}
					break;
				case KEY_DOWN:
					gotoxy(px-1,py-1);
					printf("      ");
					gotoxy(px,py);
					printf(" ");
					py++;
					if(py>=24)
					{
						py=24;
					}
					draw(direction);
					break;
				case KEY_UP:
					gotoxy(px-1,py-1);
					printf("      ");
					gotoxy(px,py);
					printf(" ");
					py--;
					if(py<=1)
					{
						py=1;
					}
					draw(direction);
					break;
				case 32:
					fire(direction);
			}
		}
	}
	getkey();
	return 0;
}
