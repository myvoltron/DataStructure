#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct
{
	int* ptr_queue; //�迭�� ������ ������ ����
	int r, f;       //������ �Ӹ�
	int N;          //�迭�� ũ�� 
} QUEUE;

void initQueue(QUEUE* q, int n);
void insertQueue(QUEUE* q, int v); //overflow ó��
int deleteQueue(QUEUE* q);        //underflow ó��
void printQueue(QUEUE* q);
void freeQueue(QUEUE* q);

int QueueEmpty(QUEUE* q);
int QueueFull(QUEUE* q);

int main()
{
	int q = 0; //ť�� ũ�⸦ �����ϴ� ����
	int n = 0; //������ ������ �����ϴ� ����
	QUEUE queue;

	char oper;     //������ ����
	int value = 0; //ť�� ������ ����
	int tmp = 0;   //ť���� ��ȯ�� �� ����

	//�ʱ�ȭ
	scanf("%d", &q);
	initQueue(&queue, q);

	//���� ���� 
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &oper);
		getchar();

		switch (oper)
		{
		case 'I':
			//����
			scanf("%d", &value);
			getchar();
			insertQueue(&queue, value);
			break;
		case 'D':
			//���� �� �ش� ���� ���� 0���� ġȯ
			tmp = deleteQueue(&queue);
			break;
		case 'P':
			//�迭 ���� ��ü�� ���ʷ� ȭ�鿡 ��� 
			printQueue(&queue);
			break;
		}
	}

	//�Ҵ����� 
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

	//�迭�� ��� ���� 0���� �ʱ�ȭ
	for (ptr = q->ptr_queue; ptr < q->ptr_queue + q->N; ptr++)
		*ptr = 0;
}
void insertQueue(QUEUE* q, int v) //overflow ó��
{
	if (QueueFull(q)) //ť�� ������ ��� 
	{
		printf("overflow");
		printQueue(q);

		freeQueue(q); //�Ҵ����� �� ���α׷� ����
		exit(1);
	}

	q->r = (q->r + 1) % q->N;
	q->ptr_queue[q->r] = v;
}
int deleteQueue(QUEUE* q)        //underflow ó��
{
	if (QueueEmpty(q)) //ť�� ����ִ� ���
	{
		printf("underflow\n");

		freeQueue(q); //�Ҵ����� �� ���α׷� ����
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
void freeQueue(QUEUE* q) //�Ҵ�����
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