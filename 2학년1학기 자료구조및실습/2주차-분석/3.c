#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

double* prefixAverage1(int A[], int N);
double* prefixAverage2(int A[], int N);

int main()
{
	int* X = NULL;
	int* i_ptr;
	int N = 0;
	double* result_ptr;
	double* ptr;

	scanf("%d", &N);
	X = (int*)malloc(N * sizeof(int));
	if (X == NULL)
	{
		printf("동적할당 오류!\n");
		return 1;
	}

	for (i_ptr = X; i_ptr < X + N; i_ptr++)
		scanf("%d", i_ptr);

	result_ptr = prefixAverage1(X, N);
	for (ptr = result_ptr; ptr < result_ptr + N; ptr++)
		printf("%d ", (int)(*ptr + 0.5));
	printf("\n");
	result_ptr = prefixAverage2(X, N);
	for (ptr = result_ptr; ptr < result_ptr + N; ptr++)
		printf("%d ", (int)(*ptr + 0.5));
	return 0;
}

double* prefixAverage1(int A[], int N)
{
	int i, j;
	double sum = 0;
	double* result = NULL;
	result = (double*)malloc(N * sizeof(double));

	for (i = 0; i < N; i++)
	{
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += A[j];
		result[i] = sum / (i + 1);
	}

	return result;
}

double* prefixAverage2(int A[], int N)
{
	int i;
	double sum = 0;
	double* result = NULL;
	result = (double*)malloc(N * sizeof(double));

	for (i = 0; i < N; i++)
	{
		sum += A[i];
		result[i] = sum / (i + 1);
	}

	return result;
}

/*
3
5 1 9

6
1 3 2 10 6 13
*/