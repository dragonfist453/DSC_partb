#ifndef STDLIB_H
	#include <stdlib.h>
#endif

#ifndef STDIO_H
	#include <stdio.h>
#endif
		
struct NODE{
	int data;
	struct NODE* next;
};
typedef struct NODE node;
node* createnode(int ele)
{
	node* ptr= (node*)malloc(sizeof(node));
	ptr->data=ele;
	ptr->next=NULL;
	return ptr;
}	

node* insertbeg(node* start,int ele)
{
	node* ptr = createnode(ele);
	if(start==NULL)
		start=ptr;
	else
	{
		ptr->next=start;
		start=ptr;
	}	
	return start;
}

node* insertend(node* rear, int ele) //useless for my app
{
	node* ptr = createnode(ele);
	if(rear==NULL)
		rear=ptr;
	else
	{
		rear->next=ptr;
	}	
	return rear;
}

node* deletebeg(node* start)
{
	if(start->next==NULL)
		return NULL;
	else if(start==NULL)
		return NULL;	
	else
	{	
		node* temp = start;
		start = start->next;
		free(temp);
		return start;
	}	
}

node* deleteend(node* start)
{
	if(start->next==NULL)
		return NULL;
	else if(start==NULL)
		return NULL;	
	else
	{	
		node* ptr=start;
		node* temp;
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;
		}	
		temp=ptr->next;
		ptr->next=NULL;
		free(temp);
		return start;
	}	
}
void display(node* start)
{
	node* ptr=start;
	//printf("%d : \n",ptr->data);
	//fflush(stdout);
	if(ptr==NULL)
	{
		printf("Underflow!\n");
	}	
	while(ptr->next!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);	
}








