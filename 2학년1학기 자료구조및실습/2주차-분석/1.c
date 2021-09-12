#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int modulo(int a, int b)
{
	while (a >= 0)
	{
		a -= b;
	}
	return a + b;
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));
	return 0;
}
