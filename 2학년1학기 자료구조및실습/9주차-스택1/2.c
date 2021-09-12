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
void isBalanced(char* str);
void make_str(int TorF, int N);
int same_symbol(char a, char b);

int main()
{
	char str[1001];

	gets(str);
	isBalanced(str);
	return 0;
}

void initStack(STACK* s, int N)
{
	//초기화
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
void isBalanced(char* str)
{
	STACK stack;
	int str_len = strlen(str);
	int i = 0;
	int symbol_N = 0;
	int TORF = 0;
	char symbol;
	char save;
	initStack(&stack, 1000);

	for (i = 0; i < str_len; i++)
	{
		symbol = str[i];

		if (symbol == '(' || symbol == '{' || symbol == '[')
		{
			symbol_N++;
			push(&stack, symbol);
		}
		else if (symbol == ')' || symbol == '}' || symbol == ']')
		{
			symbol_N++;
			if (stack.t == -1) //스택에 아무것도 없는데 닫는 괄호가 옴
			{
				TORF++;
				continue;
			}

			save = pop(&stack);
			if (!same_symbol(save, symbol)) //괄호종류가 같지 않을때
			{
				TORF++;
			}
		}
	}

	if (stack.t != -1)
		TORF++;
	free(stack.stack);
	make_str(TORF, symbol_N);
}
void make_str(int TorF, int N)
{
	if (TorF == 0) //균형
	{
		printf("OK_%d", N);
	}
	else           //불균형
	{
		printf("Wrong_%d", N);
	}
}
int same_symbol(char a, char b)
{
	if (a == '(')
	{
		if (b == ')')
			return 1;
		else
			return 0;
	}

	if (a == '{')
	{
		if (b == '}')
			return 1;
		else
			return 0;
	}

	if (a == '[')
	{
		if (b == ']')
			return 1;
		else
			return 0;
	}

	else
		return 1;
}