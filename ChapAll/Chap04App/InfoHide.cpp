#include <stdio.h>

class Time {
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		SetHour(h);
		SetMin(m);
		SetSec(s);
	}

	int GetHour()
	{
		return hour;
	}
	void SetHour(int h)
	{
		if (h >=0 && h < 24)
		{
			hour = h;
		}
		else {
			hour = h % 24;
		}
	}

	int GetMin()
	{
		return min;
	}
	void SetMin(int m)
	{
		if (m >= 0 && m < 60)
		{
			min = m;
		}
		else
		{
			min = m % 60;
		}
	}

	int GetSec()
	{
		return sec;
	}
	void SetSec(int s)
	{
		if (s >= 0 && s < 60)
		{
			sec = s;
		}
		else
		{
			sec = s % 60;
		}
	}

	void OutTime()
	{
		printf("현재 시간은 %2d:%2d:%2d 입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(14, 2, 24);
	now.OutTime();
	
	now.SetHour(40);
	now.OutTime();

	now.SetHour(9);
	now.SetMin(20);
	now.SetSec(14);
	now.OutTime();

	return 0;
}