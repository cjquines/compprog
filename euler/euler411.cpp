// LIS on the sorted list of stations, the sorting operation being 
// non-decreasing in both x and y coordinates. This is N lg N and
// N = sum i^5 1..30 ~ 1.3e8. In practice, this runs X on my laptop.

#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PER(i, a, b) for (int(i) = int(a); (i) >= int(b); (i)--)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f3f3f
#define EB emplace_back
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii arr;

int lis() {
  vi lst{0};
  for (int i = 1; i < SIZE(arr); i++) {
    auto it = lower_bound(ALL(lst), i,
      [&](const int &l, const int &r) {
        return (arr[l].F <= arr[r].F) && (arr[l].S <= arr[r].S);
      });
    if (it != lst.end()) *it = i;
    else lst.push_back(i);
  }
  return SIZE(lst);
}

int modpow(int b, int e, int m) {
  if (e == 0) return 1;
  if (e == 1) return b;
  if (e & 1) return (b*modpow(b, e-1, m)) % m;
  int b2 = modpow(b, e/2, m);
  return (b2*b2) % m;
}

int main() {
  ios_base::sync_with_stdio(0);
  int res = 1;
  REP(i, 5, 5) {
    int k = i*i*i*i*i;
    REP(j, 0, 2*k) arr.EB(modpow(2, j, k), modpow(3, j, k));
    sort(ALL(arr));
    auto it = unique(ALL(arr));
    arr.erase(it, arr.end());
    res += lis();
    cout << "RESULT " << i << ' ' << res << endl;
  }
}