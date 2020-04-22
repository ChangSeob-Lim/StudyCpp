#include <stdio.h>
#include <string.h>

class Human {
private:
	char* name;
	int age;

public:
	//Human() {
	//	// 디폴트 생성자
	//	name = new char[strlen("이름없음") + 1];
	//	strcpy(name, "이름없음");
	//	age = 0;
	//}

	Human(const char* aname = "이름없음", int aage = 0) {
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;

		printf("%s 객체의 생성자가 호출되었습니다.\n", name);
	}

	~Human() {
		printf("%s 객체가 파괴되었습니다.\n", name);

		delete[] name;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human boy("김수한무거북이와두루미", 12);
	boy.intro(); // . 안에 있는 변수나 함수를 사용하는 연산자

	Human* leo = new Human("레오나르도 디카프리오", 40);
	leo->intro(); // -> 포인팅하는 연산자
	delete leo;

	Human who;
	who.intro();

	return 0;
}