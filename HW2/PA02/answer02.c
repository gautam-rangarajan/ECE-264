#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char * str)
{
int len = 0;

while (str[len] != '\0')
{
len = len + 1;
}

return len;
}

int my_countchar(const char * str, char ch)
{
int len = 0;
int ch_count = 0;

while (str[len] != '\0')
{
if(str[len] == ch)
{
ch_count++;
}
len++;
}

return ch_count;
}


char * my_strchr(const char * str, int ch)
{

int loc = 0;
int len = my_strlen(str);

char x = 0;
while(loc < len){
	if(str[loc] == ch)
	break;
	loc++;
	}
if(loc == len){
	return NULL;
}
else if(ch == '\0'){
	x = '\n';
	return x;}
else
	return (char*)(str + loc);
}


char * my_strrchr(const char * str, int ch)
{
char * addr;
int len = 0;

while (str[len] != '\0')
{
if(str[len] == ch)
{
addr = (char *)str + len;
}
len++;
}

return addr;
}

char * my_strstr(const char * haystack, const char * needle)
{
int len = 0;
char * addr = 0;
int len2 = 0;
int found = 0;
int cont = 1;

while (haystack[len] != '\0' && cont == 1 && needle[0] != '\0')
{
	if(haystack[len] == needle[0])
	{
	while(needle[len2] != '\0')
	{
	if(needle[len2] == haystack[len + len2]) {
	found = 1;
	}
	else{
	found = 0;
	}
	len2++;
	}
	}
if(found == 0){
len++;
cont = 1;
}
else{
addr = (char *)haystack + len;
cont = 0;
}
}

if(my_strlen(needle) == 0){
	addr = (char *)haystack;
}
else if(needle == '\0'){
	addr = (char *)haystack;
}
else if(found == 0){
	addr =  NULL;
}

return addr;
}


char * my_strcpy(char * dest, const char * src)
{
int len = 0;
char * loc = dest;
while(src[len] != '\0')
{
*loc = src[len];
loc++;
len++;
}

*loc = '\0';

return dest;


}


char * my_strcat(char * dest, const char * src)
{
char * loc = dest;
int len = my_strlen(dest);
int len2 = 0;

if(len == 0){
loc = my_strcpy(dest, src);
}
else{
	while(src[len2] != '\0')
	{
	*(loc + len + len2) = src[len2];
	len2++;
	}
*(loc + len + len2) = '\0';
}
return dest;
}

int my_isspace(int ch)
{
int true = 0;
if(ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v')
{
true = 1;
}

return true;
}


int my_atoi(const char * str)
{
int len = 0;
int check = 0;
int x = 0;
int answer = 0;
char c = 0;
int stop = 0;

while (str[len] != '\0' && stop == 0)
{
x = str[len];
check = my_isspace(x);

if(str[len] >= 48 && str[len] <= 58){
c = str[len];
answer = answer*10 + (c - '0');
}

if(check == 1 || (str[len] >= 48 && str[len] <= 58)){
len++;
}
else{
stop = 1;
}
}

return answer;
}
