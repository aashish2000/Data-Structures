#include <stdio.h>
#include <stdlib.h>

int btree[50],i=0, elc=0;

void insert(int n)
{
	i=0;
	if(btree[0]==NULL)
	{
		btree[0]=n;
		elc++;
	}
	for(i=0;i<elc;i++)
	{
		if(btree[2*i+1]==NULL)
		{
			btree[2*i+1]=n;
			elc++;
			break;
		}
		else if(btree[2*i+2]==NULL)
		{
			btree[2*i+2]=n;
			elc++;
			break;
		}
	}
}

void inor(int i)
{
	if(btree[i]!=NULL)
	{
		inor(2*i+1);
		printf("%d ",btree[i]);
		inor(2*i+2);
	}
}
void main()
{
	int ch;
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
				insert(val);
				break;
			}
			/*case 2:
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
			}*/
			case 5:
			{
				i=0;
				inor(i);
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