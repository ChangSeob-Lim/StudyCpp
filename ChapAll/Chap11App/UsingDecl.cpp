#include <stdio.h>

namespace UTIL {
	int value;
	double score;
	void sub() { puts("sub routine"); }
}

namespace VeryVeryLongLongNameSpace {
	// ~
	int value;
}

namespace MyCompany {
	namespace Reserch {
		namespace GameEngine {
			// ...
		}
	}
}

int value;

int main()
{
	namespace MRG = MyCompany::Reserch::GameEngine;
	namespace A = VeryVeryLongLongNameSpace;
	using namespace UTIL;
	int value = 3;

	VeryVeryLongLongNameSpace::value = 1;
	A::value = 2;

	UTIL::value = 3;
	UTIL::score = 1.234;
	UTIL::sub();

	return 0;
}

void mysub() {
	UTIL::value = 5;
}