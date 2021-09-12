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
	Node* header;
} List;

void init_list(List* plist);
Node* add_Node(Node* ptr, int e);
void print_list(List* plist);
Node* union_list(Node* A, Node* B);
Node* intersect_list(Node* A, Node* B);

int main()
{
	int A_size_N = 0, B_size_N = 0;
	int elem = 0;
	List A, B;
	List result_union, result_inter;
	Node* last_ptr = NULL;

	//initialize
	init_list(&A);
	init_list(&B);
	init_list(&result_union);
	init_list(&result_inter);

	//input set
	scanf("%d", &A_size_N);
	last_ptr = A.header;
	for (int i = 0; i < A_size_N; i++)
	{
		scanf("%d", &elem);
		last_ptr = add_Node(last_ptr, elem);
	}
	scanf("%d", &B_size_N);
	last_ptr = B.header;
	for (int i = 0; i < B_size_N; i++)
	{
		scanf("%d", &elem);
		last_ptr = add_Node(last_ptr, elem);
	}

	result_union.header->next = union_list(A.header->next, B.header->next);
	result_inter.header->next = intersect_list(A.header->next, B.header->next);
	print_list(&result_union);
	printf("\n");
	print_list(&result_inter);
	return 0;
	/*
	6
	3 7 45 88 99 101
	4
	7 10 15 45
	*/
}

void init_list(List* plist)
{
	plist->header = (Node*)malloc(sizeof(Node));
}
Node* add_Node(Node* ptr, int e)
{
	Node* new_Node = (Node*)malloc(sizeof(Node));
	new_Node->elem = e;
	new_Node->next = NULL;
	ptr->next = new_Node;
	return new_Node;
}
void print_list(List* plist)
{
	Node* ptr = plist->header->next;

	if (ptr == NULL)
	{
		printf("0\n");
		return;
	}

	while (ptr != NULL)
	{
		printf(" %d", ptr->elem);
		ptr = ptr->next;
	}
}
Node* union_list(Node* A, Node* B)
{
	if (A == NULL && B == NULL)
		return NULL;

	Node* new_Node = (Node*)malloc(sizeof(Node));

	if (A == NULL)
	{
		new_Node->elem = B->elem;
		new_Node->next = union_list(A, B->next);
	}
	else if (B == NULL)
	{
		new_Node->elem = A->elem;
		new_Node->next = union_list(A->next, B);
	}
	else
	{
		if (A->elem < B->elem)
		{
			new_Node->elem = A->elem;
			new_Node->next = union_list(A->next, B);
		}
		else if (A->elem > B->elem)
		{
			new_Node->elem = B->elem;
			new_Node->next = union_list(A, B->next);
		}
		else
		{
			new_Node->elem = A->elem;
			new_Node->next = union_list(A->next, B->next);
		}
	}

	return new_Node;
}
Node* intersect_list(Node* A, Node* B)
{
	if (A == NULL || B == NULL)
	{
		return NULL;
	}

	if (A->elem < B->elem)
	{
		return intersect_list(A->next, B);
	}
	else if (A->elem > B->elem)
	{
		return intersect_list(A, B->next);
	}
	else
	{
		Node* new_Node = (Node*)malloc(sizeof(Node));
		new_Node->elem = A->elem;
		new_Node->next = intersect_list(A->next, B->next);
		return new_Node;
	}
}