#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int maxnum(int arr[], int n)
{
	if (n == 1)
		return arr[0];
	else if (n == 2)
		return arr[0] >= arr[1] ? arr[0] : arr[1];
	else
		return arr[n - 1] >= maxnum(arr, n - 1) ? arr[n - 1] : maxnum(arr, n - 1);
}

int main()
{
	int N = 0;
	int arr[20];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	printf("%d", maxnum(arr, N));
	return 0;
}