#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct student
{
	char name[10];
	int score;
} ST;

int main()
{
	ST st[5];
	ST* st_ptr;
	double avg = 0;

	for (st_ptr = st; st_ptr < st + 5; st_ptr++)
	{
		scanf("%s %d", st_ptr->name, &st_ptr->score);
		avg += st_ptr->score;
	}
	avg /= 5;

	for (st_ptr = st; st_ptr < st + 5; st_ptr++)
	{
		if (st_ptr->score <= avg)
			printf("%s\n", st_ptr->name);
	}
	return 0;
}