#include <stdio.h>
#include <string.h>

class Human {
private:
	char name[12];
	int age;

public:
	// ������
	Human(const char* name, int age){
		strcpy(this->name, name); // strcpy(Human::name, name);
		this->age = age; // Human::age = age;
	}

	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human h = Human("��â��", 26);
	h.intro();

	return 0;
}