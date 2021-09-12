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

	int value = 0; //추가할 원소를 저장하는 변수
	int tmp = 0;   //반환값을 저장할 변수

	//덱 초기화 
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

	//할당해제 
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

	if (EmptyDeque(deque))               //비어있던거라면 rear도 newNode를 향하게 설정.
		deque->rear = newNode;
	else
		deque->front->prev = newNode;    //비어있지 않았다면 front가 향하는 노드의 이전노드를 newNode로 설정 

	newNode->prev = NULL;                //newNode의 이전노드는 당연히 NULL
	deque->front = newNode;              //마지막으로 front가 newNode를 향하게 설정함. 
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

	if (EmptyDeque(deque)) //비어있는 경우 에러 발령
	{
		printf("underflow");
		//할당해제 후 프로그램 종료 
		free_Deque(deque);
		exit(1);
	}

	tmp = ptr->elem;

	deque->front = deque->front->next;
	free(ptr);

	if (deque->front == NULL) //초기화 상태로 되돌아감
		deque->rear = NULL;
	else
		deque->front->prev = NULL;

	return tmp;
}
int delete_rear(DEQUE* deque)
{
	Node* ptr = deque->rear;
	int tmp = 0;

	if (EmptyDeque(deque)) //비어있는 경우 에러 발령
	{
		printf("underflow");
		//할당해제 후 프로그램 종료 
		free_Deque(deque);
		exit(1);
	}

	tmp = ptr->elem;

	deque->rear = deque->rear->prev;
	free(ptr);

	if (deque->rear == NULL) //초기화 상태로 되돌아감
		deque->front = NULL;
	else
		deque->rear->next = NULL;

	return tmp;
}
void print_deque(DEQUE* deque) //모든 원소 출력 
{
	Node* ptr = deque->front;

	while (ptr)                //NULL값이 오면 while을 벗어나게 된다. 
	{
		printf(" %d", ptr->elem);
		ptr = ptr->next;
	}
	printf("\n");
}

int EmptyDeque(DEQUE* deque)
{
	if (deque->front == NULL) //비었다면 1 반환 
		return 1;
	return 0;
}
void free_Deque(DEQUE* deque)  //할당해제 함수 
{
	Node* ptr = deque->front;
	Node* pnext = NULL;

	while (1)
	{
		if (ptr == NULL)
			break;
		pnext = ptr->next;    //먼저 ptr의 next를 저장하고
		free(ptr);            //ptr 메모리 할당 해제
		ptr = pnext;          //다시 ptr에 pnext를 대입
	}
}