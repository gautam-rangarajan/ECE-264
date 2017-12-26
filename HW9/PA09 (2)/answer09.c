#include "answer09.h"

/* This function has been completed for you */

Node * Node_construct(int val, int ind)
{
	Node * nd = calloc(1,sizeof(Node));
	nd->next = NULL;
	nd->value = val;
	nd->index = ind;
	
	return nd;
}

/* This function has been completed for you */

static Node * List_insertHelper(Node * head , int val, int ind)
{
	if(head == NULL)
	{
		return Node_construct(val,ind);
	}
	head-> next = List_insertHelper(head->next,val,ind+1);
	return head;
}

/* This function has been completed for you */

Node * List_insert ( Node * head , int val)
{
	return List_insertHelper(head,val,0);
} 

/* This function has been completed for you */

void List_destroy ( Node * head )
{
	if(head==NULL) return;
	List_destroy(head->next);
	free(head);
}

/* This function has been completed for you */

void List_print(Node * head)
{
	while(head !=NULL)
	{
		printf("[%d]:%d ",head->index,head->value);
		head = head->next;
	}
	printf("\n");
}

int List_length(Node * head)
{
	//Write your code here	
	
	return -1; //Change this
}

int List_swap(Node * head, int index1, int index2)
{
	//Write your code here	
		
	return -1; //Change this
}

int List_read(Node * head, int index)
{
	//Write your code here	
		
	return -1; //Change this
}

int List_write(Node * head, int index, int val)
{
	//Write your code here	
		
	return -1; //Change this
}


Node * List_qsort(Node * head, int length)
{
	//Write your code here	
		
	return NULL;	//Change this
}

Node * List_readFromTextFile(char * filename)
{
	//Write your code here	
		
	return NULL; //Change this	
}

int List_writeToTextFile(Node * head, char * filename)
{
	//Write your code here	
		
	return -1; //Change this
}

Node * List_readFromBinaryFile(char * filename)
{
	//Write your code here	
	
	return NULL; //Change this
}

int List_writeToBinaryFile(Node * head, char * filename)
{
	//Write your code here	
	
	return -1; //Change this
}

