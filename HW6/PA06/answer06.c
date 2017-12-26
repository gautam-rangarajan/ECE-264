#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer06.h"

List * List_createNode(const char * str)
{
List * head = NULL;
head = malloc(sizeof(List));


if(str == NULL){
head->str = NULL;
}
else{
head->str = strdup(str);
}

head->next = NULL;

return (head);
}

void List_destroy(List * list)
{

List * temp;

if(list == NULL){
return;
}

while(list != NULL){
temp = list->next;

free (list->str);
free(list);

list = temp;

}


return;
}

int List_length(List * list)
{
int length = 0;

if(list == NULL){
return length;
}

length = 1;

while(list->next != NULL){
length++;
list = list->next;
}

return length;
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
List * head;
List * temp;
List * curr;

if(lhs == NULL && rhs == NULL){
return NULL;
}
else if(lhs == NULL){
return rhs;
}
else if(rhs == NULL){
return lhs;
}

if(compar(lhs->str,rhs->str) < 0){
head = lhs;
lhs = lhs->next;
}
else if(compar(lhs->str,rhs->str) > 0){
head = rhs;
rhs = rhs->next;
}
else if(compar(lhs->str,rhs->str) == 0){
head = lhs;
lhs = lhs->next;
}

head->next = NULL;
curr = head;


while(lhs != NULL  && rhs != NULL){

if(compar(lhs->str,rhs->str) > 0){
temp = rhs->next;
curr->next = rhs;
curr = rhs;
curr->next = NULL;
rhs = temp;
}
else{
temp = lhs->next;
curr->next = lhs;
curr = lhs;
curr->next = NULL;
lhs = temp;
}

}

if(lhs == NULL){
curr->next = rhs;
}
else if(rhs == NULL){
curr->next = lhs;
}

return head;
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{

int length = 1;
List * temp = list;
int posn = 1;
List * lhs = list;
List * rhs;
List * head;


if(list == NULL){
return list;
}

if(temp->next == NULL){
return list;
}

while(temp->next != NULL){
length++;
temp = temp->next;
}

temp = lhs;

while(posn < length/2){
temp = temp->next;
posn++;
}

rhs = temp->next;
temp->next = NULL;

lhs = List_sort(lhs, compar);
rhs = List_sort(rhs, compar);

head = List_merge(lhs, rhs, compar);

return head;

}
