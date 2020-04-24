#include <stdio.h>
#include <string.h>

class Human {
//private:
protected:
	char name[12];
	int age;

public:
	Human() { ; }
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Student :public Human {
private:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		/*strcpy(name, aname);
		age = aage;*/
		stunum = astunum;
	}

	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}

	void report() {
		printf("�̸� : %s, �й�: %d ���� �����մϴ�.\n", name, stunum);
	}

	void intro() {
		Human::intro();
		printf("%d�й� %s�Դϴ�.\n", stunum, Human::name);
	}
};

class Graduate : public Student {
protected:
	char thesis[40];

public:
	Graduate(const char* aname, int aage, int astunum, const char* athesis) : Student(aname, aage, astunum) {
		strcpy(thesis, athesis);
	}

	void research() {
		printf("%s�� �����ϰ� ���� ����.\n", thesis);
	}
};

class Boxer : public Human {
protected:
	int height, weight;

public:
	Boxer(const char* aname, int aage, int aheight, int aweight) : Human(aname, aage) {
		height = aheight;
		weight = aweight;
	}
	
	void intro() {
		printf("Ű %d, ������ %d �� %s �����Դϴ�.\n", height, weight, name);
	}

	void fight() {
		puts("����Ʈ, ����Ʈ, µµ\n");
	}
};

int main()
{
	/*Human lim("��â��", 26);
	lim.intro();*/

	/*Student seob("����", 22, 14);
	seob.intro();
	seob.study();
	seob.report();*/

	/*Graduate G("��â��", 26, 14, "����");
	G.intro();
	G.research();*/

	Boxer park("������", 61, 178, 65);
	park.intro();
	park.fight();

	return 0;
}