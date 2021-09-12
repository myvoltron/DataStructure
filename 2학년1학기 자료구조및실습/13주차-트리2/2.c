#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct _treenode
{
	struct _treenode* left;
	struct _treenode* right;
	int data; //folder's size
	int id; //folder's ID
} treeNode;

treeNode* makeNode(int ID, int d);
void setTreeLeftChild(treeNode* root, treeNode* chi);
void setTreeRightChild(treeNode* root, treeNode* chi);
void preorderTraver(treeNode* pNode, int ID);
int preorderCalculate(treeNode* pNode);
void freeTreeNode(treeNode* pNode); //put treeRoot point

int main()
{
	int Num_id = 0;

	//create each treeNode
	treeNode* treeRoot = makeNode(1, 20); //treeRood's address pointer
	treeNode* T2 = makeNode(2, 30);
	treeNode* T3 = makeNode(3, 50);
	treeNode* T4 = makeNode(4, 70);
	treeNode* T5 = makeNode(5, 90);
	treeNode* T6 = makeNode(6, 120);
	treeNode* T7 = makeNode(7, 130);
	treeNode* T8 = makeNode(8, 80);

	//link each treeNode
	setTreeLeftChild(treeRoot, T2);
	setTreeRightChild(treeRoot, T3);
	setTreeLeftChild(T2, T4);
	setTreeRightChild(T2, T5);
	setTreeRightChild(T3, T6);
	setTreeLeftChild(T6, T7);
	setTreeRightChild(T6, T8);

	scanf("%d", &Num_id);
	if (Num_id < 9)
	{
		preorderTraver(treeRoot, Num_id);
	}
	else
	{
		printf("-1\n");
	}

	freeTreeNode(treeRoot);
	return 0;
}

treeNode* makeNode(int ID, int d)
{
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->data = d;
	newNode->id = ID;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
void setTreeLeftChild(treeNode* root, treeNode* chi) //set child 
{
	root->left = chi;
}
void setTreeRightChild(treeNode* root, treeNode* chi)
{
	root->right = chi;
}

void preorderTraver(treeNode* pNode, int ID)
{
	if (pNode->id == ID)
	{
		printf("%d\n", preorderCalculate(pNode));
	}
	if (pNode->left != NULL)
		preorderTraver(pNode->left, ID);
	if (pNode->right != NULL)
		preorderTraver(pNode->right, ID);
}
int preorderCalculate(treeNode* pNode)
{
	if (pNode->left == NULL && pNode->right == NULL)
		return pNode->data;

	if (pNode->left != NULL && pNode->right == NULL)
		return pNode->data + preorderCalculate(pNode->left);
	else if (pNode->right != NULL && pNode->left == NULL)
		return pNode->data + preorderCalculate(pNode->right);
	else
		return pNode->data + preorderCalculate(pNode->left) + preorderCalculate(pNode->right);
}


void freeTreeNode(treeNode* pNode)
{
	if (pNode->left != NULL)
		freeTreeNode(pNode->left);
	if (pNode->right != NULL)
		freeTreeNode(pNode->right);
	free(pNode);
}