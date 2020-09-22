#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int bmh;
	int score;
	struct node* next;
}Node;

void insertNode(Node *head,Node *s);
void output(Node *head,int m);
void destory(Node *head);

int main()
{
	Node *head,*p,*s,*prep;
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	int n,m;
	scanf("%d %d",&n,&m);
	m = m*1.5;
	for(int i=1;i<=n;i++)
	{
		s = (Node *)malloc(sizeof(Node));
		scanf("%d %d",&s->bmh,&s->score);
		insertNode(head,s);
	}
	output(head,m);
	destory(head);

	return 0;
}
void insertNode(Node *head,Node *s)
{
	Node *p = head->next;
	Node *prep = head;
	while(p &&( p->score>s->score||(p->score==s->score&&p->bmh<s->bmh)))
	{
		prep = p;
		p = p->next;
	}
	prep->next = s;
	s->next = p;
}
void output(Node *head,int m)
{
	int c = 0;
	Node *p = head->next;
	int ss;
	while(p)
	{
		c++;
		if(c==m)
		{
			ss = p->score;
			Node * s = p;
			p = p->next;
			while(p->score==ss)
			{
				p = p->next;c++;
			}
			break;
		}
		p = p->next;
	}
	printf("%d %d\n",ss,c);
	p = head->next;
	while(p && p->score>=ss)
	{
		printf("%d %d\n",p->bmh,p->score);
		p = p->next;
	}
}
void destory(Node *head)
{
	Node *p = head,*q;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}
