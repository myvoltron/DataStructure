#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct stack
{
	char* stack;
	int stack_N;
	int t;
} STACK;

void initStack(STACK* s, int N);
void push(STACK* s, char e);
char pop(STACK* s);
char peek(STACK* s);
void duplicate(STACK* s);
void upRotate(STACK* s, int n);
void downRotate(STACK* s, int n);
void print(STACK* s);

int main()
{
	int stack_N = 0;
	int oper_N = 0;
	int rotate_N = 0;
	char oper[10], elem;
	char return_elem;
	STACK stack;

	scanf("%d", &stack_N);
	initStack(&stack, stack_N); //������ ũ�� N�� �ް� ���� �ʱ�ȭ
	scanf("%d", &oper_N);		//��ɾ��� ����
	/*
	4
	10
	PUSH s
	PUSH t
	PUSH a
	PRINT
	*/
	for (int i = 0; i < oper_N; i++)
	{
		scanf("%s", oper); //��ɾ� �Է� 

		if (!strcmp("POP", oper))
		{
			return_elem = pop(&stack);
		}
		else if (!strcmp("PUSH", oper))
		{
			getchar();
			scanf("%c", &elem);
			push(&stack, elem);
		}
		else if (!strcmp("PEEK", oper))
		{
			return_elem = peek(&stack);
			printf("%c", return_elem);
		}
		else if (!strcmp("DUP", oper))
		{
			duplicate(&stack);
		}
		else if (!strcmp("UpR", oper))
		{
			scanf("%d", &rotate_N);
			upRotate(&stack, rotate_N);
		}
		else if (!strcmp("DownR", oper))
		{
			scanf("%d", &rotate_N);
			downRotate(&stack, rotate_N);
		}
		else if (!strcmp("PRINT", oper))
		{
			print(&stack);
		}
	}

	free(stack.stack); //�Ҵ�����
	return 0;
}

void initStack(STACK* s, int N)
{
	//�ʱ�ȭ
	s->stack_N = N;
	s->t = -1;
	s->stack = (char*)malloc(sizeof(char) * (s->stack_N));
}
void push(STACK* s, char e)
{
	if (s->t == s->stack_N - 1)
	{
		printf("Stack FULL\n");
		return;
	}

	s->t = s->t + 1;
	s->stack[s->t] = e;
}
char pop(STACK* s)
{
	if (s->t == -1)
	{
		printf("Stack Empty\n");
		return 1;
	}

	s->t = s->t - 1;
	return s->stack[s->t + 1];
}
char peek(STACK* s)
{
	if (s->t == -1)
	{
		printf("Stack Empty\n");
		return 1;
	}

	return s->stack[s->t];
}
void duplicate(STACK* s)
{
	if (s->t == s->stack_N - 1)
	{
		printf("Stack FULL\n");
		return;
	}

	char e = pop(s);
	for (int i = 0; i < 2; i++)
	{
		if (s->t == s->stack_N - 1)
		{
			printf("Stack FULL\n");
			return;
		}

		push(s, e);
	}
}
void upRotate(STACK* s, int n)
{
	if (n > s->t + 1)
		return;

	char save;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		save = s->stack[s->t - n + 1];
		for (j = s->t - n + 1; j <= s->t - 1; j++)
			s->stack[j] = s->stack[j + 1];
		s->stack[s->t] = save;
	}
}
void downRotate(STACK* s, int n)
{
	if (n > s->t + 1)
		return;

	char save;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		save = s->stack[s->t];
		for (j = s->t; j > s->t - n + 1; j--)
			s->stack[j] = s->stack[j - 1];
		s->stack[s->t - n + 1] = save;
	}
}
void print(STACK* s)
{
	if (s->t == -1)
	{
		return;
	}

	for (int i = s->t; i >= 0; i--)
		printf("%c", s->stack[i]);
	printf("\n");
}