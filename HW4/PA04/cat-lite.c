#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
    int help = 0;
    int count = 1;
    int count1 = 1;
    int quit = 0;
    char c;
    int dash;

    FILE * fp;

    //checking if user entered help
    while(count < argc){
        if(strcmp(argv[count],"--help") == 0){
        help = 1;
        }
        count++;
    }

    if(argc > 1){
    //checking every argument entered
    while(!quit && !help && count1 < argc){
       //check if std input
       dash = 0;
        if(strcmp(argv[count1],"-") == 0){

            while((c = fgetc(stdin)) != EOF){
            printf("%c", c);
            }
            dash = 1;
        }


        if(dash != 1){
        //check if valid file name
        fp = fopen(argv[count1], "r");
        if(fp == NULL){
            fprintf(stderr, "cat cannot open %s\n",argv[count1]);
            quit = 1;
            return EXIT_FAILURE;
        }
        //print from file name
        else{
            while((c = fgetc(fp)) != EOF){
            printf("%c", c);
          }
        }
        }

        count1++;

    }

    if(help == 1){
    printf("Usage: cat-lite [--help] [FILE]...\n");
    printf("With no FILE, or when FILE is -, read standard input (can exit with CTRL+D, play around with ""cat"" to get a sense of how this works\n");
    }
    }
    else{
            while((c = fgetc(stdin)) != EOF){
            printf("%c", c);
            }
            dash = 1;
    }



    return EXIT_SUCCESS;
}
