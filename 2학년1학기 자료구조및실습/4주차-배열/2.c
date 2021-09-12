#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int switch_location(int* arr, int from, int to)
{
	int save = arr[to];
	arr[to] = from;

	return save;
}

int main()
{
	int arr[100];
	int N = 0;
	int order_switch_N = 0;
	int* order_switch;
	int* ptr = NULL;
	int save = 0;
	int ins_first = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &order_switch_N);
	order_switch = (int*)malloc(order_switch_N * sizeof(int));
	for (ptr = order_switch; ptr < order_switch + order_switch_N; ptr++)
		scanf("%d", ptr);

	for (ptr = order_switch; ptr < order_switch + order_switch_N - 1; ptr++)
	{
		if (ins_first++ == 0)
		{
			save = arr[*ptr];
			save = switch_location(arr, save, *(ptr + 1));
			continue;
		}
		save = switch_location(arr, save, *(ptr + 1));
	}

	for (int i = 0; i < N; i++)
		printf(" %d", arr[i]);
	return 0;
}

/*
10
3 81 9 12 0 -9 36 33 91 10
5
3 8 0 9 3
*/