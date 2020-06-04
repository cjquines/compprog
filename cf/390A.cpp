#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> x, y;
  int n, cx, cy;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &cx, &cy);
    x.insert(cx);
    y.insert(cy);
  }
  printf("%d", min(x.size(), y.size()));
}