#include <stdio.h>

// 왼쪽의 const -> 리턴값이 바꾸지 않는걸 정의 오른쪽 const -> 함수에서 값을 변경하지 않는다?
// 예를 들어서 리턴값을 임의로 바꿀 수 없다.
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

	t2 = t1++.SetTime(6, 6, 6); // const가 있으면 이런게 불가능함
	t1.OutTime();

	return 0;
}