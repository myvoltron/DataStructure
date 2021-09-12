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
void preorderPrint(treeNode* pNode);
void inorderTraver(treeNode* pNode, int ID);
void inorderPrint(treeNode* pNode);
void postorderTraver(treeNode* pNode, int ID);
void postorderPrint(treeNode* pNode);
void freeTreeNode(treeNode* pNode); //put treeRoot point

int main()
{
	int Num_traver = 0;
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

	scanf("%d %d", &Num_traver, &Num_id);
	if (Num_id < 9)
	{
		switch (Num_traver)
		{
		case 1:
			preorderTraver(treeRoot, Num_id);
			break;
		case 2:
			inorderTraver(treeRoot, Num_id);
			break;
		case 3:
			postorderTraver(treeRoot, Num_id);
			break;
		default:
			break;
		}
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
		preorderPrint(pNode);
		return;
	}

	if (pNode->left != NULL)
		preorderTraver(pNode->left, ID);
	if (pNode->right != NULL)
		preorderTraver(pNode->right, ID);
}
void inorderTraver(treeNode* pNode, int ID)
{
	if (pNode->left != NULL)
		inorderTraver(pNode->left, ID);
	if (pNode->id == ID)
	{
		inorderPrint(pNode);
		return;
	}
	if (pNode->right != NULL)
		inorderTraver(pNode->right, ID);
}
void postorderTraver(treeNode* pNode, int ID)
{
	if (pNode->left != NULL)
		postorderTraver(pNode->left, ID);
	if (pNode->right != NULL)
		postorderTraver(pNode->right, ID);
	if (pNode->id == ID)
	{
		postorderPrint(pNode);
		return;
	}
}

void preorderPrint(treeNode* pNode)
{
	printf(" %d", pNode->data);
	if (pNode->left != NULL)
		preorderPrint(pNode->left);
	if (pNode->right != NULL)
		preorderPrint(pNode->right);
}
void inorderPrint(treeNode* pNode)
{
	if (pNode->left != NULL)
		inorderPrint(pNode->left);
	printf(" %d", pNode->data);
	if (pNode->right != NULL)
		inorderPrint(pNode->right);
}
void postorderPrint(treeNode* pNode)
{
	if (pNode->left != NULL)
		postorderPrint(pNode->left);
	if (pNode->right != NULL)
		postorderPrint(pNode->right);
	printf(" %d", pNode->data);
}

void freeTreeNode(treeNode* pNode)
{
	if (pNode->left != NULL)
		freeTreeNode(pNode->left);
	if (pNode->right != NULL)
		freeTreeNode(pNode->right);
	free(pNode);
}