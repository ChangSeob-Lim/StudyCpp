#include <stdio.h>
#include <exception>

using namespace std;

void myunex() {
	puts("�ٽ� ���� �߻�");
	exit(-2);
}

void report() {
	try
	{
		// logic
	}
	catch (const std::exception&)
	{

	}
	//throw e;
}

void calc() throw(int) {
	// ...
	// throw "string";
	try
	{
		report();
	}
	catch (const std::exception&)
	{

	}
}

int main()
{
	set_terminate(myunex);

	try
	{
		calc();
	}
	catch (int)
	{
		puts("������ ���� �߻�");
	}

	puts("���α׷� ����");

	return 0;
}