#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void print_high_digit(int n)
{
	if (n < 10)
		printf("%d\n", n);
	else
	{
		print_high_digit(n / 10);
		printf("%d\n", n % 10);
	}
}

int main()
{
	int N = 0;
	scanf("%d", &N);
	print_high_digit(N);
	return 0;
}