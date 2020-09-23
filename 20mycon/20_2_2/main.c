#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <mycon.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int x,y;
int xdir, ydir;
int key;
int bx;
int in;
int count;

void draw_one_block(int x,int y,int color)
{
	gotoxy(x,y);
	set_color(0,color);
	printf("█"); 
}

void end_game(void)
{
	gotoxy(33,12);
	printf("游戏结束！您共计得%d分！",count);
	getkey();
	exit(0); 
}

void draw_all_blocks(void)
{
	int x,y;
	y = 0;
	for(x=5;x<=75;x+=2)
	{
		draw_one_block(x,y,x%16);
	}
}

void init_game(void)
{
	set_size(80,25);
	set_color(0,0xb);
	set_title("弹小球游戏！光标左右键控制弹棒的移动！");
	hide_cursor();
	cls();
	
	draw_all_blocks();
	x=0;
	y=0;
	xdir=1;
	ydir=1;
	in = 0;
	bx = 40;
	count =0; 
}

void draw_bar()
{
	gotoxy(0,24);
	printf("                                           ");
	gotoxy(bx,24);
	printf("========");
}

void show_score()
{
	gotoxy(0,0);
	printf("得分：%d",count);
}

void move_bar()
{
	key = getkey();
	switch(key)
	{
		case 75:
			bx = (bx>=4)?bx-4:0;
			break;
		case 77:
			bx = (bx>=68)?71:bx+4;
	}
	draw_bar();
}

void draw_ball()
{
	gotoxy(x,y);
	printf("0");
	delay(100);
	gotoxy(x,y);
	printf(" ");
}

void hit_ball()
{
	in = 0;
	play_sound("Boing.wav");
	count++;
	gotoxy(x,y);
	printf("=");
}

void move_ball()
{
	if(xdir)
	{
		if(x>=79)
		{
			xdir = 0;
			ydir?y--:y++;
		}
		else
		{
			x++;
		}
		
	}
	else
	{
		if(x<=0)
		{
			if(count==39)
			{
				gotoxy(33,12);
				printf("恭喜您通关了！");
				getkey();
				exit(0);
			}
			xdir = 1;
			ydir?y--:y++;
		}
		else{
			x--;
		}
	}
	if(ydir)
	{
		if(y>=24)
		{
			if((x<bx)||(x>bx+8))
			{
				end_game();
			}
			else
			{
				in = 1;
			}
			ydir = 0;
			xdir?x--:x++;
		}
		else
		{
			y++;
		}
	}
	else
	{
		if(y<=0)
		{
			ydir = 1;
			xdir?x--:x++;
		}
		else
		{
			y--;
		}
	}
	
	draw_ball();
}

int main(int argc, char *argv[]) {

	init_game();
	draw_bar();
	while(1)
	{
		show_score();
		if(kbhit())
		{
			move_bar();
		}
		if(in)
		{
			hit_ball();
		}
		move_ball();
	}
	return 0;
	return 0;

}
