#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ String");

	cout << s << "\t���ڿ� ���� : " << s.size() << endl;
	cout << s << "\t���ڿ� ���� : " << s.length() << endl;
	cout << s << "\t���ڿ� �Ҵ���� : " << s.capacity() << endl;
	cout << s << "\t���ڿ� �ִ���� : " << s.max_size() << endl;

	cout << endl << s << endl;
	cout << boolalpha << s.empty() << endl;
	s.clear();
	cout << s << endl;
	cout << boolalpha << s.empty() << endl;

	printf("%s\n", "Hello");

	return 0;
}