#include <stdio.h>

// 함수 템플릿 //
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

// 일반적인 스왑 //
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
	Util u; // 템플릿 멤버 함수
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	//swap(a, b); // 지금 선언한 템플릿으로는 (int, double)은 불가능
	//swap(c, d);
	//swap(e, f);

	u.swap(a, b); // 지금 선언한 템플릿으로는 (int, double)은 불가능
	u.swap(c, d);
	u.swap(e, f);

	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);

	//printf("a + b = %d\n", add(a, b));
	//printf("a - b = %d\n", sub(a, b));
	//printf("c + d = %f\n", add(c, d));
	//printf("e + f = %c\n", add(e, f)); // 안 나옴

	return 0;
}