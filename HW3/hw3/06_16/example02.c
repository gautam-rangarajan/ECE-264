#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	int numElements = atoi(argv[1]); //Converts string to integer
	int * myArr = malloc(sizeof(int)*numElements);
	int i;
	for(i=0; i < numElements; i++){

		myArr[i]= i+2;
		printf("Index number %d of the array has value %d\n",i,myArr[i]);

	}
	//free(myArr); //Not freeing will result in a memory leak
	return EXIT_SUCCESS;
}
