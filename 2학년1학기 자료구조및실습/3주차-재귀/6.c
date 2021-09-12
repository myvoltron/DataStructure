#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int get_gcd(int n1, int n2)
{
	if (n1 == 0 && n2 != 0)
		return n2;
	else if (n1 != 0 && n2 == 0)
		return n1;

	else
		get_gcd(n2, n1 % n2);
}

int main()
{
	int n1 = 0, n2 = 0;

	scanf("%d %d", &n1, &n2);
	printf("%d", get_gcd(n1, n2));
	return 0;
}