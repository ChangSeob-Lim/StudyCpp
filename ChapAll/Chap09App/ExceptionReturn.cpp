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
			puts("메모리 부족");
			break;
		case 2:
			puts("연산 범위 초과");
			break;
		case 3:
			puts("하드 디스크 꽉 참");
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

	// 여기까지 왔으면 무사히 작업 완료했음
}

int main()
{
	try
	{
		report();
		puts("작업완료");
	}
	catch (E_Error e)
	{
		switch (e)
		{
		case OUTOFMEMORY:
			puts("메모리 부족");
			break;
		case OVERRANGE:
			puts("연산 범위 초과");
			break;
		case HARDFULL:
			puts("하드 디스크 꽉 참");
			break;
		case STACKFULL:
			puts("스택 꽉 참");
			break;
		default:
			break;
		}
	}
	catch (Exception& e)
	{
		printf("에러 코드 = %d => ", e.GetErrorCode());
		e.ReportError();
	}

	return 0;
}