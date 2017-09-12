#include<stdio.h>
#include<stdlib.h>
#include"BTreeTraverse.h"

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;


	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);

}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data, action);
}

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode *new = malloc(sizeof(BTreeNode));

	new->left = NULL;
	new->right = NULL;

	return new;
}

int GetData(BTreeNode *bt) {
	return bt->data;
}

void SetData(BTreeNode *bt, int data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}

void DeleteTree(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	if (bt->left != NULL)
		DeleteTree(bt->left);

	if (bt->right != NULL)
		DeleteTree(bt->right);

	printf("delete tree data: %d \n", bt->data);
	free(bt);
}