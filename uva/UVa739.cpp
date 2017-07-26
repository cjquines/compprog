// 9:51 PM - 10:37 PM
#include <iostream>
#include <cstring>
using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

int main() {
  printf("         NAME                     SOUNDEX CODE\n");
  char name[20];
  char code[4];
  REP(i, 0, 19) {
    name[i] = ' ';
  }
  while (scanf("%s", &name) != EOF) {
    int spot = 1;
    char last;
    bool flag = false;
    code[0] = name[0];
    if (name[0] == 'A' || name[0] == 'E' || name[0] == 'I' \
      || name[0] == 'O' || name[0] == 'U' || name[0] == 'Y' \
      || name[0] == 'W' || name[0] == 'H') {
      flag = true;
    } else if (name[0] == 'B' || name[0] == 'P' \
      || name[0] == 'F' || name[0] == 'X') {
      last = '1';
    } else if (name[0] == 'C' || name[0] == 'S' \
      || name[0] == 'K' || name[0] == 'G' || name[0] == 'J' \
      || name[0] == 'Q' || name[0] == 'X' || name[0] == 'Z') {
      last = '2';
    } else if (name[0] == 'D' || name[0] == 'T') {
      last = '3';
    } else if (name[0] == 'L') {
      last = '4';
    } else if (name[0] == 'M' || name[0] == 'N') {
      last = '5';
    } else if (name[0] == 'R') {
      last = '6';
    } 
    REP(i, 1, 19) {
      if (spot == 4) break;
      if (name[i] == 'A' || name[i] == 'E' || name[i] == 'I' \
        || name[i] == 'O' || name[i] == 'U' || name[i] == 'Y' \
        || name[i] == 'W' || name[i] == 'H') {
        flag = true;
      } else if (name[i] == 'B' || name[i] == 'P' \
        || name[i] == 'F' || name[i] == 'V') {
        if (last == '1' && !flag) {
          
        } else {
          code[spot] = '1';
          last = '1';
          flag = false;
          spot++;
        }
      } else if (name[i] == 'C' || name[i] == 'S' \
        || name[i] == 'K' || name[i] == 'G' || name[i] == 'J' \
        || name[i] == 'Q' || name[i] == 'X' || name[i] == 'Z') {
        if (last == '2' && !flag) {
          
        } else {
          code[spot] = '2';
          last = '2';
          flag = false;
          spot++;
        }
      } else if (name[i] == 'D' || name[i] == 'T') {
        if (last == '3' && !flag) {
          
        } else {
          code[spot] = '3';
          last = '3';
          flag = false;
          spot++;
        }
      } else if (name[i] == 'L') {
        if (last == '4' && !flag) {
          
        } else {
          code[spot] = '4';
          last = '4';
          flag = false;
          spot++;
        }
      } else if (name[i] == 'M' || name[i] == 'N') {
        if (last == '5' && !flag) {
          
        } else {
          code[spot] = '5';
          last = '5';
          flag = false;
          spot++;
        }
      } else if (name[i] == 'R') {
        if (last == '6' && !flag) {
          
        } else {
          code[spot] = '6';
          last = '6';
          flag = false;
          spot++;
        }
      }
    }
    while (spot < 4) {
      code[spot] = '0';
      spot++;
    }
    printf("         ");
    printf("%s", name);
    // 25 - strlen
    REP(i, 0, 24 - strlen(name)) {
      printf(" ");
    }
    REP(i, 0, 3) {
      printf("%c", code[i]);
    }
    printf("\n");
    REP(i, 0, 19) {
      name[i] = ' ';
    }
  }
  printf("                   END OF OUTPUT");
}