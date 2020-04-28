#include <stdio.h>

class Int100 {
private:
	int num;
public:
	Int100(int a) try :num(a) {
		/*try
		{
			if (a > 100) throw a;
			num = a;
		}
		catch (int a)
		{
			printf("100보다 작은 수 입력 = %d\n", a);
		}*/

		if (a <= 100)
		{
			num = a;
		}
		else
		{
			throw a;
		}
	}
	catch (int a) {
		printf("%d은 100보다 더 큽니다.\n", a);
	}

	Int100& operator+=(int b) {
		if (num + b <= 100) {
			num += b;
		}
		else
		{
			throw num + b;
		}

		return *this;
	}

	void OutValue() {
		printf("%d\n", num);
	}
};

int main()
{
	/*Int100 i(85);
	i.OutValue();*/

	try
	{
		Int100 i(101);
		i += 12;
		i.OutValue();
	}
	catch (int n)
	{
		printf("100보다 작은 수 입력 = %d\n", n);
	}

	return 0;
}