#include <stdio.h>

class Time {
	friend class Date;

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
private:
	int year, month, day;

public:
	Date(int y, int m, int d)
	{
		if (y > 0)
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
	// 각각 데이터에 대해 GetDate, SetDate를 만들고 생성자에서도 각 함수를 사용하는게 좋음

	void OutToday(Time& t)
	{
		printf("오늘은 %d년 %2d월 %2d일이며 지금 시간은 %2d:%2d:%2d 입니다.\n", year, month, day, t.hour, t.min, t.sec);
	}
};

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);

	d.OutToday(t);

	return 0;
}