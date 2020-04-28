#include <stdio.h>

int main()
{
	int a, b;

	try
	{
		printf("a를 입력하세요: ");
		scanf("%d", &a);
		if (a < 0) throw a;
		printf("b를 입력하세요: ");
		scanf("%d", &b);
		if (b == 0) throw "0으로 나눌 수 없음";
		else if (b < 0) throw b;
		printf("나누기결과: %d\n", a / b);
	}
	catch (int a)
	{
		if (a < 0)
			printf("%d는 음수이므로 나눌 수 없음.\n", a);
		else if (a == 0)
			printf("%d는 0이므로 나눌 수 없음.\n", a);
		//printf("%d는 음수이거나 0으로 연산 불가.\n", a);
	}
	catch (const char* msg)
	{
		//puts(msg);
		printf("%s\n", msg);
	}

	return 0;
}