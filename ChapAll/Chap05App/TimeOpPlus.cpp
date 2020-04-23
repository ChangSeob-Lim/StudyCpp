#include <stdio.h>

class Time {
	friend const Time operator + (const Time & me, const Time & other);

private:
	int hour, min, sec;

public:
	Time() { ; }
	Time(int h, int m, int s) : hour(h), min(m), sec(s) { ; }

	void OutTime()
	{
		printf("%2d:%2d:%2d\n", hour, min, sec);
	}
};

const Time operator +(const Time& me, const Time& other)
{
	Time t;
	t.sec = me.sec + other.sec; // 35 + 56 = 91 / 60 = 1m 31s
	t.min = me.min + other.min;
	t.hour = me.hour + other.hour;

	t.min += t.sec / 60;
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;
	// t.hour %= 24; // 시간 상으로는 변경

	return t;
}

int main()
{
	Time t1(14, 19, 32), t2(17, 24, 53);
	Time t3;
	t1.OutTime();
	t2.OutTime();

	t3 = t1 + t2;
	t3.OutTime();

	return 0;
}