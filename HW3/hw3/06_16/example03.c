#include <stdio.h>
#include <stdlib.h>

int * foo(int x){
	
	int * ptr = malloc(sizeof(int)*x);
	
	int i;
	for(i=0;i<x;i++)
	{
		ptr[i] = i+2;
	}

	return ptr;
}

int main(int argc, char ** argv)
{

	int * myIntPtr = foo(3);
	printf("%d\n",myIntPtr[1]); //Should give values intiialized in foo
	free(myIntPtr);
	return EXIT_SUCCESS;
}
