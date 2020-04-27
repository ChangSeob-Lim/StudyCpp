#include "PosValue.h"

using namespace std;

int main()
{
	PosValue<int> iv(10, 10, 2);
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);

	iv.outValue();
	cv.outValue();
	dv.outValue();

	return 0;
}

// 안함 수정 필요