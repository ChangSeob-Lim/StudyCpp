#include <stdio.h>

// 왼쪽의 const -> 리턴값이 바꾸지 않는걸 정의 오른쪽 const -> 함수에서 값을 변경하지 않는다?

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

	Time operator ++() { 
		sec++;
		min += sec / 60;
		sec %= 60;
		hour += min / 60;
		min %= 60;

		return *this;
	}

	const Time operator ++(int dummy)
	{
		Time t = *this;
		++* this;

		return t;
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

	return 0;
}