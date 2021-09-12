#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct _treenode
{
	int data;
	struct _treenode* left;
	struct _treenode* right;
} TreeNode;

TreeNode* makeNode(int data, TreeNode* leftC, TreeNode* rightC);
void printSubTree(TreeNode* pf[], int n);

int main()
{
	//�Է��� ��� ��ȣ�� ������ ���� 
	int nodeNumber = 0;

	//Ʈ�� ���� ���� 
	TreeNode* F7 = makeNode(130, NULL, NULL);
	TreeNode* F8 = makeNode(80, NULL, NULL);
	TreeNode* F6 = makeNode(120, F7, F8);
	TreeNode* F3 = makeNode(50, NULL, F6);
	TreeNode* F4 = makeNode(70, NULL, NULL);
	TreeNode* F5 = makeNode(90, NULL, NULL);
	TreeNode* F2 = makeNode(30, F4, F5);
	TreeNode* F1 = makeNode(20, F2, F3);

	//Ʈ����带 ����Ű�� �����͵��� �迭 
	TreeNode* PFile[9] = { 0, F1, F2, F3, F4, F5, F6, F7, F8 };

	//�Է� 
	scanf("%d", &nodeNumber);
	if (nodeNumber > 0 && nodeNumber < 9)
		printSubTree(PFile, nodeNumber);
	else
		printf("-1");
	return 0;
}

TreeNode* makeNode(int d, TreeNode* leftC, TreeNode* rightC)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = d;
	if (leftC != NULL)
		newNode->left = leftC;
	else
		newNode->left = NULL;

	if (rightC != NULL)
		newNode->right = rightC;
	else
		newNode->right = NULL;

	return newNode;
}
void printSubTree(TreeNode* pf[], int n)
{
	TreeNode* pNode = pf[n];

	if (pNode->left == NULL || pNode->right == NULL)
	{
		if (pNode->left != NULL) //�����ڽĸ� ����
			printf("%d %d", pNode->data, pNode->left->data);
		else if (pNode->right != NULL) //�������ڽĸ� ����
			printf("%d %d", pNode->data, pNode->right->data);
		else //�ڽ� ��� ��� �������� ���� 
			printf("%d", pNode->data);
	}
	else //�ڽ� ��� ��� ���� 
	{
		printf("%d %d %d", pNode->data, pNode->left->data, pNode->right->data);
	}
}
