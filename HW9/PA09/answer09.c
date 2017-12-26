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

////// ------- USER ENTERED FUNCTIONS ------ ///////

int * ListToArray(Node * head)
{
	Node * current = head;
	int len = List_length(head);
	int * array[len-1];

	int i = 0;
 
	while (current != null)
	{
    array[i] = current->data;
    current = current->next; 
    i++;   
	}

	return (array);

}

static void quickSortHelp ( int * arr , int first , int last )
{
	// [first , last ]: range of valid indexes (not last - 1)
	if ( first >= last ) // no need to sort one or no element
	{
		return;
	}
	#ifdef DEBUG
	printf (" first  = %d,  last  = %d\n", first , last ); //Need to compile with -DDEBUG to use
	#endif
	int pivot = arr[ first ];
	int low = first + 1;
	int high = last ;
	while (low < high )
	{
		while (( low < last ) && (arr [low ] <= pivot ))
		{
			// <= so that low will increment when arr [low ]
			// is the same as pivot , using < will stop
			// incrementing low when arr [low ] is the same
			// as pivot and the outer while loop will not stop
			low ++;
		}
		while (( first < high ) && (arr [ high ] > pivot ))
		{
			high --;
		}
		if (low < high )
		{
			swap (& arr[ low ], & arr [ high ]);
		}
	}
	if ( pivot > arr[ high ])
	{
		swap (& arr [ first ], & arr [ high ]);
	}
	quickSortHelp (arr , first , high - 1);
	quickSortHelp (arr , low , last );
}

void quickSort ( int * arr , int len)
{
	quickSortHelp (arr , 0, len - 1);
 
}

void ArrayToList(Node * head, int * array)
{
	int i = 0;

	while(head != NULL)
	{
		head->value = array[i];
		head = head->next;
		i++;
	}

}


//////-------USER ENTERED FUNCTIONS-------////// ----- ADD THESE TO ANSWER09.H
//int * ListToArray(Node * root);

//static void quickSortHelp ( int * arr , int first , int last );

//void quickSort ( int * arr , int len);

//int * ListToArray(Node * head);

//void ArrayToList(Node * head, int * array);

{
	//-------will probably be in main-------------
	int * array [9] = [1,8,3,9,0,4,2,7,5,3];
	int i = 1;
	int val;

	//creating a linked list to be qsorted
	Node * head = Node_construct(array[0], 0);
	Node * tempHead = head;

	while (array[i] != NULL)
	{
		val = array[i];
		tempHead->next = Node_construct(array[i], i);
		tempHead = tempHead->next;	
		tempHead->next = NULL;
		i++;
	}	

	//int len = List_length(head);
	//List_qsort(head, len)
	//------------------------------------------

	//--will probably be in the List_qsort fn---

	//convert linked list into an array
	int * arrayTest[9];  //change 9 to length
	arrayTest = ListToArray(head);

	//quicksorting the array
	int len = List_length(head);
	quickSort(arrayTest, len);

	//convert the array back into a linked list
	ArrayToList(head, arrayTest);


}