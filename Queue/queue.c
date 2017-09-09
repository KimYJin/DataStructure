#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {
	int data;
	struct Node *next;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;

int enqueue(int item);
int dequeue();
void display();
int empty();
void finish();

int main(void)
{
	int num, item; //선택 변수, 아이템 입력 변수,

	do {
		printf("Menu : (1) Insert Item (2) Delete Item (3) Show Queue (4) Finish \n");
		printf("Choose number : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1: // Insert

			printf("Input item value : ");
			scanf("%d", &item);

			if (!enqueue(item))
				printf("%d Insert completed!\n", item);
			else
				printf("%d not inserted. Memory is not available.\n", item);

			break;

		case 2: // Delete

			if ((item = dequeue()) != -1)
				printf("%d has deleted!\n", item);
			else
				printf("Error. Queue is empty.\n");
			break;

		case 3: // Display
			display();
			break;

		case 4: // Finish 
			finish();
			break;

		default:
			printf("Please Choose 1~4!\n");
		}
		printf("\n-------------------------------------------\n");
	} while (num != 4);
	return 0;
}

int empty()
{
	if (front == NULL)
		return 1;
	else
		return 0;

}


int enqueue(int item)
{
	NODE *newNode = malloc(sizeof(NODE));

	if (newNode != NULL)
	{
		newNode->next = NULL;
		newNode->data = item;

		if (empty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		return 0;
	}
	else
		return 1;
}

int dequeue()
{
	NODE*temp = NULL;
	int data;

	if (empty())
		return -1;
	else
	{
		data = front->data;

		temp = front;
		front = front->next;
		free(temp);

		return data;
	}

}

void display()
{
	NODE *temp;

	if (empty())
		printf("Queue is empty.\n");
	else
	{
		temp = front;

		while (temp != NULL)
		{
			printf("%d", temp->data);

			if (temp->next != NULL)
				printf(" -> ");

			temp = temp->next;
		}
		printf("\n");
	}
}

void finish()
{
	NODE *temp = NULL;

	while (front != NULL)
	{
		temp = front;
		front = front->next;
		free(temp);
	}
}
