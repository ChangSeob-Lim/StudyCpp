#include <iostream>
using namespace std;

int main()
{
	int i;
	char str[128];
	char ch;

	cout << "정수를 입력하세요 : ";
	cin >> i;
	//cout << "입력된 정수 : " << i << endl;

	// 띄어쓰기 불가
	/*cout << "문자열을 입력하세요 : ";
	cin >> str;
	cout << "입력된 문자열 : " << str << endl;

	cin.get(ch);

	cout << "문자을 입력 : ";
	cin.get(ch);
	cout << "입력된 문자 : " << ch << endl;

	cin.get(ch);

	cout << "문자열을 입력하세요 : ";
	cin.getline(str, 128);
	cout << "입력된 문자열 : " << str << endl;*/

	if (cin.good())
	{
		cout << "입력된 정수 : " << i << endl;
	}
	else
	{
		//cout << "실패" << endl;
		cerr << "실패" << endl;
	}

	return 0;
}