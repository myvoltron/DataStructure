#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void rhanoi(int n, char from, char aux, char to)
{
	if (n == 1)
	{
		printf("%c %c\n", from, to);
		return;
	}

	rhanoi(n - 1, from, to, aux);
	printf("%c %c\n", from, to);
	rhanoi(n - 1, aux, from, to);
}
void hanoi(int n)
{
	rhanoi(n, 'A', 'B', 'C');
}

int main()
{
	int N = 0;

	scanf("%d", &N);
	hanoi(N);
	return 0;
}