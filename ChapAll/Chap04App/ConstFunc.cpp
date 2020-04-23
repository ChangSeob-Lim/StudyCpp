#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		SetTime(h, m, s);
	}

	void SetTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() const { // 상태 멤버 함수는 객체의 상태를 읽기만 하는 함수
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time getoff(17, 30, 00);
	// getoff.SetTime(17, 00, 00); // const라서 변경 불가능
	getoff.OutTime();

	return 0;
}