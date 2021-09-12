#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int arr[100][100];
	int N = 0, M = 0;
	int i = 0, j = 0;
	int i_mi = 0, j_mi = 0;
	int num = 1;

	scanf("%d %d", &N, &M);
	for (j = 0; j < M; j++)
	{
		i_mi = 0;
		j_mi = 0;
		while (j - j_mi >= 0 && i + i_mi < N)
		{
			arr[i + i_mi][j - j_mi] = num++;
			i_mi++;
			j_mi++;
		}
	}
	j--;
	for (i = 1; i < N; i++)
	{
		i_mi = 0;
		j_mi = 0;
		while (i + i_mi < N && j - j_mi >= 0)
		{
			arr[i + i_mi][j - j_mi] = num++;
			i_mi++;
			j_mi++;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	return 0;
}

