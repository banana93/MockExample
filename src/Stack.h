#ifndef Stack_H
#define Stack_H

typedef struct 
{
	int *buffer;
	int size;
	int length;
}Stack;

Stack *stackNew(int length);
int stackPop(Stack *stackPtr);
void stackPush(Stack *stackPtr, int data);
int stackIsEmpty(Stack *stacks);
void stackDel(Stack *stacks);
int stackIsFull(Stack *stacks);


#endif // Stack_H