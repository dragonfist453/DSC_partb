#include "btree.h"
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
int m=1;
int x;
int y;
void init()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	m=1;
	x = getmaxx()/2;
	y = getmaxy()/8;
	printf("Press q to go back\n");
}
void drawnode(int i,int x,int y)
{
	char num[5];
	sprintf(num,"%d",i);
	setcolor(WHITE);
	circle(x,y,20);
	//settextstyle(2,0,2);
	outtextxy(x,y,num);
}
void drawline(node* node,int x, int y)
{
	if(node->right!=NULL)
		line(x+18,y+18,x+128/m,y+100/m);
	if(node->left!=NULL)
		line(x-18,y+18,x-128/m,y+100/m);		
}
void drawlevel(node* root, int level)
{
	if(root==NULL)
		return;
	if(level==1)
	{
		drawnode(root->data,x,y);
		drawline(root,x,y);
	}
	else if(level>1)
	{
		x=x-2*m*25-(128/m);y=y+25*m+100/m;
		drawlevel(root->left,level-1);
		x=x+4*m*25+(256/m);
		drawlevel(root->right,level-1);
	}			
}
void drawtree(node* root)
{
	int h = height(root);
	int i;
	for(i=1;i<=h;i++)
	{
		drawlevel(root,i);
		m*=2;
	}		
}
int main()
{
	//Data types and all
	int i;
	node* top;
	node* ptr;
	char ch='y';
	int opt;
	printf("Enter first node data : ");
	scanf("%d",&i);
	top = createnode(i);
	do
	{
		printf("1.Insert element into BST\n2.Delete node with given element\n3.Inorder traversal of btree\n4.Print graphical tree\n5.Exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: printf("Enter element to insert : ");
					scanf("%d",&i);
					ptr = insert(top,i);
					break;
			case 2: printf("Enter element to delete : ");
					scanf("%d",&i);
					deletegiven(top,i);	
					break;	
			case 3: inorder(top);
					break;
			case 4: while(1)
					{
						init();
						drawtree(top);
						if(getch()=='q')
						{
							cleardevice();
							closegraph();
							break;
						}	
					}
					closegraph();
					break;
			case 5: return 0;
		}
	//printf("Keep going? (Y/N)\n");
	//scanf(" %c",&ch);
	}while(1);
	//while(ch=='y'||ch=='Y');	
	return 0;
}
