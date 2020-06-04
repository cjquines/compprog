#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> piles;
  int n, m, temp, total = 1;
  scanf("%d", &n);
  while (n--) scanf("%d", &temp), piles.push_back(temp);
  partial_sum(begin(piles), end(piles), begin(piles));
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &temp);
    printf("%d\n", distance(begin(piles),
      upper_bound(begin(piles), end(piles), temp)) + 1);
  }
}