#include <stdio.h> // 표준 헤더파일이라 < >
#include "cursor.h" // 만든거라 " "

class RandNum
{
private:
   int num;

public:
   RandNum() { randomize(); }
   void Generate() { num = random(100) + 1; } 
   BOOL Compare(int input) {
      if (input == num) {
         printf("맞췄습니다.\n");
         return TRUE;
      }
      else if (input > num) {
         printf("입력한 숫자보다 더 작습니다.\n");
      }
      else {
         printf("입력한 숫자보다 더 큽니다.\n");
      }
      return FALSE;
   }
};

class Ask 
{
private:
   int input;

public:
   void Prompt() { printf("\n제가 만든 숫자를 맞춰 보세요.\n"); }
   BOOL AskNumber() {
      printf("숫자를 입력하세요(끝낼 때는 999) : ");
      scanf("%d", &input);
      if (input == 999) {
         return TRUE;
      }
      return FALSE;
   }
   int GetInput() { return input; }
};

int main()
{
   RandNum R; // 클래스 선언
   Ask A;

   while (1) { // 무한루프
      R.Generate(); // 정의로 이동 F12, Back은 Ctrl + -
      A.Prompt();
      for (;;) {
         if (A.AskNumber()) {
            exit(EXIT_SUCCESS); // 빠져나오는 거, EXIT_SUCCESS 대신 0을 써도 됨
         }
         if (R.Compare(A.GetInput())) {
            break;
         }
      }
   }
}