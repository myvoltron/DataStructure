#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int inspect_char(char str[], char ins, int idx, int len)
{
	if (idx == len - 1)
	{
		if (str[idx] == ins)
			return 1;
		else
			return 0;
	}

	else
	{
		if (str[idx] == ins)
			return 1 + inspect_char(str, ins, idx + 1, len);
		else
			return inspect_char(str, ins, idx + 1, len);
	}
}

int main()
{
	char str[101];
	char inspector;

	scanf("%s", str);
	getchar();
	scanf("%c", &inspector);

	printf("%d", inspect_char(str, inspector, 0, strlen(str)));
	return 0;
}