#include <stdio.h>

class Time {
	friend const Time operator +(const int s, const Time& me);
	friend const Time operator *(const int s, const Time& me);

private:
	int hour, min, sec;

public:
	Time() { ; }
	Time(int h, int m, int s) : hour(h), min(m), sec(s) { ; }

	void OutTime()
	{
		printf("%2d:%2d:%2d\n", hour, min, sec);
	}

	const Time operator +(const Time& other) const
	{
		Time t;
		t.sec = sec + other.sec; // 35 + 56 = 91 / 60 = 1m 31s
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		// t.hour %= 24; // 시간 상으로는 변경

		return t;
	}

	const Time operator +(const int s) const
	{
		Time t = *this;
		t.sec += s;
		
		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		// t.hour %= 24; // 시간 상으로는 변경

		return t;
	}

	const Time operator *(const int s) const
	{
		Time t = *this;
		
		int tsec = t.hour * 60 * 60 + t.min * 60 + t.sec;
		tsec *= s;

		t.hour = tsec / 3600;
		t.min = (tsec / 60) % 60;
		t.sec = tsec % 60;

		/*t.sec *= s;
		t.min *= s;
		t.hour *= s;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;*/

		return t;
	}

	const bool operator ==(const Time& other) const
	{
		return (hour == other.hour && min == other.min && sec == other.sec);
	}

	bool operator !=(const Time& other) const
	{
		return !(*this == other);
	}

	bool operator >(const Time& other) const
	{
		/*Time t = *this;
		int left, right;
		left = t.hour * 3600 + t.min * 60 + t.sec;
		right = other.hour * 3600 + other.min * 60 + other.sec;

		if (left > right) return true;
		else return false;*/

		if (hour > other.hour) return true;
		if (hour < other.hour) return false;
		if (min > other.min) return true;
		if (min < other.min) return false;
		if (sec > other.sec)return true;
		return false;
	}

	bool operator <(const Time& other) const
	{
		return *this > other;
	}

	bool operator >=(const Time& other) const
	{
		return (*this == other || *this > other);
	}

	bool operator <=(const Time& other) const
	{
		return !(*this >= other);
	}
};

const Time operator +(const int s, const Time& me)
{
	//Time t = me;
	//t.sec += s;

	//t.min += t.sec / 60;
	//t.sec %= 60;
	//t.hour += t.min / 60;
	//t.min %= 60;
	//// t.hour %= 24; // 시간 상으로는 변경

	//return t;

	return (me + s);
}

const Time operator *(const int s, const Time& me)
{
	return (me * s);
}

int main()
{
	Time t1(1, 40, 32), t2(3, 24, 33);
	Time t3;
	t1.OutTime();
	t2.OutTime();

	t3 = t1 + t2;
	t3.OutTime(); // 5: 5: 5

	Time now;
	now = t3 + 3655;
	now.OutTime(); // 6: 6: 0

	now = 60 + now; // friend const opeartor에 의해 (int, Time) operator 생성 가능 사용하고 싶은 경우를 모두 만들어야 사용 가능
	//now = now + 60;
	now.OutTime(); // 6: 7: 0
	
	Time cur(1, 20, 12);
	Time mul;
	mul = cur * 2;

	mul.OutTime();

	return 0;
}