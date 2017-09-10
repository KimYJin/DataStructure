#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}BTreeNode;

BTreeNode* makeBTreeNode(void);
int getData(BTreeNode *bt);
void setData(BTreeNode *bt, int data);
BTreeNode* getLeftSubTree(BTreeNode *bt);
BTreeNode* getRightSubTree(BTreeNode *bt);
void makeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void makeRightSubTree(BTreeNode* main, BTreeNode* sub);


int main(void)
{
	BTreeNode *bt1 = makeBTreeNode();
	BTreeNode *bt2 = makeBTreeNode();
	BTreeNode *bt3 = makeBTreeNode();
	BTreeNode *bt4 = makeBTreeNode();

	setData(bt1, 1);
	setData(bt2, 2);
	setData(bt3, 3);
	setData(bt4, 4);

	makeLeftSubTree(bt1, bt2);
	makeRightSubTree(bt1, bt3);
	makeLeftSubTree(bt2, bt4);

	printf("%d \n", getData(bt1));
	printf("%d \n", getData(getLeftSubTree(bt1)) );
	printf("%d \n", getData(getRightSubTree(bt1)) );
	printf("%d \n", getData(getLeftSubTree(getLeftSubTree(bt1))) );

	return 0;

}




BTreeNode* makeBTreeNode(void)
{
	BTreeNode *new = malloc(sizeof(BTreeNode));

	new->left = NULL;
	new->right = NULL;

	return new;
}

int getData(BTreeNode *bt) {
	return bt->data;
}

void setData(BTreeNode *bt, int data)
{
	bt->data = data;
}

BTreeNode* getLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}

BTreeNode* getRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

void makeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

void makeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}