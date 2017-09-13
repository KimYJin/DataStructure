#ifndef __LB_STACK_H__
#define __LB_STACK_H__


#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node
{
	Data data;
	struct node *next;
}NODE;

typedef struct listStack
{
	NODE *head;
}Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pastack);
Data SPeek(Stack *pstack);


#endif
