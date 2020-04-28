#include <stdio.h>
#include <limits>

int main()
{
	const char* str = "korea";
	int* pi;
	double d = 214783647.99999;// 123.456;
	int i;

	double dd = std::numeric_limits<double>::max();
	int di = std::numeric_limits<int>::max();
	printf("%d\n\n", di);
	i = static_cast<int>(dd);
	printf("%d\n\n", i);
	// pi = static_cast<int*>(str); // 잘못된 변환은 static_cast가 잡아준다. 에러
	pi = (int*)str;
	//printf("%d %x\n", *pi, *pi);

	return 0;
}