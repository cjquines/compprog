#import <iostream>
using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

char row1[13] = "`1234567890-="
char row2[13] = "QWERTYUIOP[]\\"
char row3[11] = "ASDFGHJKL;'"
char row4[10] = "ZXCVBNM,./"

int main() {
  char curr;
  while (scanf("%c", &curr) != EOF) {
    if (curr == ' ' || curr == '\n') {
      printf("%c", curr);
    } else {
      REP(i, 1, 12) if (curr == row1[i]) printf("%c", row[i - 1]);
      REP(i, 1, 12) if (curr == row2[i]) printf("%c", row[i - 1]);
      REP(i, 1, 10) if (curr == row3[i]) printf("%c", row[i - 1]);
      REP(i, 1, 9) if (curr == row4[i]) printf("%c", row[i - 1]);
    }
  }
}