#include <stdio.h>

class Human {
public:
	char name[12];
	int age;

	void intro()
	{
		printf("�̸�: %s, ����: %d\n", name, age);
	}
};

int main()
{
	/*Human h = { "��â��", 26 };
	h.intro();*/

	Human arFriend[10] = {
		{"������", 49},
		{"������", 45},
		{"�ڻ�", 30}
	};

	Human* pFriend;

	for (int i = 0; i < 10; i++)
	{
		pFriend = &arFriend[i];
		pFriend->intro();
	}
	
	return 0;
}