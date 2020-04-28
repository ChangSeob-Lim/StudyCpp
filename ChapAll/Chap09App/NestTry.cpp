#include <stdio.h>
#include <conio.h>
#include <string>

int main()
{
	int num;
	int age;
	char name[12];

	try
	{
		printf("학번을 입력하세요: ");
		scanf("%d", &num);
		if (num <= 0) throw num;

		try
		{
			printf("이름을 입력하세요: ");
			scanf("%s", name);
			if (strlen(name) < 4) throw "이름이 너무 짦음."; // throw name;
			printf("나이를 입력하세요: ");
			scanf("%d", &age);
			if (age <= 0) throw age;
			printf("입력한 정보 => 학번: %d, 이름: %s, 나이: %d\n", num, name, age);
		}
		catch (const char* msg)
		{
			//puts(msg);
			printf("[ERROR] %s\n", msg); // printf("[ERROR] %s는 너무 짧음.\n", msg);
		}
		catch (int)
		{
			throw;
		}
	}
	catch (int n)
	{
		// [ERROR], [INFO] 등으로 표시하는게 좋음
		printf("[ERROR] %d는 적절하지 않은 값입니다.\n", n);
	}
}