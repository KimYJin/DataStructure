
#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}BTreeNode;

typedef int BTData;

BTreeNode* MakeBTreeNode(void);

BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode *bt);
BTreeNode* GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

void DeleteTree(BTreeNode* bt);

#endif