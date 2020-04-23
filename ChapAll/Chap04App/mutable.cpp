#include <stdio.h>

class Some
{
private:
	mutable int temp;

public:
	Some() { temp = 1; }
	void method() const { temp = 0; } // mutable �� const�󿡼��� ���� �����ϰ� ������ �� �Ⱦ�
	void print() const { printf("%d\n", temp); }
};

int main()
{
	Some s;
	s.method();
	s.print();

	const Some t;
	t.method();
	t.print();

	return 0;
}