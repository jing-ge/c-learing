#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;

int main(void)
{
	Node *head,*p,*q;
	p = (Node*)malloc(sizeof(Node));
	p->data = 20;
	head = p;
	for(int i=1;i<=3;i++)
	{
		q = (Node*)malloc(sizeof(Node));
		q->data = (i+2)*10;
		p->next = q;
		p = q;
	}
	p->next = NULL;

	printf("链表头指针的值为:%#X\n",head);
	printf("链表节点的地址：");
	p = head;
	while(p!=NULL)
	{
		printf("%#X     ",p);
		p = p->next;
	}
	printf("\n");
	printf("链表节点的内容为：");
	for(Node *p = head;p!=NULL;p = p->next)
	{
		printf("%d %#X ",p->data,p->next);
	}	
	return 0;
}
