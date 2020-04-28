#include <stdio.h>
#include <exception>
#include <stdlib.h>

using namespace std;

void myterm() {
	puts("처리되지 않은 예외 발생");
	exit(-1);
}

int main()
{
	set_terminate(myterm);

	try
	{
		throw 1234;
	}
	catch (unsigned a)
	{
		printf("%d에 대한 예외 발생\n", a);
	}
}