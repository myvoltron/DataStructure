#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void arr_reverse(int* arr, int f, int t)
{
	int n = t - f + 1;
	int save = 0;

	if (n % 2 != 0) //뒤집어야할 숫자들의 개수가 홀수라면
	{
		while (f != t)
		{
			save = arr[f];
			arr[f] = arr[t];
			arr[t] = save;

			f++;
			t--;
		}
	}
	else            //뒤집어야할 숫자들의 개수가 짝수라면
	{
		do
		{
			save = arr[f];
			arr[f] = arr[t];
			arr[t] = save;

			f++;
			t--;
		} while (f - t != 1);
	}
}

int main()
{
	int arr[100];
	int N = 0;
	int N_reverse = 0;
	int from, to;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &N_reverse);
	for (int i = 0; i < N_reverse; i++)
	{
		scanf("%d %d", &from, &to);
		arr_reverse(arr, from, to);
	}

	for (int i = 0; i < N; i++)
		printf(" %d", arr[i]);
	return 0;
}

/*
10
3 81 9 12 0 -9 36 33 91 10
3
3 7 4 5 0 4
*/