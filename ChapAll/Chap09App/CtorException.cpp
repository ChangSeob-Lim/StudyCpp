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
			printf("100���� ���� �� �Է� = %d\n", a);
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
		printf("%d�� 100���� �� Ů�ϴ�.\n", a);
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
		printf("100���� ���� �� �Է� = %d\n", n);
	}

	return 0;
}