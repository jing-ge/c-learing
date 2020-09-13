#include <stdio.h>

int main(void)
{
	FILE *fp;
	char inputfile[20] = "testfile.txt";
	/*
	 *
	 *char inputfile[20];
	 *scanf("%s",inputfile);
	 *
	 *
	 */
	fp = fopen(inputfile,"r");
	if(fp == NULL)
		printf("%s open failed!",inputfile);
	else
		printf("%s open successeful!",inputfile);
	return 0;
}
