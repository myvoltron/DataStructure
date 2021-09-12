#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct Node
{
	struct Node* next;
	struct Node* prev;
	int elem;
} Node;
typedef struct
{
	Node* front;
	Node* rear;
} DEQUE;

void initDeque(DEQUE* deque);
void add_front(DEQUE* deque, int v);
void add_rear(DEQUE* deque, int v);
int delete_front(DEQUE* deque);
int delete_rear(DEQUE* deque);
void print_deque(DEQUE* deque);

int EmptyDeque(DEQUE* deque);
void free_Deque(DEQUE* deque);

/*
7
AF 10
AF 20
AR 30
P
DF
DR
P
*/
int main()
{
	int n = 0;
	char oper[5];

	int value = 0; //�߰��� ���Ҹ� �����ϴ� ����
	int tmp = 0;   //��ȯ���� ������ ����

	//�� �ʱ�ȭ 
	DEQUE deque;
	initDeque(&deque);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", oper);

		if (!strcmp(oper, "AF"))
		{
			scanf("%d", &value);
			add_front(&deque, value);
		}
		else if (!strcmp(oper, "AR"))
		{
			scanf("%d", &value);
			add_rear(&deque, value);
		}
		else if (!strcmp(oper, "DF"))
		{
			tmp = delete_front(&deque);
		}
		else if (!strcmp(oper, "DR"))
		{
			tmp = delete_rear(&deque);
		}
		else if (!strcmp(oper, "P"))
		{
			print_deque(&deque);
		}
		else
			continue;
	}

	//�Ҵ����� 
	free_Deque(&deque);
	return 0;
}

void initDeque(DEQUE* deque)
{
	deque->front = NULL;
	deque->rear = NULL;
}
void add_front(DEQUE* deque, int v)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->elem = v;
	newNode->next = deque->front;

	if (EmptyDeque(deque))               //����ִ��Ŷ�� rear�� newNode�� ���ϰ� ����.
		deque->rear = newNode;
	else
		deque->front->prev = newNode;    //������� �ʾҴٸ� front�� ���ϴ� ����� ������带 newNode�� ���� 

	newNode->prev = NULL;                //newNode�� �������� �翬�� NULL
	deque->front = newNode;              //���������� front�� newNode�� ���ϰ� ������. 
}
void add_rear(DEQUE* deque, int v)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->elem = v;

	newNode->prev = deque->rear;

	if (EmptyDeque(deque))
		deque->front = newNode;
	else
		deque->rear->next = newNode;

	newNode->next = NULL;
	deque->rear = newNode;
}
int delete_front(DEQUE* deque)
{
	Node* ptr = deque->front;
	int tmp = 0;

	if (EmptyDeque(deque)) //����ִ� ��� ���� �߷�
	{
		printf("underflow");
		//�Ҵ����� �� ���α׷� ���� 
		free_Deque(deque);
		exit(1);
	}

	tmp = ptr->elem;

	deque->front = deque->front->next;
	free(ptr);

	if (deque->front == NULL) //�ʱ�ȭ ���·� �ǵ��ư�
		deque->rear = NULL;
	else
		deque->front->prev = NULL;

	return tmp;
}
int delete_rear(DEQUE* deque)
{
	Node* ptr = deque->rear;
	int tmp = 0;

	if (EmptyDeque(deque)) //����ִ� ��� ���� �߷�
	{
		printf("underflow");
		//�Ҵ����� �� ���α׷� ���� 
		free_Deque(deque);
		exit(1);
	}

	tmp = ptr->elem;

	deque->rear = deque->rear->prev;
	free(ptr);

	if (deque->rear == NULL) //�ʱ�ȭ ���·� �ǵ��ư�
		deque->front = NULL;
	else
		deque->rear->next = NULL;

	return tmp;
}
void print_deque(DEQUE* deque) //��� ���� ��� 
{
	Node* ptr = deque->front;

	while (ptr)                //NULL���� ���� while�� ����� �ȴ�. 
	{
		printf(" %d", ptr->elem);
		ptr = ptr->next;
	}
	printf("\n");
}

int EmptyDeque(DEQUE* deque)
{
	if (deque->front == NULL) //����ٸ� 1 ��ȯ 
		return 1;
	return 0;
}
void free_Deque(DEQUE* deque)  //�Ҵ����� �Լ� 
{
	Node* ptr = deque->front;
	Node* pnext = NULL;

	while (1)
	{
		if (ptr == NULL)
			break;
		pnext = ptr->next;    //���� ptr�� next�� �����ϰ�
		free(ptr);            //ptr �޸� �Ҵ� ����
		ptr = pnext;          //�ٽ� ptr�� pnext�� ����
	}
}