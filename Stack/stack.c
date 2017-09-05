#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

//Stack with linked list.

typedef struct Node {
	int data;
	struct Node *next;
}NODE;

NODE *top = NULL;

int push(int item);
int pop();
void display();
int empty();
void finish();

int main(void)
{
	int choice, item;

	do {
		printf("Menu : (1) Push (2) Pop (3) Show stack (4) Finish \n");
		printf("Choose number : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:

			printf("Input item value : ");
			scanf("%d", &item);

			if (!push(item))
				printf("%d insert completed!\n", item);
			else
				printf("%d not Insert. No memory aliable.\n", item);

			break;

		case 2:

			if ((item = pop()) != -1)
				printf("%d has popped!\n", item);
			else
				printf("Error. Stack is empty.\n");

			break;

		case 3: // Display
			display();
			break;

		case 4: // Finish 
			finish();
			return 0;

		default:
			printf("Please Choose 1~4!\n");
		}
		printf("\n-------------------------------------------\n");
	} while (choice != 4);

}

int empty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

int push(int item)
{
	NODE *newNode = malloc(sizeof(NODE));

	if (newNode != NULL) //is space available.
	{
		newNode->data = item;
		newNode->next = NULL;

		if (empty())
		{
			top = newNode;
		}
		else
		{
			newNode->next = top;
			top = newNode;
		}

		return 0;
	}
	else
		return 1;
}

int pop()
{
	NODE *temp = NULL;
	int data;

	if (!empty())
	{
		data = top->data;

		temp = top;
		top = top->next;
		free(temp);


		return data;
	}
	else
		return -1;
}

void display()
{
	NODE * temp = top;

	if (empty())
		printf("Stack is empty\n");
	else
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
	return;
}

void finish() {

	NODE * temp;

	while (!empty())
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	printf("free all nodes.End progam.\n");
	return;
}
