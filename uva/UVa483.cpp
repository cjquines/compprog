#include <iostream>
#include <stack>
using namespace std;

int main() {
  char curr;
  stack<char> word;
  while(scanf("%c", &curr) != EOF) {
    if (curr == ' ') {
      while(!word.empty()) {
        printf("%c", word.top());
        word.pop();
      }
      printf(" ");
    } else if (curr == '\n') {
      while(!word.empty()) {
        printf("%c", word.top());
        word.pop();
      }
      printf("\n");
    } else {
      word.push(curr);
    }
  }
  while(!word.empty()) {
    printf("%c", word.top());
    word.pop();
  }
}