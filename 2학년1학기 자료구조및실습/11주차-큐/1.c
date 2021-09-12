#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct
{
	int* ptr_queue; //배열을 저장할 포인터 변수
	int r, f;       //꼬리와 머리
	int N;          //배열의 크기 
} QUEUE;

void initQueue(QUEUE* q, int n);
void insertQueue(QUEUE* q, int v); //overflow 처리
int deleteQueue(QUEUE* q);        //underflow 처리
void printQueue(QUEUE* q);
void freeQueue(QUEUE* q);

int QueueEmpty(QUEUE* q);
int QueueFull(QUEUE* q);

int main()
{
	int q = 0; //큐의 크기를 저장하는 변수
	int n = 0; //연산의 개수를 저장하는 변수
	QUEUE queue;

	char oper;     //연산의 종류
	int value = 0; //큐에 저장할 변수
	int tmp = 0;   //큐에서 반환된 값 저장

	//초기화
	scanf("%d", &q);
	initQueue(&queue, q);

	//연산 시작 
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &oper);
		getchar();

		switch (oper)
		{
		case 'I':
			//삽입
			scanf("%d", &value);
			getchar();
			insertQueue(&queue, value);
			break;
		case 'D':
			//삭제 후 해당 원소 값을 0으로 치환
			tmp = deleteQueue(&queue);
			break;
		case 'P':
			//배열 원소 전체를 차례로 화면에 출력 
			printQueue(&queue);
			break;
		}
	}

	//할당해제 
	freeQueue(&queue);
	return 0;
}

void initQueue(QUEUE* q, int n)
{
	int* ptr = NULL;

	q->N = n;
	q->ptr_queue = (int*)malloc(sizeof(int) * q->N);
	q->f = 0;
	q->r = 0;

	//배열을 모두 정수 0으로 초기화
	for (ptr = q->ptr_queue; ptr < q->ptr_queue + q->N; ptr++)
		*ptr = 0;
}
void insertQueue(QUEUE* q, int v) //overflow 처리
{
	if (QueueFull(q)) //큐가 만원인 경우 
	{
		printf("overflow");
		printQueue(q);

		freeQueue(q); //할당해제 후 프로그램 종료
		exit(1);
	}

	q->r = (q->r + 1) % q->N;
	q->ptr_queue[q->r] = v;
}
int deleteQueue(QUEUE* q)        //underflow 처리
{
	if (QueueEmpty(q)) //큐가 비어있는 경우
	{
		printf("underflow\n");

		freeQueue(q); //할당해제 후 프로그램 종료
		exit(1);
	}

	int value;
	q->f = (q->f + 1) % q->N;
	value = q->ptr_queue[q->f];
	q->ptr_queue[q->f] = 0;
	return value;
}
void printQueue(QUEUE* q)
{
	int* ptr = NULL;

	for (ptr = q->ptr_queue; ptr < q->ptr_queue + q->N; ptr++)
		printf(" %d", *ptr);
	printf("\n");
}
void freeQueue(QUEUE* q) //할당해제
{
	free(q->ptr_queue);
}

int QueueEmpty(QUEUE* q)
{
	if (q->r == q->f)
		return 1;
	return 0;
}
int QueueFull(QUEUE* q)
{
	if ((q->r + 1) % q->N == q->f)
		return 1;
	return 0;
}

/*
6
10
I 10
I 20
P
I 30
I 40
D
P
I 50
I 60
I 70
*/