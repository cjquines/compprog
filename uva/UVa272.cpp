#include <iostream>
using namespace std;

int main() {
  bool test = true;
  char c;
  while (scanf("%c", &c) != EOF) {
    if (c == '"') {
      if (test) {
        printf("``");
        test = false;
      } else {
        printf("''");
        test = true;
      }
    } else {
      printf("%c", c);
    }
  }
  return 0;
}