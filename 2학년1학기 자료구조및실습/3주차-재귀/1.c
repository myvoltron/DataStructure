#include <stdio.h>
#pragma warning(disable:4996)

int addtion(int N)
{
	if (N == 1)
		return 1;
	else
		return N + addtion(N - 1);
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", addtion(N));
	return 0;
}
