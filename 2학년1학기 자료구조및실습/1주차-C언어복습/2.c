#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void ABC(int arr[], int k)
{
	int max_num = -999;
	int i;
	int save;
	int max_num_index = k;
	for (i = k; i < 10; i++)
	{
		if (max_num < arr[i])
		{
			max_num = arr[i];
			max_num_index = i;
		}
	}

	save = arr[k];
	arr[k] = max_num;
	arr[max_num_index] = save;
}

int main()
{
	int arr[10] = { 0 };
	int* ptr;
	int k;

	for (ptr = arr; ptr < arr + 10; ptr++)
		scanf("%d", ptr);

	for (k = 0; k < 10; k++)
		ABC(arr, k);

	for (ptr = arr; ptr < arr + 10; ptr++)
		printf(" %d", *ptr);
	return 0;
}