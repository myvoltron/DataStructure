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
void encode(char* str); //convert하기 쉽게 문자열을 변환한다. 
void convert(char* str);
int isOperand(char s); //피연산자인지 아닌지 판단
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
	//초기화
	s->t = -1;
}
int SisEmpty(STACK* s)
{
	//비어있다면 1반환 아니면 0반환
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
void encode(char* str) //convert하기 쉽게 문자열을 변환한다. 
{
	char* ptr;
	char* ptr_q;
	int str_len = strlen(str);

	if (*str == '+')
		*str = 'p';
	if (*str == '-')
		*str = 'm';
	for (ptr = str + 1; ptr < str + str_len; ptr++) // &&나 ||를 & |로 줄인다.
	{
		if (*ptr == '|' || *ptr == '&')
		{
			for (ptr_q = ptr + 1; ptr_q < str + str_len; ptr_q++)
				*(ptr_q - 1) = *ptr_q; //왼쪽으로 shift하면서 옮긴다

			*(ptr_q - 1) = '\0'; //마지막에는 널문자를 넣어준다. 
		}
	}
	for (ptr = str + 1; ptr < str + str_len; ptr++) //단항연산자인 +와-를 후위계산식으로 변환하기 쉽게 p, m으로 바꾼다.
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
	char s; //str의 문자를 받을 임시변수
	char tmp; //pop함수 반환문자를 받을 임시변수 

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
			while (seek(&S) != '(') // '('를 찾을 떄 까지 pop한다. 
			{
				tmp = pop(&S);
				if (tmp == '|' || tmp == '&') //해당 문자들은 출력시 2개씩 출력
					printf("%c%c", tmp, tmp);
				else if (tmp == 'p') //p m은 + -로 변환해서 출력한다 
					printf("+");
				else if (tmp == 'm')
					printf("-");
				else
					printf("%c", tmp);
			}
			tmp = pop(&S);
		}
		else //s가 연산자일때
		{
			while (!SisEmpty(&S) && (prio_oper(s) <= prio_oper(seek(&S))))
			{
				tmp = pop(&S);
				if (tmp == '|' || tmp == '&') //해당 문자들은 출력시 2개씩 출력
					printf("%c%c", tmp, tmp);
				else if (tmp == 'p') //p m은 + -로 변환해서 출력한다 
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
		if (tmp == '|' || tmp == '&') //해당 문자들은 출력시 2개씩 출력
			printf("%c%c", tmp, tmp);
		else if (tmp == 'p') //p m은 + -로 변환해서 출력한다 
			printf("+");
		else if (tmp == 'm')
			printf("-");
		else
			printf("%c", tmp);
	}
}
int isOperand(char s) //피연산자인지 아닌지 판단
{
	if ('A' <= s && 'Z' >= s)
		return 1;
	else
		return 0;
}
int prio_oper(char s) //연산자 우선순위 반환
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