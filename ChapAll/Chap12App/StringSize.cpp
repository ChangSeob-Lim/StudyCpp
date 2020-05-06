#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ String");

	cout << s << "\t문자열 길이 : " << s.size() << endl;
	cout << s << "\t문자열 길이 : " << s.length() << endl;
	cout << s << "\t문자열 할당길이 : " << s.capacity() << endl;
	cout << s << "\t문자열 최대길이 : " << s.max_size() << endl;

	cout << endl << s << endl;
	cout << boolalpha << s.empty() << endl;
	s.clear();
	cout << s << endl;
	cout << boolalpha << s.empty() << endl;

	printf("%s\n", "Hello");

	return 0;
}