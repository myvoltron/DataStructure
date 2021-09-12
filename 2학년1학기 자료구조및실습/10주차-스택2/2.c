#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct stack
{
	char stack[101];
	int t;
} STACK;

void initStack(STACK* s);
void push(STACK* s, char e);
char pop(STACK* s);
int isOperand(char s); //�ǿ��������� �ƴ��� �Ǵ�
void evaluate(char* str); //�Ķ���ͷ� ���� ���ڿ��� ������� ��ȯ�Ѵ�.
char doOperator(char op, char x, char y); //�����ڿ� �ǿ����ڷ� ����Ѵ�. 

int main()
{
	int N = 0, ptr_len = 0;
	char str[101];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		evaluate(str);
		printf("\n");
	}
	return 0;
}

void initStack(STACK* s)
{
	//�ʱ�ȭ
	s->t = -1;
}
void push(STACK* s, char e)
{
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
int isOperand(char s) //�ǿ��������� �ƴ��� �Ǵ�
{
	if ('0' <= s && '9' >= s)
		return 1;
	else
		return 0;
}
void evaluate(char* str)
{
	int str_len = strlen(str);
	char s; //str���ڿ��� ���ڸ� �����ϴ� �ӽú��� 
	char a, b; //���ڹ��ڸ� �޾Ƶδ� �ӽú��� 

	STACK S;
	initStack(&S);

	for (int i = 0; i < str_len; i++)
	{
		s = str[i];
		if (isOperand(s))
			push(&S, s);
		else // s is an operator 
		{
			a = pop(&S);
			b = pop(&S);
			push(&S, doOperator(s, b, a)); //������� ���ÿ� �ִ´�. 
		}
	}
	printf("%d", pop(&S) - '0'); //������ ����� ����Ѵ�.
}
char doOperator(char op, char x, char y)
{
	switch (op)
	{
	case '+':
		return ((x - '0') + (y - '0')) + '0';
	case '-':
		return ((x - '0') - (y - '0')) + '0';
	case '*':
		return ((x - '0') * (y - '0')) + '0';
	case '/':
		return ((x - '0') / (y - '0')) + '0';
	}
	return 0;
}
