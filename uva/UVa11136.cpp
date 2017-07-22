#include <bits/stdc++.h>
using namespace std;

int main() {
  multiset<int> bills;
  long long ans;
  int n, k, t;
  while (scanf("%d", &n), n) {
    multiset<int>().swap(bills);
    ans = 0;
    while (n--) {
      scanf("%d", &k);
      while (k--) scanf("%d", &t), bills.insert(t);
      t = *bills.rbegin();
      ans += t - *bills.begin();
      bills.erase(bills.begin());
      bills.erase(bills.find(t));
    }
    printf("%lld\n", ans);
  }
}