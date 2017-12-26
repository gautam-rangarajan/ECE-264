#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "answer06.h"
int compar ( const char * a, const char * b)
{
if(a == NULL || b == NULL){
return 1;
}

return strcmp(a,b);

}

int main(int argc, char ** argv)
{
const char * str1 = "g";
const char * str2 = "G";

//int a;
int i = 1;

List * lhs = NULL;
List * head = NULL;
List * rhs = NULL;
List * temp = NULL;
lhs = List_createNode(str1);
rhs = List_createNode(str2);

temp = lhs;
head = rhs;

//a = List_length(lhs);
//printf("a = %d\n", a);


while(i < 2){


temp->next = List_createNode(str2);
head->next = List_createNode(str1);
temp = temp->next;
head = head->next;
temp->next = NULL;
head->next = NULL;

i++;
}



lhs = List_sort(lhs, compar);
rhs = List_sort(rhs, compar);

head = List_merge(lhs, rhs, compar);
//head = List_sort(lhs, compar);
List * dest = head;

while(head != NULL){
printf("%c ", *(head->str));
head = head->next;

}


List_destroy(dest);


return EXIT_SUCCESS;
}
