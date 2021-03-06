#include <vector>
#include <numeric>
#include <iostream>
#include <map>
using namespace std;

enum struct ITEMTYPE : short
{
	WEAPON,
	EQUIPMENT,
	GEM = 10,
	DEFENSE
};

void func(int a)
{
	cout << "func int " << a << endl;
}

void func(double* p)
{
	cout << "func double* " /*<< *p*/ << endl;
}

class TEST
{
public:
	TEST() { ; }
	TEST(int an1, string as1) : n1(an1), s1(as1) { ; }
	void print() { cout << n1 << ", " << s1 << endl; }
//private:
	int n1 = 100;
	string s1 = "test class";
};

int sum(initializer_list<int> li) {
	return accumulate(li.begin(), li.end(), 0);
}

class TEST2 {
public:
	void f1(int i) { cout << i << endl; }
	void f1(double d) = delete; // 쓰지 않겠다고 정의
};

class Base {
public:
	virtual void foo(int i) final;
};

class Derived : public Base {
public:
	//virtual void foo(int i) override; // final 재정의 안하겠다 선언했기때문에 에러
	//virtual void foo(double d) override; // 부모 클래스에서 정의된게 없어서 에러
};

/*constexpr*/const double pow(double x, size_t y) {
	return y != 1 ? x * pow(x, y - 1) : x;
}

int wmain(int argc, wchar_t* argv)
{
	cout << pow(2.0, 2) << endl;
	cout << pow(3.0, 6) << endl;

	ITEMTYPE ItemType1 = ITEMTYPE::EQUIPMENT;//DEFENSE;

	cout << "ItemType1 = " << static_cast<short>(ItemType1) << endl;

	char* p = nullptr;//NULL;
	double* d = NULL;

	func(0);
	func(d);
	func(nullptr);

	cout << "size of nullptr " << sizeof(nullptr) << endl;
	cout << "type of nullptr " << typeid(nullptr).name() << endl;

	// 생성자
	TEST test1(200, "new test");
	TEST test2;

	test1.print();
	test2.print();

	TEST test3{ 300, "삼백" };
	test3.print();

	string str1{ "Hello 1" };
	string str2 = "Hello 2";

	pair<int, string> p1{ 400, "사백" };

	//vector<int> v1{1,2,3,4,5 };
	vector<pair<int, string>> pv{
		pair<int,string>{1, "일"},
		pair<int,string>{2, "이"},
		pair<int,string>{3, "삼"},
		pair<int,string>{4, "사"},
		pair<int,string>{5, "오"},
	};
	//pv.push_back(pair<int, string>{6, "육"});
	pv.emplace_back(pair<int, string>{6, "육"});

	for (auto& atom : pv)
	{
		cout << atom.first << ", " << atom.second << " : ";
	}cout << endl;

	/*map<string, int> m;
	m.insert(make_pair("a", 1));
	m.insert(make_pair("b", 2));
	m.insert(make_pair("c", 3));
	m.insert(make_pair("d", 4));
	m.insert(make_pair("e", 5));
	m.insert(make_pair("f", 6));*/
	map<string, int> m = {
		pair<string,int>{"a", 1},
		pair<string,int>{"b", 2},
		pair<string,int>{"c", 3},
		pair<string,int>{"d", 4},
		pair<string,int>{"e", 5},
		pair<string,int>{"f", 6}
	};

	for (auto& atom : m)
	{
		cout << "key: " << atom.first << " value: " << atom.second << endl;
	}

	cout << "result of accumulate " << sum({ 1,2,3,4,5 }) << endl;

	TEST2 test2_1;
	test2_1.f1(1);
	//test2_1.f1(3.14);

	string str = "Hello";
	vector<string> v8;
	v8.emplace_back(str);
	v8.emplace_back(4, 'a');
	v8.push_back({ str[0], 'l' });

	for (auto& i : v8)
	{
		cout << i << " / ";
	}cout << endl;

	return 0;
}