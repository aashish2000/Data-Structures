#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;

int height(node *T)
{
	int lh,rh;
	if(T==NULL)
	{
		return(0);
	}

	if(T->left==NULL)
	{
		lh=0;
	}
	else
	{
		lh=1+height(T->left);
	}

	if(T->right==NULL)
	{
		rh=0;
	}
	else
	{
		rh=1+height(T->right);
	}

	if(lh>rh)
		return(lh);
	return(rh);
}

int BF(node *T)
{
	int lh,rh;
	if(T==NULL)
	{
		return(0);
	}

	if(T->left==NULL)
	{
		lh=0;
	}
	else
	{
		lh=1+height(T->left);
	}

	if(T->right==NULL)
	{
		rh=0;
	}
	else
	{
		rh=1+height(T->right);
	}

	return(lh-rh);
}

node *ror(node *t)
{
	node *p;
	p=t->left;
	t->left=p->right;
	p->right=t;
	p->ht=height(p);
	t->ht=height(t);
	return(p);
}

node *rol(node *t)
{
	node *p;
	p=t->right;
	t->right=p->left;
	p->left=t;
	p->ht=height(p);
	t->ht=height(t);
	return(p);
}

node *LL(node *t)
{
	t=ror(t);
	return(t);
}

node *RR(node *t)
{
	t=rol(t);
	return(t);
}

node *LR(node *t)
{
	t->left=rol(t->left);
	t=ror(t);
	return(t);
}

node *RL(node *t)
{
	t->right=ror(t->right);
	t=rol(t);
	return(t);
}


node *insert(node *t,int x)
{
	if(t==NULL)
	{
		t=(node *)malloc(sizeof(node));
		t->left=NULL;
		t->right=NULL;
		t->data=x;
	}
	else
	{
		if(x>t->data)
		{
			t->right=insert(t->right,x);
			if(BF==-2)
			{
				if(x>t->right->data)
				{
					RR(t);
				}
				else
				{
					RL(t);
				}
			}
		}
		else if(x<t->data)
		{
			t->left=insert(t->left,x);
			if(BF==2)
			{
				if(x<t->left->data)
				{
					LL(t);
				}
				else
				{
					LR(t);
				}
			}
		}
	}

	t->ht=height(t);

	return(t);
}

void preorder(node *T)
{
    if(T!=NULL)
    {
        printf("%d ",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
 
void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d ",T->data);
        inorder(T->right);
    }
}



int main()
{
    node *root=NULL;
    int x,n,i,op;
    
    do
    {
        printf("\n1)Create:");
        printf("\n2)Insert:");
        printf("\n3)Delete:");
        printf("\n4)Print:");
        printf("\n5)Quit:");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&op);
        
        switch(op)
        {
            case 1: printf("\nEnter no. of elements:");
                    scanf("%d",&n);
                    printf("\nEnter tree data:");
                    root=NULL;
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&x);
                        root=insert(root,x);
                    }
                    break;
                
            case 2: printf("\nEnter a data:");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;
                    
            /*case 3: printf("\nEnter a data:");
                    scanf("%d",&x);
                    root=Delete(root,x);
                    break;*/
            
            case 4: printf("\nPreorder sequence:\n");
                    preorder(root);
                    printf("\n\nInorder sequence:\n");
                    inorder(root);
                    printf("\n");
                    break;            
        }
    }while(op!=5);
    
    return 0;
}







