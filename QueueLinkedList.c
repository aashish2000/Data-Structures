#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}node;

node *f=NULL,*r=NULL;

void enq(int n)
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->val=n;
	new->next=NULL;
	if(r==NULL)
	{
		r=new;
		f=new;
	}
	else
	{
		r->next=new;
		r=r->next;
	}
}

void deq()
{
	if(f!=r || f!=NULL)
	{
		node *p;
		p=f;
		f=f->next;
		printf("%d\n",p->val);
		free(p);
	}
	else
	{
		printf("Queue is Empty\n");
	}
}
void main()
{
	enq(2);
	enq(4);
	enq(6);


	deq();
	deq();
	deq();
}