#include <stdio.h>

namespace UTIL {
	int value;
	double score;
	void sub() { puts("sub routine"); }
}

using namespace UTIL;

int main()
{
	/*UTIL::*/value = 3;
	/*UTIL::*/score = 1.2;
	/*UTIL::*/sub();

	return 0;
}