#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int mostones(int Arr[][100], int n)
{
	int row = 0, jmax = 0;
	int j = 0;

	while (1)
	{
		if (row >= n || j >= n) //마지막 열이나 행을 만나면 종료
			break;

		if (Arr[row][j] == 0) //0을 만나면 아래 행으로 간다.
			row++;
		else if (Arr[row][j] == 1) //1을 만나면 오른쪽 열으로 간다. 그리고 jmax에 row를 저장한다. 
		{
			j++;
			jmax = row;
		}
	}

	return jmax;
}

int main()
{
	int arr[100][100];
	int n = 0;
	int i = 0, j = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}
	printf("%d", mostones(arr, n));
	return 0;
}