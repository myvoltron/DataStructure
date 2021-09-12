#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int N = 0;
	int* arr1 = NULL;
	int* arr2 = NULL;
	int* result = NULL;
	int* ptr;
	int* result_ptr;
	scanf("%d", &N);

	arr1 = (int*)malloc(N * sizeof(int));
	arr2 = (int*)malloc(N * sizeof(int));
	result = (int*)malloc(N * sizeof(int));

	for (ptr = arr1, result_ptr = result; ptr < arr1 + N; ptr++, result_ptr++)
	{
		scanf("%d", ptr);
		*result_ptr = *ptr;
	}

	for (ptr = arr2, result_ptr = result + N - 1; ptr < arr2 + N; ptr++, result_ptr--)
	{
		scanf("%d", ptr);
		*result_ptr += *ptr;
	}

	for (result_ptr = result; result_ptr < result + N; result_ptr++)
		printf(" %d", *result_ptr);

	free(arr1);
	free(arr2);
	free(result);
	return 0;
}