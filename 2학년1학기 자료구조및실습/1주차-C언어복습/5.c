#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct time_
{
	int hour;
	int min;
	int sec;
} TIME_;

int main()
{
	TIME_ time1, time2, result_time;

	scanf("%02d %02d %02d", &time1.hour, &time1.min, &time1.sec);
	scanf("%02d %02d %02d", &time2.hour, &time2.min, &time2.sec);

	if (time1.sec > time2.sec)
	{
		time2.min -= 1;
		time2.sec += 60;
	}
	result_time.sec = time2.sec - time1.sec;

	if (time1.min > time2.min)
	{
		time2.hour -= 1;
		time2.min += 60;
	}
	result_time.min = time2.min - time1.min;
	result_time.hour = time2.hour - time1.hour;

	printf("%d %d %d", result_time.hour, result_time.min, result_time.sec);
	return 0;
}