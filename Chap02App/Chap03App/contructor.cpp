#include <stdio.h>
#include <string.h>

class Human {
private:
	char name[12];
	int age;

public:
	// 생성자
	Human(const char* name, int age){
		strcpy(this->name, name); // strcpy(Human::name, name);
		this->age = age; // Human::age = age;
	}

	void intro()
	{
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human h = Human("임창섭", 26);
	h.intro();

	return 0;
}