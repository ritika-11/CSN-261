#include <stdio.h>
#include <bits/stdc++.h> 
#include <assert.h> 
using namespace std; 

class Node 
{ 
	public: 
	int data;
	int start;
	int end; 
	Node* next; 
}; 

Node* head = NULL;
Node* temp = NULL;

void push(Node** head_ref, int new_data, int inds, int inde);
int GetNth(Node* head, int s, int e) ;
int new_check(int counter);

int main()
{  
	int n,c;
	int count=0;
	cout<<"Enter the number of integers : ";
	cin>>n;
	int array[n];
	cout<<"Enter the integers"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i==0&&j==0)
				push(&head, array[j], i, j);
			else
			{
				if(i==0)
					push(&head, (array[j]^GetNth(head, i, j-1)), i, j);
				else
					push(&head, (array[i-1]^GetNth(head, i-1, j)), i, j);
			}
		}
	}
	cout<<"LEXOGRAPHIC ORDER OF ALL TRIPLETS IS AS FOLLOWS :-"<<endl;
	c = new_check(count);
	cout<<"TOTAL COUNT IS : "<<c<<endl;
}

void push(Node** head_ref, int new_data, int inds, int inde) 
{ 
	
	// allocate node 
	Node* new_node = new Node(); 

	// put in the data 
	new_node->data = new_data;
	new_node->start = inds;
	new_node->end = inde; 

	// link the old list 
	// off the new node 
	new_node->next = (*head_ref); 

	// move the head to point 
	// to the new node 
	(*head_ref) = new_node; 
} 

int GetNth(Node* head, int s, int e) 
{ 
	
	Node* current = head; 
	
	
	while (current != NULL) 
	{ 
		if ((current->start == s) && (current->end == e))
			return(current->data);  
		current = current->next; 
	} 

	/* if we get to this line, 
	the caller was asking 
	for a non-existent element 
	so we assert fail */
	assert(0);	 
} 

int new_check(int counter)
{
	temp = head;
	while(temp)
	{
		if(temp->data==0)
		{
			for(int i=temp->start+1;i<=temp->end;i++)
			{
				counter++;
				cout<<"("<<temp->start+1<<","<<i+1<<","<<temp->end+1<<")"<<endl;
			}
		}
		temp = temp->next;
	}
	return counter;
}
