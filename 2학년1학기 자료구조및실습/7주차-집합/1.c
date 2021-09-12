#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct simple_list_node
{
	int elem;
	struct simple_list_node* next;
} Node;
typedef struct simple_list
{
	Node* first_Node;
} List;

void init_list(List* plist);
void add_Node_first(Node* ptr, int e);
Node* add_Node(Node* ptr, int e);
void print_list(List* plist);
int member(List* plist, int e);
int subset(List* A, List* B);

int main()
{
	int A_size_N = 0, B_size_N = 0;
	int elem = 0;
	List A, B;
	Node* last_ptr = NULL;

	init_list(&A);
	init_list(&B);

	//input set
	scanf("%d", &A_size_N);
	last_ptr = A.first_Node;
	for (int i = 0; i < A_size_N; i++)
	{
		scanf("%d", &elem);
		if (i == 0)
		{
			add_Node_first(last_ptr, elem);
			continue;
		}
		last_ptr = add_Node(last_ptr, elem);
	}
	scanf("%d", &B_size_N);
	last_ptr = B.first_Node;
	for (int i = 0; i < B_size_N; i++)
	{
		scanf("%d", &elem);
		if (i == 0)
		{
			add_Node_first(last_ptr, elem);
			continue;
		}
		last_ptr = add_Node(last_ptr, elem);
	}

	printf("%d", subset(&A, &B));
	return 0;
	/*
	3
	4 6 13
	6
	1 3 4 6 8 13
	*/
}

void init_list(List* plist)
{
	plist->first_Node = (Node*)malloc(sizeof(Node));
}
void add_Node_first(Node* ptr, int e)
{
	ptr->elem = e;
}
Node* add_Node(Node* ptr, int e)
{
	Node* new_Node = (Node*)malloc(sizeof(Node));
	new_Node->elem = e;
	new_Node->next = NULL;
	ptr->next = new_Node;

	return new_Node;
}
void print_list(List* plist) //used by debugging
{
	Node* ptr = plist->first_Node;

	while (ptr != NULL)
	{
		printf("%d ", ptr->elem);
		ptr = ptr->next;
	}
	printf("\n");
}
int member(List* plist, int e)
{
	if (plist->first_Node == NULL)
		return 0;
	Node* ptr = plist->first_Node;
	int a = 0;

	while (1)
	{
		a = ptr->elem;
		if (a < e)
		{
			if (ptr->next == NULL)
				return 0;
			else
				ptr = ptr->next;
		}
		else if (a > e)
			return 0;
		else
			return 1;
	}
}
int subset(List* A, List* B)
{
	if (A->first_Node == NULL)
		return 0;
	Node* ptr = A->first_Node;

	while (1)
	{
		if (member(B, ptr->elem))
		{
			if (ptr->next == NULL)
				return 0;
			else
				ptr = ptr->next;
		}
		else
			return ptr->elem;
	}
}