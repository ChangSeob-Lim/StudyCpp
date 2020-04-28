#include <stdio.h>

enum E_Error { OUTOFMEMORY, OVERRANGE, HARDFULL, STACKFULL };

class Exception {
private:
	int ErrorCode;

public:
	Exception(int ae) : ErrorCode(ae) { ; }
	int GetErrorCode() { return ErrorCode; }

	void ReportError() {
		switch (ErrorCode)
		{
		case 1:
			puts("�޸� ����");
			break;
		case 2:
			puts("���� ���� �ʰ�");
			break;
		case 3:
			puts("�ϵ� ��ũ �� ��");
			break;
		default:
			break;
		}
	}
};

void report()
{
	//if (true) throw HARDFULL;
	if (true) throw Exception(3);

	// ������� ������ ������ �۾� �Ϸ�����
}

int main()
{
	try
	{
		report();
		puts("�۾��Ϸ�");
	}
	catch (E_Error e)
	{
		switch (e)
		{
		case OUTOFMEMORY:
			puts("�޸� ����");
			break;
		case OVERRANGE:
			puts("���� ���� �ʰ�");
			break;
		case HARDFULL:
			puts("�ϵ� ��ũ �� ��");
			break;
		case STACKFULL:
			puts("���� �� ��");
			break;
		default:
			break;
		}
	}
	catch (Exception& e)
	{
		printf("���� �ڵ� = %d => ", e.GetErrorCode());
		e.ReportError();
	}

	return 0;
}