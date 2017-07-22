#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) int(c.size())
#define PB push_back
typedef long long ll;

// er yeah, um

#define N 10000000
#define N10 1000000
bitset<N10> p;
char t;
int n, q;
vector<int> pr, a(N), s(N);

int inv(int n) {
  int res = 0;
  while (n) res *= 10, res += n % 10, n /= 10;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  REP(i, 2, N10-1) if (!p[i]) {
    pr.PB(i); ll c = ll(i)*i;
    while (c < N10) p[c] = 1, c += i;
  }
  for (int i = N10 + 10; i < N; i += 10)
    if (!p[inv(i)]) {
      int j = a[n] = i;
      for (auto it : pr) {
        while (j % it == 0) s[n]++, j /= it;
        if (it * it > j) break;
      }
      if (j != 1) s[n]++;
      n++;
    }
  a.resize(n), s.resize(n);
  partial_sum(ALL(s), s.begin());
  while (cin >> t >> q) {
    if (t == 'q') cout << s[q] << '\n';
    else {
      int it = lower_bound(ALL(a), q) - a.begin();
      q = (it > 0) ? (s[it] - s[it-1]) : s[it];
      a.erase(a.begin() + it); s.erase(s.begin() + it);
      for (; it < SIZE(a); it++) s[it] -= q;
    }
  }
}