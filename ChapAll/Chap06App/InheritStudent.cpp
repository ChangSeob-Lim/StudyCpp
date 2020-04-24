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
		printf("이름 = %s, 나이 = %d\n", name, age);
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
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}

	void report() {
		printf("이름 : %s, 학번: %d 보고서 제출합니다.\n", name, stunum);
	}

	void intro() {
		Human::intro();
		printf("%d학번 %s입니다.\n", stunum, Human::name);
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
		printf("%s를 연구하고 논문을 쓴다.\n", thesis);
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
		printf("키 %d, 몸무게 %d 인 %s 선수입니다.\n", height, weight, name);
	}

	void fight() {
		puts("레프트, 라이트, 쨉쨉\n");
	}
};

int main()
{
	/*Human lim("임창섭", 26);
	lim.intro();*/

	/*Student seob("섭섭", 22, 14);
	seob.intro();
	seob.study();
	seob.report();*/

	/*Graduate G("임창섭", 26, 14, "수학");
	G.intro();
	G.research();*/

	Boxer park("박종팔", 61, 178, 65);
	park.intro();
	park.fight();

	return 0;
}