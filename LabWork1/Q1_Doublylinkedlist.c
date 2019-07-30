#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int rollNumber;
  struct node *next;
  struct node *prev;
  char name[150];
  char date[20];
  char address[250];
  int mobilenumber;
  
};

struct queueNode
{
	int rollNo;
	struct queueNode *next;
};

char *record[13][4];
struct queueNode *front=NULL;
struct queueNode *rear=NULL;
struct node *head=NULL;  
int rowCount=0;

int deleteQueue();

void insertion(char str[],char DOB[],char address[],int number)
{
  
	int rollNumberFromQueue;
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL)
    	{
    		printf("Memory not available\n\n" );
    	}
    	else
	{
		if(head==NULL)
		{ 
		  if(front==NULL)
		  {		
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
			ptr->rollNumber=101;
			printf("First node inserted with roll no:%d\n\n",ptr->rollNumber);
		  }
		  else
		  {
			rollNumberFromQueue=deleteQueue();
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
			ptr->rollNumber=rollNumberFromQueue;
   			printf("First node inserted with roll no:%d\n\n",ptr->rollNumber);
	          }
	        }
	 	else
		{
		   rollNumberFromQueue=deleteQueue();
		   temp=head;
                   if(rollNumberFromQueue==0)
           	   {
               		while(temp->next!=head)
           	   	{
           	   		temp=temp->next;
           		}
			   temp->next=ptr;
			   ptr->prev=temp;
			   ptr->next=head;
			   ptr->rollNumber=(temp->rollNumber+1);
			   head->prev=ptr;
			   printf("Node inserted with roll no:%d\n\n",ptr->rollNumber);
		    }
           	    else
           	    {
           		while(!((temp->rollNumber<rollNumberFromQueue)&&(temp->next->rollNumber>rollNumberFromQueue)))
           	        {
           			temp=temp->next;
           			if(temp->next==head)
           			{
           			   struct node *ptr1=temp->next;
				     ptr1->prev=ptr;
				     temp->next=ptr;
				     ptr->prev=temp;
				     ptr->next=ptr1;
				     ptr->rollNumber=rollNumberFromQueue;
				     strcpy(ptr->name,str);
				     strcpy(ptr->date,DOB);
				     strcpy(ptr->address,address);
				     ptr->mobilenumber=number;
				     break;
			      	}
           	
           		}
			struct node *ptr2=temp->next;
			ptr2->prev=ptr;
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=ptr2;
	   	        ptr->rollNumber=rollNumberFromQueue;
			printf("Node inserted with roll no:%d\n\n",ptr->rollNumber);
		    }      
   		}

	        strcpy(ptr->name,str);
	        strcpy(ptr->date,DOB);
	        strcpy(ptr->address,address);
	        ptr->mobilenumber=number;
  	   }	
}

void insertQueue(int x)
{
	struct queueNode *temp;
	temp=(struct queueNode*)malloc(sizeof(struct queueNode));
	if(temp==NULL)
	{
		printf("Memory not available\n");
	}
  	else if(front==NULL)
  	{
	     	temp->rollNo=x;
	     	temp->next=NULL;
	     	front=temp;
	     	rear=temp;
        }
	  else 
	  {
	     temp->rollNo=x;
	     rear->next=temp;
	     rear=temp;
	     rear->next=NULL;
	  }

}

void deletion(int id)
{
	struct node *temp,*ptr;
        if(id<101||id>113)
  	{
    		printf("No record with given roll number exists\n\n");
    		return;
  	}
	if(head==NULL)
	{
		printf("There is nothing in the list to delete\n\n");
	}
	else 
	{
	        ptr=head;
	        temp=head->next;
	        if(ptr->next==head)
     		{
			head=NULL;
			free(head);
			printf("The only node present in the list is deleted(linked list)\n\n");
			insertQueue(id);
	        }
		else if(ptr->rollNumber==id)
  		{
			temp->prev=head->prev;;
			head->prev->next=temp;
			head=head->next;
		        printf("Node deleted successfully\n\n");
		        insertQueue(id);
	  	}
		else
		{
		       while((temp->rollNumber)!=id)
		       {
		       	ptr=ptr->next;
		       	temp=temp->next;
		       }
		       ptr->next=temp->next;
		       temp->next->prev=ptr;
		       free(temp);
		       printf("Node deleted successfully\n\n");
		       insertQueue(id);
		     

		}
	}
}

void sortNamesAlphabetically()
{

  int count=1;
  struct node *temp1,*temp;
  temp=head;
  

  while(temp->next!=head)
  {
    temp=temp->next;
    count++;
  }
  printf("%d\n",count);
   char str[count][25];
   char temp3[25];
  
  int i;

  for(int i=0;i<count;i++)
  {
    strcpy(*(str+i),temp->name);
    temp=temp->next;
  }

   for( i=0;i<=count;i++)
      for(int j=i+1;j<=count;j++)
      {
         if(strcmp(*(str+i),*(str+j))>0){
            strcpy(temp3,*(str+i));
            strcpy(*(str+i),*(str+j));
            strcpy(*(str+j),temp3);
         }
      }
   printf("Order of Sorted Names: ");
   printf("\n");
   for(i=0;i<count;i++)
      { 
        printf("%s\n",*(str+i));
      }
}


char newName[150];
char newAddress[250];
char newDOB[20];
int  newNumber;
char oldname[150];
char oldDOB[20]; 
char oldAddress[250]; 
int oldNumber;

void modify(int key)
{
  int choice;
  struct node *temp2;
  temp2=head;
  while((temp2->next!=head)&&(temp2->rollNumber!=key))
  {
     temp2=temp2->next;
  }
  if(temp2->rollNumber==key)
  {
    printf("Which field do you want to modify?\n");
    printf("1.Name\n");
    printf("2.Date of Birth\n");
    printf("3.Address\n");
    printf("4.Mobile Number\n");
    printf("5.Exit\n");
    printf("Enter your choice : \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
		printf("Enter new name : ");
		scanf("%s",newName);
		strcpy(oldname,temp2->name);
		strcpy(temp2->name,newName);   
		printf("Name changed from %s to %s\n",oldname,temp2->name);
            break;
        case 2:
                printf("Enter new DOB : ");
		scanf("%s",newDOB);
		strcpy(oldDOB,temp2->date);
		strcpy(temp2->date,newDOB);   
		printf("DOB changed from %s to %s\n",oldDOB,temp2->date);
            break;
        case 3:
		printf("Enter new address : ");
		scanf("%s",newAddress);
		strcpy(oldAddress,temp2->address);
		strcpy(temp2->address,newAddress);   
		printf("Address changed from %s to %s\n",oldAddress,temp2->address);
	    break;
        case 4:
		 printf("Enter new number : ");
		 scanf("%d",&newNumber);
		 oldNumber=temp2->mobilenumber;
		 temp2->mobilenumber=newNumber;   
		 printf("Number changed from %d to %d\n",oldNumber,temp2->mobilenumber);
	    break;
         case 5:
            break;
         default:
                 printf("Wrong choice\n");

     }
  }
  else
  {
    printf("Unable to find element with given roll number\n");

  }
}

void search(int searchKey)
{
	  struct node *temp;
	  temp=head;
	  while((temp->next!=head)&&(temp->rollNumber!=searchKey))
	  {
	     temp=temp->next;
	  }
	  if(temp->rollNumber==searchKey)
	  {
	    printf("Search Successfull!\n");
	    printf("\nRoll No: %d\nName:%s\nDOB:%s\n",temp->rollNumber,temp->name,temp->date);
	  }
	  else
	  {
	    printf("Search unsuccessful,no such element exists\n");

	  }
}


void display()
{
	struct node *temp1;
	temp1=head;
	if(head==NULL)
	{
		printf("\nList is empty \n");
	}
	else
	{
		
		while((temp1->next)!=head)
		{
      			printf("\nRoll No: %d\nName:%s\nDOB:%s\n",temp1->rollNumber,temp1->name,temp1->date);
			temp1=temp1->next;
		}
		printf("\nRoll No: %d\nName:%s\nDOB:%s\n",temp1->rollNumber,temp1->name,temp1->date);
	}
}


int deleteQueue()
{
	int number;
	struct queueNode *temp;
	if(front==NULL)
	{
		return 0;
	}
	else if(front==rear)
	{
		number = front->rollNo;
		free(front);
		front=NULL;
		rear=NULL;
		return number;
	}
	else{
		number=front->rollNo;
         	temp=front;
         	front=front->next;
		free(temp);
		return number;
	    }
    
}

int main()
{
   char buff[1024];
   int choice;int delkey;int searchkey;int modifykey;
   FILE *fp = fopen("StudentData.csv", "r");
   fgets(buff, sizeof(buff), fp); // to skip column names  
   char Name[150], DOB[20], address[250];int phn_no; 

  do
   {
	  printf("What action do you want to perform?\n");
	  printf("1.Insert record from excel file\n");
	  printf("2.Delete a record from linkd list\n");
	  printf("3.Sort names alphabetically\n");
	  printf("4.Modify a record\n");
	  printf("5.Search for a record\n");
	  printf("6.Display records in linked list\n");
	  printf("7.Exit\n");
	  printf("Enter your choice : ");
  
   	  scanf("%d",&choice);

   	  switch(choice)
   	  {
    		    case 1: 
		            fgets(buff, sizeof(buff), fp);
		            char *token = strtok(buff, ",");
		            if(token!=NULL)
		            {
		            token = strtok(NULL, ",");
		            strcpy(Name, token);
		            token = strtok(NULL, ",");
		            strcpy(DOB, token);
		            token = strtok(NULL, ",");  
		            strcpy(address, token);
		            token = strtok(NULL, ",");
		            phn_no = atoi(token);
		            }
		            else{
		              printf("End of file reached\n");
		            }
		            insertion(Name,DOB,address,phn_no);
                    break;

		    case 2:
				      
			    printf("Enter roll number of record which you want to delete?");
		            scanf("%d",&delkey);
	        	    deletion(delkey); 
	            break;

		    case 3:
		            sortNamesAlphabetically();
	            break;

		    case 4:
		            printf("Enter roll number of record which you want to modify?");
		            scanf("%d",&modifykey);
		    	    modify(modifykey);
	            break;    

		    case 5:
				      
		            printf("Enter roll number of record which you want to search?");
		            scanf("%d",&searchkey);
	         	    search(searchkey);
		    break;

		    case 6:                 
			     display();
		    break;            

		    case 7:
		    break;

		    default:
        		     printf("Wrong choice\n");                          
				
	 }
     
   } while (choice!=7); 

   return 0;

}	
