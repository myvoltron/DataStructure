#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int arr[100][100];
	int N = 0;
	int num = 1;
	int i = 0, j = 0;
	int oper = 1;

	scanf("%d", &N);
	while (num <= N * N)
	{
		arr[i][j] = num++;
		if ((num - 1) % N == 0)
		{
			i++;
			arr[i][j] = num++;
			oper *= -1;
		}
		j += oper;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	return 0;
}

/*
10
3 81 9 12 0 -9 36 33 91 10
5
3 8 0 9 3
*/