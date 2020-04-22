#include <stdio.h>

class Date;
class Time {
	friend void OutToday(Date&, Time&);

private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		if (h >= 0 && h < 24)
		{
			hour = h;
		}
		else
		{
			hour = 0;
		}

		if (m >= 0 && m < 60)
		{
			min = m;
		}
		else
		{
			min = 0;
		}

		if (s >= 0 && s < 60)
		{
			sec = s;
		}
		else
		{
			sec = 0;
		}
	}
};

class Date {
	friend void OutToday(Date&, Time&);

private:
	int year, month, day;

public:
	Date(int y, int m, int d)
	{
		if (y> 0)
		{
			year = y;
		}
		else
		{
			year = 0;
		}

		if (m > 0 && m <= 12)
		{
			month = m;
		}
		else
		{
			month = 0;
		}

		if (d > 0 && d < 32)
		{
			day = d;
		}
		else
		{
			day = 0;
		}
	}
};

void OutToday(Date& d, Time& t)
{
	printf("������ %d�� %2d�� %2d���̸� ���� �ð��� %2d:%2d:%2d �Դϴ�.\n", d.year, d.month, d.day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);

	OutToday(d, t);

	return 0;
}