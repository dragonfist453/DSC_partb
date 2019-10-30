#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
void stack();
void queue();
void graph_stack(node*);
void graph_queue(node*);
void node_draw(int,int,int);
void init();
int main()
{
	int ch,key=1;
	while(key)
	{	
		key=0;
		printf("Which of these would you like to see a graphical implementation of?\n1. Stack\n2. Queue\n3. I'd rather draw it myself\n");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1: stack();
					break;
			case 2: queue();
					break;
			case 3: printf("Alright then! Bye bye!!\n");
					exit(0);
					break;
			default: printf("Wrong choice entered!\n");
					key=1;
					break;										
		}
	}	
	return 0;
}
void stack()
{
	int ele,ch;	
	node* top;
	while(1)
	{
		printf("What operation would you want to perform on a stack?\n1. Push\n2. Pop\n3. Display graphically\n4. Get out of this mess\n5. Display stack normally\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element you'd like to insert : ");
					scanf("%d",&ele);
					top = insertbeg(top,ele);
					break;
			case 2: printf("%d was popped!\n",top->data);
					top = deletebeg(top);
					break;
			case 3: while(1)
					{
						init();
						graph_stack(top);
						if(getch()=='q')
						{
							cleardevice();
							closegraph();
							break;
						}
					}
					closegraph();
					break;	
			case 4:	printf("Don't we all? :\")");
					exit(0);	
					break;
			case 5: printf("Entered switch");
					fflush(stdout);
					display(top);
					break;	
			default: printf("Wrong choice entered!\n");
					break;							
		}
	}	
}
void queue()
{
	int ele,ch;	
	node* front;
	while(1)
	{
		printf("What operation would you want to perform on a queue?\n1. Enqueue\n2. Dequeue\n3. Display graphically\n4. Get out of this mess\n5. Display queue normally\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element you'd like to insert : ");
					scanf("%d",&ele);
					front = insertbeg(front,ele);
					break;		
			case 2: printf("%d was dequeued!\n",front->data);
					front = deleteend(front);
					break;
			case 3: while(1)
					{
						init();
						graph_queue(front);
						if(getch()=='q')
						{
							cleardevice();
							closegraph();
							break;
						}
					}
					closegraph();
					break;	
			case 4:	printf("Don't we all? :\")");
					exit(0);	
			case 5: display(front);
					break;		
			default: printf("Wrong choice entered!\n");
					break;							
		}
	}	
}
void init()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	printf("Press q to go back\n");
}
void node_draw(int x,int y,int i)
{
	char num[5]="";
	sprintf(num,"%d",i);
	setcolor(WHITE);
	rectangle(x-50,y,x+50,y+30);
	outtextxy(x-2,y+5,num);
}	
void graph_stack(node* top)
{
	int x=getmaxx()/2;
	int y=getmaxy()/10;
	node* ptr=top;
	while(ptr!=NULL)
	{
		node_draw(x,y,ptr->data);
		y=y+35;
		ptr=ptr->next;
	}
	line(x-100,y,x+100,y);
}
void graph_queue(node* front)
{
	int x=getmaxx()/20;
	int y=getmaxy()/2;
	outtextxy(x,y,"----->");
	node* ptr=front;
	while(ptr!=NULL)
	{
		node_draw(x,y,ptr->data);
		x=x+55;
		ptr=ptr->next;
	}
	line(x,y-60,x,y+60);
}
























