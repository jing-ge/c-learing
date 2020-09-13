#include <stdio.h>

void f(const int * ptr);
int main()
{
	int y;
	f(&y);
	return 0;
}

void f(const int * ptr)
{
	*ptr = 100;//编译会发生错误
}
