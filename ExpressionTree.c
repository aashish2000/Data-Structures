#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define size 30

typedef struct Node
{

  char data;
  struct Node* left;
  struct Node* right;

}node;


node* getnode(int data)
{

   node* temp=(node*)malloc(sizeof(node));
   temp->data=data;
   temp->left=NULL;
   temp->right=NULL;

}

int push(node* stack[],int* top,node* ele)
{
  if((*top)>=size-1)
       return 0;
  
  stack[++(*top)]=ele;

  return 1;
}

node* pop(node* stack[],int* top)
{
   node* ele;

   if((*top)==-1)
       return NULL;

   ele=stack[(*top)--];
   
   return ele;
}

node* exptree(node* stack[],int* top,char exp[])
{
   node *node1,*node2,*node3,*root;
   int i=0;

   while(exp[i]!='\0')
   {
       node3=getnode(exp[i]);      

       if(isalpha(exp[i]))
           push(stack,top,node3);
       else
       {
           node1=pop(stack,top);
           node2=pop(stack,top);
           node3->left=node2;
           node3->right=node1;
           push(stack,top,node3);
       }
       i++;
   }   
   
   root=pop(stack,top);

   return root;
}

void inod(node* root)
{
   if(root!=NULL)
   {
      inod(root->left);
      printf("%c ",root->data);
      inod(root->right);  
   }
}

void prod(node* root)
{
   if(root!=NULL)
   {
      printf("%c ",root->data);
      prod(root->left);
      prod(root->right);  
   }
}

void pood(node* root)
{
   if(root!=NULL)
   {
      pood(root->left);
      pood(root->right);
      printf("%c ",root->data);  
   }
}

void main()
{

   char exp[size];
   node* stack[size];
   int top=-1;
   node* root=NULL;

   printf("Postfix Expression: ");
   scanf("%s",exp);

   root=exptree(stack,&top,exp);

   printf("\nPreorder Form: ");
   prod(root);
   printf("\nInorder Form: ");
   inod(root);
   printf("\nPostorder Form: ");
   pood(root);   
   printf("\n");
}
