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

	void OutTime() const { // ���� ��� �Լ��� ��ü�� ���¸� �б⸸ �ϴ� �Լ�
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time getoff(17, 30, 00);
	// getoff.SetTime(17, 00, 00); // const�� ���� �Ұ���
	getoff.OutTime();

	return 0;
}