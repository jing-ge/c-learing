#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char sno[20];
	int month;
	int day;
	struct node *next;
} Node;

void insert(Node *head,char*sno,int month,int day)
{
	Node *p = head->next;
	Node *prep = head;
	Node *s = (Node *)malloc(sizeof(Node));
	strcpy(s->sno,sno);
	s->month = month;
	s->day = day;
	while(p!=NULL)
	{
		if(p->month<s->month||p->month==s->month&&p->day<s->day)
		{
			prep = p;
			p = p->next;
		}
		else break;
	}
	prep->next = s;
	s->next = p;
}

void display(Node *head)
{
	printf("-----------\n");
	Node *p = head->next;
	while(p!=NULL)
	{
		Node *q = p->next;
		if(q && q->month == p->month && q->day==p->day)
		{
			printf("%d %d %s %s",p->month,p->day,p->sno,q->sno);
			q = q->next;
			while(q && q->month==p->month&&q->day==p->day)
			{
				printf("  %s ",q->sno);
				q = q->next;
			}
			printf("\n");
			p = q;
		}else{
			p = p->next;
		}
	}
}

void print(Node *head)
{
	Node *p = head->next;
	while(p!=NULL)
	{
		printf("%s %d %d\n",p->sno,p->month,p->day);
		p = p->next;
	}
}
int main()
{
	Node *head;
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	
	int n;
	char sno[20];
	int month;
	int day;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s %d %d",sno,&month,&day);
		insert(head,sno,month,day);
	}
	//print(head);
	display(head);
}
