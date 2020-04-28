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
		printf("�й��� �Է��ϼ���: ");
		scanf("%d", &num);
		if (num <= 0) throw num;

		try
		{
			printf("�̸��� �Է��ϼ���: ");
			scanf("%s", name);
			if (strlen(name) < 4) throw "�̸��� �ʹ� �F��."; // throw name;
			printf("���̸� �Է��ϼ���: ");
			scanf("%d", &age);
			if (age <= 0) throw age;
			printf("�Է��� ���� => �й�: %d, �̸�: %s, ����: %d\n", num, name, age);
		}
		catch (const char* msg)
		{
			//puts(msg);
			printf("[ERROR] %s\n", msg); // printf("[ERROR] %s�� �ʹ� ª��.\n", msg);
		}
		catch (int)
		{
			throw;
		}
	}
	catch (int n)
	{
		// [ERROR], [INFO] ������ ǥ���ϴ°� ����
		printf("[ERROR] %d�� �������� ���� ���Դϴ�.\n", n);
	}
}