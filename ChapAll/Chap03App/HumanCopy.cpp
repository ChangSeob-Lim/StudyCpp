#include <stdio.h>
#include <string.h>

class Human {
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	Human(const Human& other) {
		// 복사 생성자 -> 기본적으로 생성되지만 복사시에 2중으로 메모리를 해제하는 경우를 막아준다.
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human() {
		delete[] pname;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

void printHuman(Human who)
{
	who.intro();
}

int main()
{
	Human kang("강감찬", 1424);
	Human boy = kang; // assign, copy

	//boy.intro();
	printHuman(boy);

	return 0;
}