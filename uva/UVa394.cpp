#include <iostream>
using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  char arrnames[n][10];
  int arrays[n][10];
  int arrsize[n];

  int B, D, C_D, L_d, U_d;

  REP(i, 0, n - 1) {
    scanf("%s %i %i %i", &arrnames[i][], &B, &C_D, &D);
    arrays[i][D] = C_D;
    arrays[i][0] = B;
    arrsize[i] = D;
    for (int j = D - 1; j >= 1; j--) {
      scanf("%i %i", &L_d, &U_d);
      arrays[i][j] = arrays[i][j + 1] * (U_d - L_d + 1);
      arrays[i][0] -= arrays[i][j] * L_d;
    }
  }

  printf("%s", arrnames[1][]);

  char current[10];
  int curr;

  while (r--) {
    scanf("%s", &current[]);
    REP(i, 0, n - 1) {
      bool flag = true;
      REP(j, 0, 9) {
        if (current[j] != arrnames[i][j]) {
          flag = false;
        }
      }
      if (flag) {
        curr = i;
        break;
      }
    }
    printf("%d", curr);
  }
}