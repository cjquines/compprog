#include <bits/stdc++.h>
using namespace std;

int main() {
  map<set<int>, int> frosh;
  set<int> temp;
  int n, c1, c2, c3, c4, c5, ans, max;
  while (scanf("%d", &n), n) {
    map<set<int>, int>().swap(frosh);
    max = ans = -1;
    while (n--) {
      scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);
      frosh[set<int>{c1, c2, c3, c4, c5}]++;
    }
    for (auto it : frosh) {
      if (it.second > max) max = ans = it.second;
      else if (it.second == max) ans += it.second;
    }
    printf("%d\n", ans);
  }
}