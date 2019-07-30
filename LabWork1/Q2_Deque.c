# include<stdio.h>
# include <stdlib.h>

int MAX=5;
int* deque_arr ;
int* deque_arr1;
int left = -1;
int right = -1;
int size;
int k = 0;

/*Begin of insert_right*/
void insert_right()
{
	int added_item;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	//printf("Queue Overflow\n");
		MAX = MAX*2;
		deque_arr1 = (int*)malloc(MAX*sizeof(int));
		int p = 0;
		do
		{
		   deque_arr1[p] = deque_arr[left];
		   p++;  
		   left = (left+1)%(MAX/2);
		}while(left!=((right+1)%(MAX/2)));
		left = 0;  right = (MAX/2)-1;
		deque_arr = realloc(deque_arr,MAX*sizeof(int));
		for(int i=0;i<MAX;i++)
		{
			deque_arr[i] = deque_arr1[i];
		}
	}
	if (left == -1)  /* if queue is initially empty */
	{	left = 0;
		right = 0;
	}
	else
	{
		if(right == MAX-1)  /*right is at last position of queue */
			right = 0;
		else
			right = right+1;
	}
	deque_arr[right] = added_item ;
	free(deque_arr1);
}
/*End of insert_right*/

/*Begin of insert_left*/
void insert_left()
{	int added_item;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	//printf("Queue Overflow\n");
		MAX = MAX*2;
		deque_arr1 = (int*)malloc(MAX*sizeof(int));
		int p = 0;
		do
		{
		   deque_arr1[p] = deque_arr[left];
		   p++;  
		   left = (left+1)%(MAX/2);
		}while(left!=((right+1)%(MAX/2)));
		left = 0;  right = (MAX/2)-1;
		deque_arr = realloc(deque_arr,MAX*sizeof(int));
		for(int i=0;i<MAX;i++)
		{
			deque_arr[i] = deque_arr1[i];
		}	
	}
	if (left == -1)/*If queue is initially empty*/
	{	
		left = 0;
		right = 0;	
	}
	else
	{
		if(left== 0)
			left=MAX-1;
		else
			left=left-1;
	}
	deque_arr[left] = added_item ;
	free(deque_arr1);
}
/*End of insert_left*/

int sizes();

/*Begin of delete_left*/
void delete_left()
{	
	if (left == -1)
	{	
		printf("Queue Underflow\n");
		return ;	
	}
	printf("Element deleted from queue is : %d\n",deque_arr[left]);
	if(left == right) /*Queue has only one element */
	{	
		left = -1;
		right=-1;	 
	}
	else
	{
		if(left == MAX-1)
			left = 0;
		else
			left = left+1;
	}
	if(sizes()<=(MAX/2))
	{
		if(MAX%2!=0)
			k=1;
		MAX = MAX/2;
		deque_arr1 = (int*)malloc(MAX*sizeof(int));
		int p = 0;
		do
		{
			deque_arr1[p] = deque_arr[left];
			p++;  
			if(k==1)
				left = (left+1)%((MAX*2)+1);
			else
				left = (left+1)%(MAX*2);
		}while(left!=((right+1)%MAX));
		left = 0;  right = MAX-1;
		deque_arr = realloc(deque_arr,MAX*sizeof(int));
		for(int i=0;i<MAX;i++)
		{
			deque_arr[i] = deque_arr1[i];
		}	
	}
	free(deque_arr1);
}
/*End of delete_left*/

/*Begin of delete_right*/
void delete_right()
{
	if (left == -1)
	{
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted from queue is : %d\n",deque_arr[right]);
	if(left == right) /*queue has only one element*/
	{
		left = -1;
		right=-1;	
	}
	else
	{
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;
	}
	if(sizes()<=(MAX/2))
	{
		if(MAX%2!=0)
			k=1;
		MAX = MAX/2;
		deque_arr1 = (int*)malloc(MAX*sizeof(int));
		int p = 0;
		do
		{
			deque_arr1[p] = deque_arr[left];
			p++;  
			if(k==1)
				left = (left+1)%((MAX*2)+1);
			else
				left = (left+1)%(MAX*2);
		}while(left!=((right+1)%MAX));
		left = 0;  right = MAX-1;
		deque_arr = realloc(deque_arr,MAX*sizeof(int));
		for(int i=0;i<MAX;i++)
		{
			deque_arr[i] = deque_arr1[i];
		}	
	}
	free(deque_arr1);
}
/*End of delete_right*/

/*Begin of sizes*/
int sizes()
{
if(left==-1&&right==-1)
   size = 0;
if(left<=right)
   size = right-left+1;
if(left>right)
   size = right-left+1+MAX;
return size;
}
/*End of sizes*/

/*Begin of display_que*/
void display_queue(int* x)
{	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	
		printf("Queue is empty\n");
		return;	
	}
	printf("Queue elements :\n");
	if( front_pos <= rear_pos )
	{	
		while(front_pos <= rear_pos)
		{	printf("%d ",x[front_pos]);
			front_pos++;	
		}
	}
	else
	{	
		while(front_pos <= MAX-1)
		{	
			printf("%d ",x[front_pos]);
			front_pos++;	
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	
			printf("%d ",x[front_pos]);
			front_pos++;
		}
	}
	printf("\n");
}
/*End of display_queue*/


/*Begin of declaration*/
void declaration()
{
	deque_arr = (int*)malloc(MAX*sizeof(int));
}
/*End of declaration*/

void declaration();

/*Begin of main*/
void main()
{

	declaration();

	int choice;
	do
	{
		printf("1.Insert at right\n");
		printf("2.Insert at left\n");
		printf("3.Delete from left\n");
		printf("4.Delete from right\n");
		printf("5.Display\n");
		printf("6.Print Capacity\n");
		printf("7.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			insert_left();
			break;
		 case 3:
			delete_left();
			break;
		 case 4:
			delete_right();
			break;
		 case 5:
			display_queue(deque_arr);
			break;
		 case 6:
			printf("%d\n",MAX);
		 case 7:
			break;
		 default:
			printf("Invalid choice\n");
		}
	}while(choice!=7);
	
}
/*End of main*/

