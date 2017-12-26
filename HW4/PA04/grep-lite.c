#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
    int help = 0;
    int count = 1;
    int invertMatch = 0; //prints non matching lines
    int lineNumber = 0;  //prints line number with matching pattern
    int quiet = 0;       //quits grep-lite
    int suf = 1;

    //MAKING SURE THE USER ENTERED SUFFICIENT INPUTS
    if(argc <= 2){
    suf = 0;
    }

    //CHECKING IF USER ENTERED HELP
    while(count < argc){
        if(strcmp(argv[count],"--help") == 0){
        help = 1;
        }
        count++;
    }

    if(help == 1){
    printf("Usage: grep-lite [OPTION]... PATTERN\n");
    printf("Search for PATTERN in standard input. PATTERN is a string. grep-lite will search standard input line by line, and (by default) print out those lines which contain pattern as a substring.\n\n");

    printf("-v, --invert-match     print non-matching lines\n");
    printf("-n, --line-number      print line numbers with output\n");
    printf("-q, --quiet            suppress all output\n\n");

    printf("Exit status is 0 if any line is selected, 1 otherwise;\n");
    printf("if any error occurs, then the exit status is 2.\n");
    return EXIT_SUCCESS;
    }


    //TO MAKE SURE THE LAST ARGUMENT DOES NOT START WITH '-'
    int correctPattern = 1;
    if(argv[argc - 1][0] == '-'){
    fprintf(stderr, "The last argument cannot begin with a '-'! \n");
    correctPattern = 0;
    return 2;
    }

    //CHECKS WHICH PATTERN RECOGNITION OPTIONS HAVE BEEN SELECTED
    int count1 = 0;
    int stop = 0;
    if(suf && !help && correctPattern){
        for(count1 = 1; count1 < (argc-1)  && stop == 0; count1++){

        if(strcmp(argv[count1], "-v") == 0 || strcmp(argv[count1], "--invert-match") == 0){
        invertMatch = 1;
        }

        else if(strcmp(argv[count1], "-n") == 0 || strcmp(argv[count1], "--line-number") == 0){
        lineNumber = 1;
        }

        else if(strcmp(argv[count1], "-q") == 0 || strcmp(argv[count1], "--quiet") == 0){
        quiet = 1;
        }

        else{
        stop = 1;
        }
        }
    }

    if(stop == 1){
    fprintf(stderr, "One or more of the arguments are invalid!");
    return 2;
    }


    char input[2000];
    int inputNumber = 1;


    while(fgets(input,2000, stdin) != NULL){

        char * match = strstr(input, argv[argc-1]);

        if((invertMatch == 0 && lineNumber == 0 && quiet == 0)){
            if(match != NULL){
            printf("%s", input);
            }

        }

        if((invertMatch == 0 && lineNumber == 0 && quiet == 1)){
            if(match != NULL){
            return 1;
            }
            else{
            return 0;
            }
        }

        if((invertMatch == 0 && lineNumber == 1 && quiet == 0)){
            if(match != NULL){
            printf("%d:%s", inputNumber, input);
            }

        }

        if((invertMatch == 0 && lineNumber == 1 && quiet == 1)){
            if(match != NULL){
            return 1;
            }
            else{
            return 0;
            }

        }

        if((invertMatch == 1 && lineNumber == 0 && quiet == 0)){
            if(match == NULL){
            printf("%s", input);
            }
        }

        if((invertMatch == 1 && lineNumber == 0 && quiet == 1)){
            if(match == NULL){
            return 1;
            }
            else {
            return 0;
            }
        }

        if((invertMatch == 1 && lineNumber == 1 && quiet == 0)){
            if(match == NULL){
            printf("%d:%s", inputNumber, input);
            }
        }

        if((invertMatch == 1 && lineNumber == 1 && quiet == 1)){
            if(match == NULL){
            return 1;
            }
            else{
            return 0;
            }
        }

    inputNumber++;
    }

return 0;

}
