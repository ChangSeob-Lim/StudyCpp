#include <stdio.h>
#include "Time.h"
#include "Date.h"

int main()
{
	Date d;
	d.SetDate(2020, 4, 20);
	d.OutDate();
	printf("Size of Date = %d\n", sizeof(Date));

	Time now;
	now.SetTime(15, 24, 48);
	now.OutTime();
	printf("Size of Time = %d\n", sizeof(Time));

	return 0;
}