
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"ListBaseStack.h"


void StackInit(Stack *pstack)
{
	pstack->head = NULL;
}
int SIsEmpty(Stack *pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	NODE *newNode = malloc(sizeof(NODE));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}
Data SPop(Stack *pstack)
{
	Data data;
	NODE *temp;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	data = pstack->head->data;
	temp = pstack->head;
	pstack->head = pstack->head->next;

	free(temp);
	return data;
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}


