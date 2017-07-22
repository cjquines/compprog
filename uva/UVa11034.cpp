#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<int> left, right;
  char side[11];
  int c, l, m, len, cur, res;
  scanf("%d", &c);
  while (c--) {
    res = 0;
    scanf("%d %d", &l, &m);
    l *= 100;
    while (m--) {
      scanf("%d %s", &len, side);
      if (side[0] == 'l') left.push(len);
      else right.push(len);
    }
    while (!left.empty() || !right.empty()) {
      cur = 0;
      if (res % 2) {
        while (!right.empty() && cur + right.front() < l) {
          cur += right.front();
          right.pop();
        }
      } else {
        while (!left.empty() && cur + left.front() < l) {
          cur += left.front();
          left.pop();
        }
      }
      res++;
    }
    printf("%d\n", res);
  }
}