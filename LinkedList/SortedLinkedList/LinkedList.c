#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//���Ḯ��Ʈ�� �̿��� ����ü �����ϱ�.

typedef struct student {
	int id;
	char name[100];
	struct student *next;
}NODE;

void insert(NODE** head)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	NODE *currPtr = NULL;
	NODE *prePtr = NULL;

	if (newNode != NULL)
	{
		printf("�л��� ID : ");
		scanf("%d", &newNode->id);

		printf("�л��� name : ");
		scanf("%s", &newNode->name);

		newNode->next = NULL;
		currPtr = *head;

		while (currPtr != NULL && newNode->id >= currPtr->id)
		{
			prePtr = currPtr;
			currPtr = currPtr->next;
		}

		//insert new node at the beginnig of list
		if (prePtr == NULL)
		{
			newNode->next = (*head);
			*head = newNode;
		}
		//insert new node between nodes or at the last of list.
		else
		{
			prePtr->next = newNode;
			newNode->next = currPtr;
		}

	}
	else {
		printf("Not inserted. No memory available\n");
	}
}

void delete(NODE **head, int target)
{
	NODE *prePtr = NULL, *currPtr = NULL, *tempPtr = NULL;

	//delete first node
	if ((*head)->id == target)
	{
		tempPtr = *head;
		*head = (*head)->next;
		free(tempPtr);
		printf("%d deleted.\n", target);
	}
	else
	{
		prePtr = *head;
		currPtr = (*head)->next;

		while (currPtr != NULL && currPtr->id != target)
		{
			prePtr = currPtr;
			currPtr = currPtr->next;
		}

		if (currPtr != NULL)
		{
			prePtr->next = currPtr->next;
			tempPtr = currPtr;
			free(tempPtr);
			printf("%d deleted.\n", target);
		}
		else
		{
			printf("��ġ�ϴ� id�� �л��� �����ϴ�.\n");
		}
	}
}

void printList(NODE *currPtr)
{

	while (currPtr != NULL)
	{
		printf(" %d , %s \n", currPtr->id, currPtr->name);
		currPtr = currPtr->next;
	}

}
void allFree(NODE **head)
{
	NODE* tempPtr = NULL;

	while (*head != NULL)
	{
		tempPtr = *head;
		free(tempPtr);
		*head = (*head)->next;
	}
}

int main(void)
{
	NODE *head = NULL;
	NODE *newNode = NULL;
	NODE *curr = NULL;

	int select = 0, target = 0;
	int i;


	while (1)
	{
		printf("1:���� 2:���� 3:��� 4:����\n");
		scanf("%d", &select);

		switch (select) {

		case 1:
			insert(&head);
			printList(head);
			break;

		case 2:

			if (head == NULL)
				printf("List is empty");
			else
			{
				printf("������ �л��� ID : ");
				scanf("%d", &target);
				delete(&head, target);
				printList(head);
			}

			break;

		case 3:
			if (head == NULL)
				printf("List is empty.\n");
			else
				printList(head);

			break;

		case 4:
			allFree(&head);
			printf("��� node���� �Ϸ�\n");
			return 0;
		}
	}

	for (;;);
}