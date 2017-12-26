#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	
	int myIntArr[5];
	printf("myIntArr[0]: %d\n",myIntArr[0]);
	//printf("myIntArr[5]: %d\n",myIntArr[5]);
	//printf("myIntArr[99999]: %d\n", myIntArr[99999]);
	
	int a = 4;
	int * myIntPtr;
	myIntPtr = myIntArr;
	myIntPtr = &a;
	*myIntPtr = 20;

	printf("a: %d",a);

	return EXIT_SUCCESS;
}
