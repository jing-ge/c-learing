#include <stdio.h>
#include <stdlib.h>    //malloc, free, rand,srand
#include <time.h>      //time

int main()
{
	int len;
	char *buffer = NULL;
	srand(time(0));   //设置随机数种子
	printf("你想要多长的字符串？\n");
	scanf("%d",&len);

	buffer = (char*)malloc(len+1);

	if (buffer == NULL) exit(1);
	
	for(int i=1;i<len;i++)
		buffer[i] = rand()%26 +'a';
	buffer[len] = '\0';

	printf("随机字符串: %s\n",buffer);
	free(buffer);
	return 0;
}
