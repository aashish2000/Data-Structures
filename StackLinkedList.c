#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}node;

node *top=NULL;

node *push(int n,node *head)
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->val=n;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		top=head;
	}
	else
	{
		top->next=new;
		top=top->next;
	}
	return(head);
}

node *pop(node *head)
{
	if(head==NULL)
	{
		printf("Stack is Empty\n");
		return(head);
	}
	if(head!=NULL)
	{
		node *p;
		p=top;

		node *t;
		t=head;
		if(head==top)
		{
			head==NULL;
			printf("%d\n", p->val);
			top=NULL;
			return(head);
		}
		while(t->next!=p)
		{
			t=t->next;
		}
		top=t;
		printf("%d\n",p->val);
		free(p);
	}
	return(head);
}

void display(node *head)
{
	node *t;
	t=head;
	while(t!=NULL)
	{
		printf("%d ",t->val);
		t=t->next;
	}
}
void main()
{
	node *head=NULL;
	head=push(2,head);
	head=push(4,head);
	head=push(6,head);

	display(head);

	printf("\n");

	head=pop(head);
	head=pop(head);
	head=pop(head);
}