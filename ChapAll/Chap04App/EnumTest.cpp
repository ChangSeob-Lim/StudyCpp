#include <stdio.h>

enum Color
{
	Black,
	White,
	Red,
	Green,
	Blue,
	Aqua,
	Gray
};

class Test {
private:
	Color mycol;

public:
	Test() {
		mycol = Black;
	}

	void OutColor()
	{
		printf("%d\n", mycol);
	}
};

int main()
{
	Test t;

	t.OutColor();

	return 0;
}