#ifndef STDLIB_H
	#include <stdlib.h>
#endif

#ifndef STDIO_H
	#include <stdio.h>
#endif
	
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node* createnode(int ele)
{
	node* ptr = (node*)malloc(sizeof(node));
	ptr->left=ptr->right=NULL;
	ptr->data=ele;
	return ptr;
}
node* insert(node* top,int ele)
{
	if(top == NULL) return createnode(ele);
	
	if(ele < top->data)
		top->left = insert(top->left,ele);
	else if(ele > top->data)
		top->right = insert(top->right,ele);	
	return top;	
}
node* minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
node* deletegiven(node* top,int ele)
{
	node* ptr;
	if(top == NULL)
	{
		printf("Element wasn't found!\n");
	}	
	if(ele == top->data)
	{
		if(top->left==NULL)
		{
			ptr = top->right;
			free(top);
			return ptr;
		}
		else if(top->right == NULL)
		{
			ptr = top->left;
			free(top);
			return ptr;
		}
		ptr = minValueNode(top->right);
		top->data = ptr->data;
		top->right = deletegiven(top->right,ptr->data);
		printf("%d was found and deleted\n",ele);
	}
	else if(ele<top->data)
		top->left = deletegiven(top->left,ele);
		
	else
		top->right = deletegiven(top->right,ele);
	return top;	
}
void inorder(node* parent)
{
	if(parent!=NULL)
	{
		inorder(parent->left);
		printf("%d ",parent->data);
		inorder(parent->right);
	}	
}
void printlevel(node* root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf("%d ",root->data);
	else if(level>1)
	{
		printlevel(root->left,level-1);
		printlevel(root->right,level-1);
	}			
}
int height(node* node)
{
	if(node==NULL)
		return 0;
	else
	{
		int lh = height(node->left);
		int rh = height(node->right);
		if(lh>rh)
			return lh+1;
		else
			return rh+1;				
	}	
}
void depthfirst(node* root)
{
	int h = height(root);
	int i;
	for(i=1;i<=h;i++)
		printlevel(root,i);
		
}
