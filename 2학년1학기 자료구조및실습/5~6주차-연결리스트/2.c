#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct simple_list_Node
{
	int coef;
	int exp;
	struct simple_list_Node* next;
} Node;
typedef struct simple_list
{
	Node* header;
} List;

void init_list(List* plist); //initialize the list
void free_list(List* plist); //�Ҵ�����
Node* append_list(Node* k, int c, int e); //���׽Ŀ� �� �߰�
List addPoly(List* list1, List* list2); //���׽ĳ��� ���ϰ� ��ȯ
void print_list(List* plist); //���Ḯ��Ʈ ���

int main()
{
	List list[3];
	List* ptr = NULL;
	Node* lastOflist = NULL;
	int coef, exp;
	int n = 0;

	//���׽� �ʱ�ȭ
	for (ptr = list; ptr < list + 3; ptr++)
		init_list(ptr);

	//���׽��Է�
	scanf("%d", &n);
	lastOflist = list[0].header;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &coef, &exp);
		lastOflist = append_list(lastOflist, coef, exp);
	}
	scanf("%d", &n);
	lastOflist = list[1].header;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &coef, &exp);
		lastOflist = append_list(lastOflist, coef, exp);
	}

	//���׽� ���� ��� ��� 
	list[2] = addPoly(&list[0], &list[1]);
	print_list(&list[2]);

	//���Ḯ��Ʈ �Ҵ�����
	for (ptr = list; ptr < list + 3; ptr++)
		free_list(ptr);
	return 0;
}

void init_list(List* plist) //initialize the list
{
	plist->header = (Node*)malloc(sizeof(Node));
}
void free_list(List* plist) //�Ҵ�����
{
	Node* ptr = plist->header;
	Node* save = NULL;

	while (ptr != NULL)
	{
		save = ptr->next;
		free(ptr);
		ptr = save;
	}
}
Node* append_list(Node* k, int c, int e) //���׽Ŀ� �� �߰�
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->coef = c;
	node->exp = e;
	node->next = NULL;
	k->next = node;
	k = node;
	return k;
}
List addPoly(List* list1, List* list2) //���׽ĳ��� ���ϰ� ��ȯ
{
	List result;
	Node* i = list1->header->next;
	Node* j = list2->header->next;
	Node* k = NULL;
	int sum = 0;

	result.header = (Node*)malloc(sizeof(Node));
	k = result.header;

	while ((i != NULL) && (j != NULL))
	{
		if (i->exp > j->exp)
		{
			k = append_list(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp)
		{
			k = append_list(k, j->coef, j->exp);
			j = j->next;
		}
		else
		{
			sum = i->coef + j->coef;
			if (sum != 0)
				k = append_list(k, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}

	while (i != NULL)
	{
		k = append_list(k, i->coef, i->exp);
		i = i->next;
	}

	while (j != NULL)
	{
		k = append_list(k, j->coef, j->exp);
		j = j->next;
	}

	return result;
}
void print_list(List* plist) //���Ḯ��Ʈ ���
{
	Node* ptr_node = plist->header->next;

	while (ptr_node != NULL)
	{
		printf(" %d %d", ptr_node->coef, ptr_node->exp);
		ptr_node = ptr_node->next;
	}
	printf("\n");
}

/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0
*/