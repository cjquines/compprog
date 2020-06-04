#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
typedef unsigned long long ll;

int t;
ll n, k, res1, res2;

ll magic(ll x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  x++;
  return x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  REP(i, 1, t) {
    cin >> n >> k;
    n -= k;
    k = magic(k);
    res2 = res1 = n / k;
    if (n % k * 2 >= k) res1++;
    cout << "Case #" << i << ": " << res1 << ' ' << res2 << '\n';
  }
}