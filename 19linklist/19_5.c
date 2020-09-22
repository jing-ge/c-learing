#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node* createList(int n);
int monkeyKing(int n,int m);

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int monkeyK = monkeyKing(n,m);
	printf("猴王的编号为：%d\n",monkeyK);
	return 0;

}

Node *createList(int n)
{
	Node*L = NULL,*s,*tail,*pre;
	for(int i=1;i<=n;i++)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = i;
		if(i==1)L = s;
		else tail->next = s;
		tail = s;
	}
	tail->next = L;
	return tail;
}

int monkeyKing(int n,int m)
{
	Node *tail = createList(n);
	int count  = 1;
	Node *s = tail->next;
	Node *pre = tail;
	while(s->next!=s)
	{
		while(count<m)
		{
			count ++;
			pre = s;
			s = s->next;
		}
		pre->next = s->next;
		free(s);
		s = pre->next;
		count = 1;
	}
	return s->data;

}
