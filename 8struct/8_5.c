#include <stdio.h>
#include <string.h>
union Data
{
	int i;
	double x;
	char str[16];
};
int main()
{
	union Data var;
	printf("%d\n",sizeof(var));

	var.i = 5;
	var.x = 3.14;
	for(int i=sizeof(double)-1;i>=0;i--)
		printf("%02X  ",(unsigned char)var.str[i]);
	printf("\n");
	printf("%d\n",var.i);
	strcpy(var.str,"hello");
	for(int i=15;i>=0;i--)
		printf("%02X  ",(unsigned char)var.str[i]);
	printf("\n");

	return 0;
}
