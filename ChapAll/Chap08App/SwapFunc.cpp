#include <stdio.h>

// �Լ� ���ø� //
//template <typename T>
//void swap(T& a, T& b)
//{
//	T t;
//	t = a; a = b; b = t;
//}
//
//template <typename T>
//T add(T& a, T& b)
//{
//	return a + b;
//}
//
//template <typename T>
//T sub(T& a, T& b)
//{
//	return a - b;
//}

// �Ϲ����� ���� //
//void swap(int& a, int& b)
//{
//	int t;
//	t = a; a = b; b = t;
//}

//void swap(double& a, double& b)
//{
//	double t;
//	t = a; a = b; b = t;
//}

class Util {
public:
	template <typename T>
	void swap(T& a, T& b)
	{
		T t;
		t = a; a = b; b = t;
	}
};

int main()
{
	Util u; // ���ø� ��� �Լ�
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	//swap(a, b); // ���� ������ ���ø����δ� (int, double)�� �Ұ���
	//swap(c, d);
	//swap(e, f);

	u.swap(a, b); // ���� ������ ���ø����δ� (int, double)�� �Ұ���
	u.swap(c, d);
	u.swap(e, f);

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);

	//printf("a + b = %d\n", add(a, b));
	//printf("a - b = %d\n", sub(a, b));
	//printf("c + d = %f\n", add(c, d));
	//printf("e + f = %c\n", add(e, f)); // �� ����

	return 0;
}