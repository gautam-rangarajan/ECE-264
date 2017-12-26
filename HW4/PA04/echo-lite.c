#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
    int count = 1;

    while(count < argc){
    printf("%s", argv[count]);
    if(count != argc - 1){
    printf(" ");
    }
    count++;
    }

    printf("\n");


    return EXIT_SUCCESS;
}
