#include <stdio.h>
#include <exception>
#include <stdlib.h>

using namespace std;

void myterm() {
	puts("ó������ ���� ���� �߻�");
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
		printf("%d�� ���� ���� �߻�\n", a);
	}
}