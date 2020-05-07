#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdarg>
#include <thread>
using namespace std;

template<typename Func>
void Test(Func func, int n)
{
	func(n);
}

function<void()> func5()
{
	string str("lambda");
	return [=] {cout << "Hello " << str << endl; };
}

void func6()
{
	return;
}

class Foo {
public:
	int i;
	Foo() : i(0) { ; }
	void amazing() {
		[=] {i = 8; }();
	}
};

void PrintNum(int args, ...)
{
	va_list ap;

	va_start(ap, args);
	for (int i = 0; i < args; i++)
	{
		cout << "args " << args << ": " << va_arg(ap, int) << endl;
	}cout << endl;
}

int main()
{
	PrintNum(1, 1);
	PrintNum(2, 2, 3);
	PrintNum(5, 1, 2, 3, 4, 5);

	auto Sum = [](auto a, auto b) { return a + b; };

	cout << Sum(3, 4) << endl;
	cout << Sum(3.14, 2.77) << endl;

	Foo foo;
	foo.amazing();
	cout << foo.i << endl;

	int num1 = 0;

	[](int n) {cout << "Hello World!" << n << endl; }(10); // �̷��� ���� ������ ȣ�� �Ұ���

	auto func = [](int n) {cout << "Hello World!" << n << endl; }; // �̷��� ������ �����ϸ� ������ ��� ����

	auto func0 = [num1](int n) mutable {
		num1 = 100;
		cout << "Hello World!" << num1 << ", " << n << endl;
	};

	cout << num1 << endl;

	func(20);
	func(21);

	Test(func, 30);

	// ���ϰ�
	auto func1 = [] {return 3.14f; };
	auto func2 = [](double f) {return f; };
	auto func3 = []() -> double {return 3.141592; };

	float f1 = func1();
	cout << f1 << endl;
	double f2 = func2(3.141592);
	cout << f2 << endl;
	double f3 = func3();
	cout << f3 << endl;

	vector<int> v1;
	v1.push_back(10);
	v1.emplace_back(20);
	v1.emplace_back(30);
	v1.emplace_back(40);
	v1.emplace_back(50);

	for_each(v1.begin(), v1.end(), [](int n) { cout << n << endl; });

	int x = 100;
	int y = 200;
	[&x, &y]() /*mutable*/ { x = 400;  y = 500; cout << x << ", "  << y << endl; }(); // [] �ܺ� �Լ� ��� �Ұ� [=] �ܺ� ������ ������ �� ����(����), [&] �ܺ� ������ �������� ������ �� ����(����), [������, ������] ������ ����� �� ���� mutable�� ���� �� &��� ���� ����, [&������] ������ ����

	thread Thread1([]() {
		for (int i = 0; i < 5; i++)
		{
			cout << "Hello Thread " << endl;
		}
		});

	Thread1.join();

	return 0;
}