#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fo;

	fo.open("C:\\temp\\cpptest.txt");

	if (fo.is_open())
	{
		cout << "���� ���� ����" << endl;
		fo << "�Է��� ���� ���ڿ� : " << 3.141592 << endl;
		fo.close();
	}
	else
	{
		cerr << "���� ���� ����" << endl;
	}

	ifstream fi;
	char str[128];
	int i = 0;

	fi.open("C:\\temp\\cpptest.txt");

	if (fi.is_open())
	{
		cout << "���� ���� ����" << endl;
		fi.getline(str, 128);
		cout << str << i << endl;
		fi.close();
	}
	else
	{
		cerr << "���� ���� ����" << endl;
	}

	return 0;
}