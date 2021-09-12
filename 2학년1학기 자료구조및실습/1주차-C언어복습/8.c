#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct student
{
	char name[8];
	int score1, score2, score3;
	double avg;
} ST;

int main()
{
	int N = 0;
	ST* st = NULL;
	ST* st_ptr;

	scanf("%d", &N);
	st = (ST*)malloc(N * sizeof(ST));
	if (st == NULL)
	{
		printf("malloc() error!");
		return 0;
	}

	for (st_ptr = st; st_ptr < st + N; st_ptr++)
	{
		st_ptr->avg = 0.0;
		scanf("%s %d %d %d", st_ptr->name, &st_ptr->score1, &st_ptr->score2, &st_ptr->score3);
		st_ptr->avg = st_ptr->score1 + st_ptr->score2 + st_ptr->score3;
		st_ptr->avg /= 3;
	}

	for (st_ptr = st; st_ptr < st + N; st_ptr++)
	{
		printf("%s %.1lf", st_ptr->name, st_ptr->avg);
		if (st_ptr->score1 >= 90 || st_ptr->score2 >= 90 || st_ptr->score3 >= 90)
			printf(" GREAT");
		if (st_ptr->score1 < 70 || st_ptr->score2 < 70 || st_ptr->score3 < 70)
			printf(" BAD");
		printf("\n");
	}

	free(st);
	return 0;
}