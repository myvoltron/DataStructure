#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	char message[101];
	int str_len = 0;
	int i, j;
	char save;

	scanf("%s", message);
	str_len = strlen(message);

	for (i = 0; i < str_len; i++)
	{
		printf("%s\n", message);

		save = message[0];
		for (j = 0; j < str_len - 1; j++)
			message[j] = message[j + 1];
		message[str_len - 1] = save;
	}
	return 0;
}