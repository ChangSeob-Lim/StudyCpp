#include <stdio.h>

int main()
{
	int a, b;

	try
	{
		printf("a�� �Է��ϼ���: ");
		scanf("%d", &a);
		if (a < 0) throw a;
		printf("b�� �Է��ϼ���: ");
		scanf("%d", &b);
		if (b == 0) throw "0���� ���� �� ����";
		else if (b < 0) throw b;
		printf("��������: %d\n", a / b);
	}
	catch (int a)
	{
		if (a < 0)
			printf("%d�� �����̹Ƿ� ���� �� ����.\n", a);
		else if (a == 0)
			printf("%d�� 0�̹Ƿ� ���� �� ����.\n", a);
		//printf("%d�� �����̰ų� 0���� ���� �Ұ�.\n", a);
	}
	catch (const char* msg)
	{
		//puts(msg);
		printf("%s\n", msg);
	}

	return 0;
}