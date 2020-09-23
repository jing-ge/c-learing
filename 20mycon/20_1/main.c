#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "conio.h"
#include "mycon.h"
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 char msg[] = "Hello,World";
        int delaytime = 1000;
        int len = strlen(msg);
        srand(time(NULL));

        set_title("有声有色动画版的HelloWorld程序");

        set_size(80,25);

        hide_cursor();

        cls();

        while(1)
        {
                gotoxy(40-len/2,11);
                for(int i=0;i<len;i++)
                {
                        set_color(0,rand()%15+1);
                        printf("%c",msg[i]);
                        play_sound("Boing.wav");
                        if(_kbhit())
                        {
                                exit(0);
                        }
                        delay(delaytime);
                }
                gotoxy(40-len/2,11);
                for(int i=0;i<len;i++)
                {
                        printf(" ");
                }
        }
        return 0;

	return 0;
}
