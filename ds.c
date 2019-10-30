#include "list.h"
#include <stdlib.h>
#include <stdio.h>
int main()
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
			case 4:	printf("Don't we all? :\")");
					exit(0);	
					break;
			case 5: printf("Entered switch\n");
					fflush(stdout);
					display(top);
					break;	
			default: printf("Wrong choice entered!\n");
					break;							
		}
	}
	return 0;
}			
		
