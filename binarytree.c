#include <stdio.h>
#include <stdlib.h>

int c=0;
typedef struct node
{
	int d;
	struct node* l,*r;
}node;

node *insert(node *head, node *new)
{
	node *t;
	t=head;
	if(t==NULL)
	{
		head=new;
	}
	else if(t->l==NULL)
	{
		t->l=new;
	}
	else if(t->r==NULL)
	{
		t->r=new;
	}
	else if(t->r->l==NULL || t->r->r==NULL)
	{
	    	insert(t->r,new);
	}
	else
	{
		insert(t->l,new);
	}
	return(head);
}

void search(node *head,int val)
{
	node *t;
	t=head;
	if(t==NULL)
	{
		return;
	}
	if(t->d==val)
	{
		printf("Value Found");
		c++;
		return;
	}
	else
	{
		search(t->l,val);
		search(t->r,val);
	}
	
}

void inor(node *head)
{
	node *t;
	t=head;
	if(t!=NULL)
	{
		inor(t->l);
		printf("%d ",t->d);
		inor(t->r);
	}
}

void pre(node *head)
{
	node *t;
	t=head;
	if(t!=NULL)
	{
		printf("%d ",t->d);
		pre(t->l);
		pre(t->r);
	}
}

void post(node *head)
{
	node *t;
	t=head;
	if(t!=NULL)
	{
		pre(t->l);
		pre(t->r);
		printf("%d ",t->d);
	}
}

void main()
{
	int ch;
	node *head=NULL;
	while(1==1)
	{
		printf("\n1.Insert \n2.Search\n3.Preorder\n4.Postorder\n5.Inorder\n6.Delete\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				int val;
				printf("Enter new Value: ");
				scanf("%d",&val);
				node *new;
				new=(node *)malloc(sizeof(node));
				new->d=val;
				new->l=NULL;
				new->r=NULL;

				head=insert(head,new);
				break;
			}
			case 2:
			{
				printf("Enter value to be searched: ");
				int val;
				c=0;
				scanf("%d",&val);
				if(head==NULL)
				{
					printf("Root node is null");
					break;
				}
				search(head,val);
				if(c==0)
				{
					printf("Value not found");	
				}
				break;
			}
			case 3:
			{
				pre(head);
				break;
			}
			case 4:
			{
				head=post(head);
				break;
			}
			case 5:
			{
				inor(head);
				break;
			}
			/*case 6:
			{
				head=del(head);
				break;
			}*/
		}
	}
}
