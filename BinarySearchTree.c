#include<stdio.h> 
#include<stdlib.h> 

typedef struct TreeNode { 

	int item; 
	struct TreeNode *left; 
	struct TreeNode *right; 

	} node; 

node *newnode()
	{
	node *ptr = (node*)malloc(sizeof(node)); 
	return ptr; 
	}

node *insert (node *root, int data) 
	{
	node *curr; 

	curr = newnode(); 
	curr->item = data; 
	curr->left = NULL; 
	curr->right = NULL; 	

	if (root==NULL) 
		root = curr; 
		
	else
		{
		if (data < root->item) 
			root->left = insert (root->left, data); 

		else 
			root->right = insert (root->right, data);  
		}
	return root;
	}

void Inorder_Print (node *root) 
	{
	if (root==NULL) 
		return; 
		
	else 
		{
		Inorder_Print (root->left); 
		printf("%d ", root->item);
 		Inorder_Print (root->right); 
		}
	} 

void Preorder_Print (node *root) 
	{
	if (root==NULL) 
		return; 
		
	else 
		{
		printf("%d ", root->item);
		Preorder_Print (root->left); 
 	 	Preorder_Print (root->right); 
		}
	} 

void Postorder_Print (node *root) 
	{
	if (root==NULL)
		return; 
		

	else 
		{
		Postorder_Print (root->left); 
 	 	Postorder_Print (root->right); 
		printf("%d ", root->item);		
		}
  	}

node *search (node *root, int data) 
	{
	node *ptr = root; 

	while (ptr!=NULL) 
		{ 
		if (ptr->item == data)
			break;
			
		else if (ptr->item < data)
			ptr = ptr->right;

		else 
			ptr = ptr->left;
		}

	return ptr;
	} 

node *find_max (node *root)
	{
	if (root->right == NULL)
		return root; 

	else 
		root->right = find_max (root->right); 
	}

node *find_min (node *root)
	{
	if (root->left == NULL)
		return root; 

	else 
		root->left = find_max (root->left); 
	}

node* find_parent (node *root, int data) 
	{
	node *parent;
	node *current; 

	parent = NULL;
	current = root; 

	while (current->item != data) 
		{
		parent = current; 
		
		if (current->item > data) 
			current = current->left;

		else 
			current = current->right; 
		}			

	return parent; 
	}

node* Delete (node *root, int data) 
	{
	node *position, *substitute, *parent; 
	position = search (root, data); 	
	
	if (position == NULL) //Search item not present   
		printf("\nElement not present!"); 

	else if ((root->left == NULL) && (root->right==NULL)) // Only root node 
		root = NULL; 

	else 
		{
		if ((position->left == NULL) && (position->right == NULL)) // Leaf node  
			{
			parent = find_parent (root, data);

			if (parent->item >= position->item) 
				parent->left = NULL; 

			else 
				parent->right = NULL;  
			}

		else 
			{
			if (position->left != NULL)
				{
				substitute = find_max (position->left);
				position->item = substitute->item; 
				position->left = Delete (position->left, substitute->item); 	 
				}

			else 
				{
				substitute = find_min (position->right); 
				position->item = substitute->item; 
				position->right = Delete (position->right, substitute->item); 	 
				}
			}			
		} 

	return root;
	} 

void main () 
	{
	node *root;
	root = NULL; 
	int choice, item;  

	do 
		{
		printf("\n1.Insert\n2.Pre-order form\n3.In-order form\n4.Post-order form\n5.Delete\n6.Exit: "); 
		scanf("%d", &choice);

		switch (choice)
			{
			case 1: 
				printf("\nItem to be inserted: "); 
				scanf("%d", &item); 
				root = insert (root, item); 
				break;

			case 2: 
				printf("\nPreorder: "); 
				Preorder_Print (root); 
				break; 
			
			case 3: 
				printf("\nInorder: "); 
				Inorder_Print (root); 
				break; 

			case 4: 
				printf("\nPostorder: "); 
				Postorder_Print (root);
				break;

			case 5:
				printf("Item to be deleted: "); 
				scanf("%d", &item); 
				root = Delete (root, item);  
				break;

			case 6: 
				break;
			
			default: 
				printf("\nEnter proper choice!");  
  			}

		} while (choice!=6); 
 
	printf("\n"); 
}





						














