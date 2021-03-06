#include <stdio.h>
#include <string.h>

class Date
{
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d/%d/%d", year, month, day); }
};

//class Product {
//private:
//	char name[64];
//	char company[32];
//	Date validto;
//	int price;
//
//public:
//	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) :validto(y, m, d) {
//		strcpy(name, aname);
//		strcpy(company, acompany);
//		price = aprice;
//	}
//
//	void OutProduct() {
//		printf("이름:%s\n", name);
//		printf("제조사:%s\n", company);
//		printf("유효기간:");
//		validto.OutDate();
//		puts("");
//		printf("가격:%d\n", price);
//	}
//};

// 포함 = private와 비슷하다.
class Product : public Date{
private:
	char name[64];
	char company[32];
	int price;

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) :Date(y, m, d) {
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}

	void OutProduct() {
		printf("이름:%s\n", name);
		printf("제조사:%s\n", company);
		printf("유효기간:");
		Date::OutDate();
		puts("");
		printf("가격:%d\n", price);
	}
};

int main()
{
	Product shrimp("새우깡", "농심", 2020, 8, 15, 1200);
	shrimp.OutProduct();
	shrimp.OutDate(); // public Date와 private의 차이

	return 0;
}