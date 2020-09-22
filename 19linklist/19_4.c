#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char sub[100];
	int count;
	struct node* next;
}Node;

void insert(Node*head,char sub[]);
void output(Node *head);

int main()
{
	char s[100],sub[100];
	scanf("%s",s);
	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	int len = strlen(s);
	for(int i=1;i<len;i++)
	{
		for(int j=0;j<=len-i;j++)
		{
			memset(sub,0,100);
			strncpy(sub,s+j,i);
			insert(head,sub);
		}
	}
	output(head);
	return 0;
}
void insert(Node*head,char sub[])
{
	Node *p = head->next;
	Node *prep = head;
	while(p!=NULL)
	{
		if(strcmp(sub,p->sub)>0)
		{
			prep = p;
			p = p->next;
		}else break;
	}
	if(p && strcmp(sub,p->sub)==0)p->count++;
	else
	{
		Node *s = (Node*)malloc(sizeof(Node));
		strcpy(s->sub,sub);
		s->count = 1;
		s->next = p;
		prep->next =s;
	}
}
void output(Node *head)
{
	Node *p = head->next;
	while(p!=NULL)
	{
		if(p->count>=2)
		printf("%s %d\n",p->sub,p->count);
		p = p->next;
	}
}
