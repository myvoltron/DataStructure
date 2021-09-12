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
int SisEmpty(STACK* s);
void push(STACK* s, char e);
char pop(STACK* s);
char seek(STACK* s);
void encode(char* str); //convert�ϱ� ���� ���ڿ��� ��ȯ�Ѵ�. 
void convert(char* str);
int isOperand(char s); //�ǿ��������� �ƴ��� �Ǵ�
int prio_oper(char s);

int main()
{
	int N = 0;
	int ptr_len = 0;
	char str[101];
	char* ptr = NULL;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		encode(str);
		convert(str);
		printf("\n");
	}
	/*
	A+(B*C-(D-F)+G)
	A*B+C-(D+E)*F
	A+B*C
	A/B-C+D*E-F*G
	A+(B*C+D)*E
	A&&B||C||!(E>F)
	*/
	return 0;
}

void initStack(STACK* s)
{
	//�ʱ�ȭ
	s->t = -1;
}
int SisEmpty(STACK* s)
{
	//����ִٸ� 1��ȯ �ƴϸ� 0��ȯ
	if (s->t == -1)
		return 1;
	else
		return 0;
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
char seek(STACK* s)
{
	if (s->t == -1)
	{
		printf("Stack Empty\n");
		return 1;
	}

	return s->stack[s->t];
}
void encode(char* str) //convert�ϱ� ���� ���ڿ��� ��ȯ�Ѵ�. 
{
	char* ptr;
	char* ptr_q;
	int str_len = strlen(str);

	if (*str == '+')
		*str = 'p';
	if (*str == '-')
		*str = 'm';
	for (ptr = str + 1; ptr < str + str_len; ptr++) // &&�� ||�� & |�� ���δ�.
	{
		if (*ptr == '|' || *ptr == '&')
		{
			for (ptr_q = ptr + 1; ptr_q < str + str_len; ptr_q++)
				*(ptr_q - 1) = *ptr_q; //�������� shift�ϸ鼭 �ű��

			*(ptr_q - 1) = '\0'; //���������� �ι��ڸ� �־��ش�. 
		}
	}
	for (ptr = str + 1; ptr < str + str_len; ptr++) //���׿������� +��-�� ������������ ��ȯ�ϱ� ���� p, m���� �ٲ۴�.
	{
		if (!isOperand(*(ptr - 1)) && *(ptr - 1) != ')')
		{
			if (*ptr == '+')
				*ptr = 'p';
			if (*ptr == '-')
				*ptr = 'm';
		}
	}
}
void convert(char* str)
{
	STACK S;
	char s; //str�� ���ڸ� ���� �ӽú���
	char tmp; //pop�Լ� ��ȯ���ڸ� ���� �ӽú��� 

	int str_len = strlen(str);

	int i, idx = 0;
	initStack(&S);

	for (i = 0; i < str_len; i++)
	{
		s = str[i];

		if (isOperand(s))
			printf("%c", s);
		else if (s == '(')
			push(&S, s);
		else if (s == ')')
		{
			while (seek(&S) != '(') // '('�� ã�� �� ���� pop�Ѵ�. 
			{
				tmp = pop(&S);
				if (tmp == '|' || tmp == '&') //�ش� ���ڵ��� ��½� 2���� ���
					printf("%c%c", tmp, tmp);
				else if (tmp == 'p') //p m�� + -�� ��ȯ�ؼ� ����Ѵ� 
					printf("+");
				else if (tmp == 'm')
					printf("-");
				else
					printf("%c", tmp);
			}
			tmp = pop(&S);
		}
		else //s�� �������϶�
		{
			while (!SisEmpty(&S) && (prio_oper(s) <= prio_oper(seek(&S))))
			{
				tmp = pop(&S);
				if (tmp == '|' || tmp == '&') //�ش� ���ڵ��� ��½� 2���� ���
					printf("%c%c", tmp, tmp);
				else if (tmp == 'p') //p m�� + -�� ��ȯ�ؼ� ����Ѵ� 
					printf("+");
				else if (tmp == 'm')
					printf("-");
				else
					printf("%c", tmp);
			}
			push(&S, s);
		}
	}
	while (!SisEmpty(&S))
	{
		tmp = pop(&S);
		if (tmp == '|' || tmp == '&') //�ش� ���ڵ��� ��½� 2���� ���
			printf("%c%c", tmp, tmp);
		else if (tmp == 'p') //p m�� + -�� ��ȯ�ؼ� ����Ѵ� 
			printf("+");
		else if (tmp == 'm')
			printf("-");
		else
			printf("%c", tmp);
	}
}
int isOperand(char s) //�ǿ��������� �ƴ��� �Ǵ�
{
	if ('A' <= s && 'Z' >= s)
		return 1;
	else
		return 0;
}
int prio_oper(char s) //������ �켱���� ��ȯ
{
	switch (s)
	{
	case '!':
	case 'p':
	case 'm':
		return 6;
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 4;
	case '>':
	case '<':
		return 3;
	case '&':
		return 2;
	case '|':
		return 1;
	}
	return -1;
}