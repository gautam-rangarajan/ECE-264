#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
int x = 0;
int sum = 0;

while(len > x)
{
sum = sum + array[x];
x++;
}

	return sum;
}

int arrayCountNegative(int * array, int len)
{
int x = 0;
int negCount = 0;

while(len > x)
{
if(array[x] < 0)
{
negCount++;
}
x++;
}


	return negCount; 
}

int arrayIsIncreasing(int * array, int len)
{
int x = 1;
int incOrNot = 1;

if(len >= 2)
{
while(len > x)
{
if (array[x] < array[x-1])
{
incOrNot = 0;
}
x++;
}
}

	return incOrNot;
}



int arrayIndexFind(int needle, const int * haystack, int len)
{
int x = 0;
int position = -1;

while(len > x)
{
if(haystack[x] == needle)
{
position = x;
}
x++;
}

	return position;
}

int arrayFindSmallest(int * array, int len)
{
int x = len-1;
int position = 0;
int smallest = array[len-1];

if(len > 0)
{
while(x >= 0)
{
if(array[x] <= smallest)
{
smallest = array[x];
position = x;
}
x--;
}
}
	return position;
}
