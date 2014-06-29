#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "StringReversal.h"
#include "Stack.h"

char *reverseString(char *stringToReverse)
{
	int i, j = 0;
	char *reverseString, ch;
	Stack *stack = stackNew(512);
	
	printf("stack: %p \n", stack);
	printf("size: %d, length: %d \n", stack->size, stack->length);	
	
	for(i = 0; stringToReverse[i] != '\0'; i++)
	{
		stackPush(stack, (int)stringToReverse[i]);
		printf("%c", stringToReverse[i]);
	}
	
	printf("\n i: %d \n", i);
	reverseString = malloc(sizeof(char) * (i + 1));
	
	while(!stackIsEmpty(stack))
	{
		reverseString[j++] = stackPop(stack);
		printf("%c", reverseString[j-1]);
	}
	
	reverseString[j] = '\0';
	
	return reverseString;
}