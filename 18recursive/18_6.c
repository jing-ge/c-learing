#include <stdio.h>
#include <string.h>

char s1[105],s2[105];

int find(int pos);

int main()
{
	while(scanf("%s",s1)!=EOF)
	{
		printf("%s\n",s1);
		int len = strlen(s1);
		memset(s2,' ',sizeof(s2));
		for(int i=0;i<len;i++)
		{
			if(s1[i]=='(')s2[i] = '$';
			else if(s1[i]==')')
			{
				int n = find(i-1);
				if(n==-1)s2[i] = '?';
				else s2[n] = ' ';
			}
		}
		s2[len] = '\0';
		printf("%s\n",s2);
	}
	return 0;
}

int find(int pos)
{
	if(pos == -1)return -1;
	else if(s2[pos]=='$')return pos;
	else return find(pos-1);
}
