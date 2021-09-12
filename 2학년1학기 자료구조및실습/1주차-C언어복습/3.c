#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void swap(int* ptr1, int* ptr2)
{
	int save;
	save = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = save;
}

int main()
{
	int N = 0;
	int arr[50] = { 0 };
	int* ptr;
	int a, b;

	scanf("%d", &N);
	for (ptr = arr; ptr < arr + N; ptr++)
		scanf("%d", ptr);

	scanf("%d %d", &a, &b);
	swap(arr + a, arr + b);

	for (ptr = arr; ptr < arr + N; ptr++)
		printf(" %d", *ptr);
	return 0;
}