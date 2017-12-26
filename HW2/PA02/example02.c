#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	char * str = "Hello";
	str++;
	while((*str) != '\0'){
		printf("Current character is: %p\n",&str);
		str++;	
	
	}
	//*str = '!';
	
	return EXIT_SUCCESS;
}
