#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int sum(int n)
{
	int result = 0, i;
	for (i = 1; i <= n; i++)
		result += i;

	return result;
}

int main()
{
	int X = 0, i;
	int sum_val = 0;
	scanf("%d", &X);

	for (i = 1; i <= X; i++)
		sum_val += sum(i);

	printf("%d", sum_val);
	return 0;
}