#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fo;

	fo.open("C:\\temp\\cpptest.txt");

	if (fo.is_open())
	{
		cout << "파일 열기 성공" << endl;
		fo << "입력해 넣을 문자열 : " << 3.141592 << endl;
		fo.close();
	}
	else
	{
		cerr << "파일 열기 실패" << endl;
	}

	ifstream fi;
	char str[128];
	int i = 0;

	fi.open("C:\\temp\\cpptest.txt");

	if (fi.is_open())
	{
		cout << "파일 열기 성공" << endl;
		fi.getline(str, 128);
		cout << str << i << endl;
		fi.close();
	}
	else
	{
		cerr << "파일 열기 실패" << endl;
	}

	return 0;
}