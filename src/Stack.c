#include <stdio.h>
#include "Stack.h"
#include "malloc.h"
#include "ErrorCode.h"
#include "CException.h"

Stack *stackNew(int length)
{
	Stack *stacks;
	
	stacks = malloc(sizeof(Stack));
	stacks->buffer = malloc(sizeof(char) * length);
	stacks->length = length;
	stacks->size = 0;
	
	return stacks;
}

int stackIsFull(Stack *stacks)
{
	if(stacks->size > stacks->length)
		return 0;
	else 
		return 1;
		
}

/*
	In this function, the data will be stored into the buffer 
	and the size will increase, if it is full then it will throw an error.
*/
void stackPush(Stack *stacks, int data)
{
	if(!stackIsFull(stacks))
	{
		Throw(ERR_STACK_FULL); // Throw an error if the size and the length is the same or greater.
	}
	
	stacks->buffer[stacks->size] = data; // the data is stored into the buffer.
	stacks->size++; // the size will increase as the data is stored into the buffer.

}

/*
	In this function if the stack is empty it will return 0,
	if it is not then it will return 1.
*/
int stackIsEmpty(Stack *stacks)
{
	if(stacks->size == 0) // if the stack is empty then return 0
		return 0;
	else 
		return 1;
}


/*
	In this function, the data will be set to zero so that the
	zero will be placed into the buffer to indicate that it is removed.
	As the data is being removed from the buffer the size will decrease.
*/

int stackPop(Stack *stacks)
{
	int result;
	
	if(!stackIsEmpty(stacks))
	{
		Throw(ERR_STACK_EMPTY);
	}
	
	result = *stacks->buffer; // set the buffer to zero value to indicate that the value is pop out.
	stacks->size--; // as the value is removed the size will decrease.
	
	return result;
	
}


void stackDel(Stack *stacks)
{
	if(stacks != NULL)
	{
		free(stacks->buffer);
		free(stacks);
	}
}

