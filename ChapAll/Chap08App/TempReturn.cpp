#include <stdio.h>

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T>
T cast(int s)
{
	return (T)s;
}

int main()
{
	int a = max(1, 2);
	double b = max(1.1, 2.2);
	int c = max(cast<int>(2), int(3.14)); // int(3.14), (int)3.14 앞이 c++ 표준이였던것 같음

	printf("c = %d\n", c);

	return 0;
}