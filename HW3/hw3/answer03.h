#ifndef PA03_H
#define PA03_H
#include <stdlib.h>

/**
 * Append the C-string 'src' to the end of the C-string '*dest'.
 *
 * strcat_ex(...) will append the C-string 'src' to the end of the string
 * at '*dest'. The parameter 'n' is the address of a int that specifies how
 * many characters can safely be stored in '*dest'.
 *
 * If '*dest' is NULL, or if '*dest' is not large enough to contain the result
 * (that is, the sum of the lengths of *dest, src, and the null byte), then
 * strcat_ex will:
 * (1) malloc a new buffer of size 1 + 2 * (strlen(*dest) + strlen(src))
 * (2) set '*n' to the size of the new buffer
 * (3) copy '*dest' into the beginning of the new buffer
 * (4) free the memory '*dest', and then set '*dest' to point to the new buffer
 * (5) concatenate 'src' onto the end of '*dest'.
 *
 * Always returns *dest.
 *
 * Why do we need to pass dest as char * *, and n as int *?
 * Please see the README for an answer.
 *
 * Hint: These <string.h> functions will help: strcat, strcpy, strlen.
 * Hint: Leak no memory.
 */
char * strcat_ex(char * * dest, int * n, const char * src);

/**
 * Takes a string and splits it into an array of strings according to delimiter.
 * The memory location '*arrLen' is initialized to the length of the returned
 * array.
 *
 * str: A string to split
 * delims: a string that contains a set of delimiter characters. explode(...)
 *         will split the string at any instance of a character that appears in 'delims'.
 * arrLen: pointer to an int that is used to store the resultant length of the
 *         returned array.
 *
 * For example, if delimiter is white space " \t\v\n\r\f", then,
 * int len;
 * char * * strArr = explode("The\nTuring test", " \t\v\n\r\f", &len);
 * // len = 3, strArr[0] is "The", strArr[1] is "Turing", strArr[2] is "test"
 *
 * Hint: you can use <string.h> functions "memcpy" and "strchr"
 *       "memcpy" copies blocks of memory.
 *       "strchr" can be used to tell if a specific character is in delims.
 * Hint: this question is hard; it will help to draw out your algorithm.
 * Hint: read the README...
 */
char * * explode(const char * str, const char * delims, int * arrLen);

/**
 * Takes an array of strings, and concatenates the elements into a single
 * string, placing a 'glue' string between each successive element.
 *
 * strArr: an array of strings
 * len: the length of the array 'strArr'
 * glue: string to concatenate between each element of 'strArr'
 *
 * For example:
 * int len;
 * char * * strArr = explode("100 224 147 80", " ", &len);
 * char * str = implode(strArr, len, ", ");
 * printf("(%s)\n", str); // (100, 224, 147, 80)
 *
 * Hint: use strcat_ex in a for loop.
 */
char * implode(char * * strArr, int len, const char * glue);

/**
 * Takes an array of C-strings, and sorts them alphabetically, ascending.
 *
 * arrString: an array of strings
 * len: length of the array 'arrString'
 *
 * For example,
 * int len;
 * char * * strArr = explode("lady beatle brew", " ", &len);
 * sortStringArray(strArr, len);
 * char * str = implode(strArr, len, " ");
 * printf("%s\n", str); // beatle brew lady
 *
 * Hint: use the <stdlib.h> function "qsort"
 * Hint: you must _clearly_ understand the typecasts.
 */
void sortStringArray(char * * arrString, int len);

/**
 * Sorts the characters in a string.
 *
 * str: string whose characters are to be sorted
 *
 * For example,
 * char * s1 = strdup("How did it get so late so soon?");
 * sortStringCharacters(s1)
 * // s1 is now "       ?Haddeegiilnooooossstttw"
 *
 * Hint: use the <stdlib.h> function "qsort"
 * Hint: you must _clearly_  understand the typecasts.
 */
void sortStringCharacters(char * str);

/**
 * Safely frees all memory associated with strArr, and then strArr itself.
 * Passing NULL as the first parameter has no effect.
 *
 * strArr: an array of strings
 * len: the length of 'strArr'
 *
 * int len;
 * const char * abe = "Give me six hours to chop down a tree and I will spend\nthe first four sharpening the axe.";
 * char * * strArr = explode(abe, "\n ");
 * destroyStringArray(strArr, len); // cleans memory -- no memory leaks
 * destroyStringArray(NULL, 0); // does nothing, does not crash.
 */
void destroyStringArray(char * * strArr, int len);



#endif




///////////////////////////////////
   //tester

         // test for strcat_ex
  //test 1
 //const char * z2 = "How did it get so late so soon?";
 //char * s1 = NULL;
 //int n1;
// char * s2 = strcat_ex(&s1, &n1, z2);
 //printf("s1: %s\n", s2);
// printf("n= %d\n", n1);


 //char ** strArr;
 //int len;
 //char *delims =  " \t\v\n\r\f";
 //char * str = "Hello World\nhjfhjd\v g";
 //strArr = explode(str, delims, &len);
 //printf("%s\n", strArr[2]);

 //free(s2);


 //int len;
 //char * * strArr = explode("100 224 147 80", " ", &len);
 //printf("%s\n", strArr[3]);
 //char * str = implode(strArr, len, ", ");
 //printf("(%s)\n", str); // (100, 224, 147, 80)
 //test 2
 //const char * z0 = "";
 //int n2;
 //char * s3 = strcat_ex(&s1, &n2, z0);
// printf("s3: %s\n", s3);
 //printf("n= %d\n", n2);


 //test3
 //int n3 = 2048;
 //char * s4 = malloc(n);
 //s4[0] = '\0';
 //char * s6 = strcat_ex(&s4, &n3, z2);
 //printf("s1: %s\n", s6);
 // printf("n= %d\n", n3);
//int len;
//char * * strArr = explode("lady beatle brew", " ", &len);
//len = strlen((const char*)strArr);
//sortStringArray(strArr, len);
//char * str = implode(strArr, len, " ");
//printf("%s\n", str); // beatle brew lady


//char * s10 = strdup("How did it get so late so soon?");
// sortStringCharacters(s10);
 //printf("%s\n", s10);

 //int len;
 //const char * abe = "Give me six hours to chop down a tree and I will spend\nthe first four sharpening the axe.";
 //char * * strArr = explode(abe, "\n ", &len);
 //destroyStringArray(strArr, len); // cleans memory -- no memory leaks
 //destroyStringArray(NULL, 0); // does nothing, does not crash.
