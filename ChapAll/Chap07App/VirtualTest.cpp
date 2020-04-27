#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class Human
{
protected:
    char name[12];
    int age;

public:
    Human(const char* aname, int aage)
    {
        strcpy(name, aname); //값 초기화
        age = aage;
    }

    virtual void intro()
    {
        printf("%s은(는) %d살 입니다.\n", name, age);
    }
};

class Student : public Human
{
protected:
    int stunum;

public:
    Student(const char* aname, int aage, int astunum) : Human(aname, aage)
    {
        stunum = astunum;
    }

    void intro()
    {
        printf("%d번 %s 입니다.\n", stunum, name);
    }
};

int main()
{
    Human h("임창섭", 26);
    Student s("섭섭", 26, 14);

    Human* pH;
    Student* pS;

    //printf("Human size : %d, Student size : %d\n", sizeof(h), sizeof(s));

    pH = &h;
    pH->intro();

    pS = &s;
    pS->intro();

    pH = &s;
    pH->intro();

    pS = (Student*)&h;
    pS->intro(); //IS A 관계 형변환 virtual

    int sel;


    while (1)
    {
        cout << "원하는 수를 고르세요(1 : Human | 2 : Student | 9 : 종료) : ";
        cin >> sel;

        if (sel == 1)
        {
            pH = &h;
        }
        else if (sel == 2)

        {
            pH = &s;
        }
        else if (sel == 9)
        {
            exit(-1);
        }
        else
        {
            cout << "맞는 수가 없습니다" << endl;
            exit(-1);
        }

        pH->intro();
    }

    return 0;
}