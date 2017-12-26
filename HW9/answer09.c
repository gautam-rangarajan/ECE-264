#include "answer09.h"

/* This function has been completed for you */


static void quickSortHelp ( int * arr , int first , int last );

void quickSort ( int * arr , int len);

void ListToArray(Node * head, int* array);

void ArrayToList(Node * head, int * array);

void swap(int* a, int* b);



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
	int len = 0;
	while (head != NULL){
		len++;
		head = head->next;
	}
	return len;
}

int List_swap(Node * head, int index1, int index2)
{
	Node * curr1;
	Node * curr2;

	if ((index1 < 0) || (index1 >= List_length(head))){
		return EXIT_FAILURE;
	}
	if ((index2 < 0) || (index2 >= List_length(head))){
		return EXIT_FAILURE;
	}
	
	while (head->index != index1){
		head = head->next;
		}
		if(head->index == index1){
			curr1 = head;
		}
	
		while(head->index != index2){
			head = head->next;
		}
			if(head->index == index2){
				curr2 = head;
			}
		int temp1 = curr1->value;
		int temp2 = curr2->value;

		curr1->value = temp2;
		curr2->value = temp1;
		

	return EXIT_SUCCESS;
}


int List_read(Node * head, int index)
{
		while (head->index != index){
		 	head = head->next;
		}
		if (head->index == index){
			return head->value;
		}
	return EXIT_FAILURE; 
}

int List_write(Node * head, int index, int val)
{
	while (head->index != index){
		head = head->next;
	}
	if(head->index == index){
		head->value = val;
		return EXIT_SUCCESS;
	}	
	return EXIT_FAILURE;
}


Node * List_qsort(Node * head, int length)
{

int arrayTest[length];
ListToArray(head, arrayTest);
quickSort(arrayTest, length);
ArrayToList(head, arrayTest);

return (head);

}

Node * List_readFromTextFile(char * filename)
{
FILE * fp = NULL;
Node * curr = NULL;
int ch;

fp = fopen(filename, "r")	;
if(fp == NULL){
	return NULL;
}

while(fscanf(fp, "%d", &ch) != EOF){
	curr = List_insert(curr, ch);
}

fclose(fp);
return curr;
}

int List_writeToTextFile(Node * head, char * filename)
{
FILE * fp = NULL;

fp = fopen(filename, "w");
if(fp == NULL){
	return EXIT_FAILURE;
}

while(head != NULL){
	fprintf(fp, "%d", head->value);
	fprintf(fp, "\n");

	head = head->next;
}
fclose(fp);
return EXIT_SUCCESS;
}

Node * List_readFromBinaryFile(char * filename)
{
	FILE * fp = NULL;
	Node * curr = NULL;

	Node * ch = malloc(sizeof(Node));

	fp = fopen(filename, "rb");
	if (fp == NULL) return NULL;
	
	while ((fread(ch, sizeof(Node),1, fp)) == 1)
	{
		curr = List_insert(curr, ch->value);
	}
	free(ch);
	fclose(fp);
	return curr;
}

int List_writeToBinaryFile(Node * head, char * filename)
{
	FILE * fp = NULL;

	fp = fopen(filename, "wb");
	
	if (fp == NULL) return EXIT_FAILURE;

	while (head != NULL)
	{
		fwrite(head, sizeof(Node), 1, fp);
		head = head->next;
	}

	fclose(fp);
	return EXIT_SUCCESS;
}

////// ------- USER ENTERED FUNCTIONS ------ ///////

void ListToArray(Node * head, int* array)
{
Node * current = head;
int i = 0;
 
while (current != NULL)
{
    array[i] = current->value;
    current = current->next; 
    i++;   
}
}

static void quickSortHelp ( int * arr , int first , int last )
{
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
low ++;
}
while (( first < high ) && (arr [ high ] > pivot ))
{
high --;
}
if (low < high )
{
swap (&arr[ low ], &arr[ high ]);
}
}
if ( pivot > arr[ high ])
{
swap (&arr[first], &arr[high]);
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


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}




