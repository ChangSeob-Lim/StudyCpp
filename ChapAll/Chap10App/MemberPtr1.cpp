#include <stdio.h>

class Calc {
public:
	void Op1(int a, int b) { printf("%d\n", a + b); }
	void Op2(int a, int b) { printf("%d\n", a - b); }
	void Op3(int a, int b) { printf("%d\n", a * b); }
	void Op4(int a, int b) { printf("%d\n", a / b); }

	void DoCalc(void(Calc::* fp)(int, int), int a, int b) {
		puts("초기 연산 로직 실행");
		printf("%d와 %d의 연산 결과 : ", a, b);
		(this->*fp)(a, b);
		puts("이후 로직 실행");
	}
};

int main()
{
	int ch;
	Calc c;
	int a = 10, b = 5;
	void (Calc:: * arOp[4])(int, int) = { &Calc::Op1, &Calc::Op2, &Calc::Op3, &Calc::Op4 };

	while (true)
	{
		printf("연산을 선택하세요, 1=더하기, 2=빼기, 3=곱하기, 4=더하기, 0=종료 : ");
		scanf("%d", &ch);

		if (ch > 0 && ch < 5)
		{
			//(c.*arOp[ch - 1])(a, b);
			c.DoCalc(arOp[ch - 1], a, b);
		}
		else if (ch == 0)
		{
			return 0;
		}

		/*switch (ch)
		{
		case 1:
			(c.*arOp[0])(a, b);
			break;
		case 2:
			(c.*arOp[1])(a, b);
			break;
		case 3:
			(c.*arOp[2])(a, b);
			break;
		case 4:
			(c.*arOp[3])(a, b);
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}*/
	}

	return 0;
}