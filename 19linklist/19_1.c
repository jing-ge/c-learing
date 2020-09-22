#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

int count(Node* head,int m);
void destory(Node* head);

int main()
{
	int n,m,x;
	Node* head = NULL,*s,*tail;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s = (Node*)malloc(sizeof(Node));
		s->data = x;
		if(i==1) head = s;
		else tail->next = s;
		tail = s;
	}
	tail->next = NULL;
	scanf("%d",&m);
	printf("%d\n",count(head,m));
	destory(head);
	head = NULL;
	return 0;
}

int count(Node* head,int m)
{
	int c = 0;
	Node *p = head;
	while(p)
	{
		if(p->data==m)c++;
		p = p->next;
	}
	return c;
}
void destory(Node* head)
{
	Node *p = head, *q;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}
