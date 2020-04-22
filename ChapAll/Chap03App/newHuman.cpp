#include <stdio.h>
#include <string.h>

class Human {
private:
	char* name;
	int age;

public:
	//Human() {
	//	// ����Ʈ ������
	//	name = new char[strlen("�̸�����") + 1];
	//	strcpy(name, "�̸�����");
	//	age = 0;
	//}

	Human(const char* aname = "�̸�����", int aage = 0) {
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;

		printf("%s ��ü�� �����ڰ� ȣ��Ǿ����ϴ�.\n", name);
	}

	~Human() {
		printf("%s ��ü�� �ı��Ǿ����ϴ�.\n", name);

		delete[] name;
	}

	void intro()
	{
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

int main()
{
	Human boy("����ѹ��ź��̿͵η��", 12);
	boy.intro(); // . �ȿ� �ִ� ������ �Լ��� ����ϴ� ������

	Human* leo = new Human("���������� ��ī������", 40);
	leo->intro(); // -> �������ϴ� ������
	delete leo;

	Human who;
	who.intro();

	return 0;
}