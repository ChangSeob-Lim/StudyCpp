#include <stdio.h>

// ������ const -> ���ϰ��� �ٲ��� �ʴ°� ���� ������ const -> �Լ����� ���� �������� �ʴ´�?
// ���� �� ���ϰ��� ���Ƿ� �ٲ� �� ����.
// t3 = (t1 + t2).SetTime(6, 6, 6);

class Time {
private:
	int hour, min, sec;

public:
	Time() { ; }
	Time(int h, int m, int s) : hour(h), min(m), sec(s) { ; }

	void OutTime()
	{
		printf("%2d:%2d:%2d\n", hour, min, sec);
	}

	const Time operator ++() { 
		sec++;
		min += sec / 60;
		sec %= 60;
		hour += min / 60;
		min %= 60;

		return *this;
	}

	Time operator ++(int dummy)
	{
		Time t = *this;
		++* this;

		return t;
	}

	Time SetTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;

		return *this;
	}
};

int main()
{
	Time t1(1, 1, 1);
	Time t2;

	t2 = ++t1;
	t1.OutTime();
	t2.OutTime();

	t2 = t1++;
	t1.OutTime();
	t2.OutTime();

	t2 = t1++.SetTime(6, 6, 6); // const�� ������ �̷��� �Ұ�����
	t1.OutTime();

	return 0;
}