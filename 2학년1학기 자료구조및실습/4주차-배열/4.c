#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int arr[100][100];
	int N = 0, M = 0;
	int save_N, save_M;
	int i = 0, j = -1;
	int num = 1;
	int oper = 1;

	scanf("%d %d", &N, &M);
	save_N = N;
	save_M = M;

	while (num <= save_N * save_M)
	{
		for (int l = 0; l < M; l++)
		{
			j += oper;
			arr[i][j] = num++;
		}
		for (int l = 0; l < N - 1; l++)
		{
			i += oper;
			arr[i][j] = num++;
		}

		oper *= -1;
		M--;
		N--;
	}

	for (i = 0; i < save_N; i++)
	{
		for (j = 0; j < save_M; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	return 0;
}

