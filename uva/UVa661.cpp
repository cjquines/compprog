// 9:11 PM - 9:18 PM / 9:45 PM - 9:48 PM
#include <iostream>
using namespace std;

#define REP(i, a, b) \
  for(int i = int(a); i <= int(b); i++)

int main() {
  int seq = 1;
  while (true) {
    int n, m, c, max, curr, appl;
    scanf("%d %d %d", &n, &m, &c);
    if (n == 0) break;
    max = 0;
    curr = 0;
    appl = 0;
    //printf("%d ", curr);
    int amperes[n], state[n];
    REP(i, 0, n - 1) {
      scanf("%d", &amperes[i]);
      state[i] = 0;
    }
    REP(i, 0, m - 1) {
      scanf("%d", &appl);
      appl--;
      if (state[appl] == 0) {
        state[appl] = true;
        curr += amperes[appl];
        if (curr > max) {
          max = curr;
        }
        //printf("%d ", curr);
      } else {
        state[appl] = false;
        curr -= amperes[appl];
        //printf("%d ", curr);
      }
    }
    printf("Sequence %d\n", seq);
    if (max > c) {
      printf("Fuse was blown.\n");
    } else {
      printf("Fuse was not blown.\n");
      printf("Maximal power consumption was %d amperes.\n", max);
    }
    printf("\n");
    seq++;
  }
}