#include <stdio.h>
#include <iostream>

using namespace std;

class OtherClass {
	void OutTime() { printf("~~"); }
};

namespace A {
	class MyClass {
	public:
		int value;
		MyClass() { ; }
		void OutTime() { printf("~~"); }
	};
	double value;
	void OutTime() { printf("~~"); }
}

namespace B {
	int value;
	void OutTime() { printf("~~"); }
}

using namespace A;

int value;

int main()
{
	int value;
	//A::MyClass a;
	MyClass a;

	a.value = 10;
	//A::value = 3.14159;
	B::value = 10;

	value = 1;
	::value = 12;
	A::value = 12.5;

	printf("%f\n", A::value);
	printf("%d\n", B::value);

	std::cout << " " << endl;

	return 0;
}