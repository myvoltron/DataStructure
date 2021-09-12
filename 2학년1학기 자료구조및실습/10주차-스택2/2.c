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
int isOperand(char s); //피연산자인지 아닌지 판단
void evaluate(char* str); //파라미터로 받은 문자열로 계산결과를 반환한다.
char doOperator(char op, char x, char y); //연산자와 피연산자로 계산한다. 

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
	//초기화
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
int isOperand(char s) //피연산자인지 아닌지 판단
{
	if ('0' <= s && '9' >= s)
		return 1;
	else
		return 0;
}
void evaluate(char* str)
{
	int str_len = strlen(str);
	char s; //str문자열의 문자를 저장하는 임시변수 
	char a, b; //숫자문자를 받아두는 임시변수 

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
			push(&S, doOperator(s, b, a)); //계산결과를 스택에 넣는다. 
		}
	}
	printf("%d", pop(&S) - '0'); //마지막 결과를 출력한다.
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
