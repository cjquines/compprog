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

#define N 2017
ll t, n, a[N], lis[N], lds[N], res;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    res = 0;
    PER(i, n, 1) cin >> a[i];
    REP(i, 1, n) {
      lis[i] = lds[i] = 0;
      REP(j, 1, i-1) {
        if (a[j] < a[i]) lis[i] = max(lis[i], lis[j]);
        else lds[i] = max(lds[i], lds[j]);
      }
      lis[i]++; lds[i]++;
      res = max(res, lis[i] + lds[i]);
    }
    if (n) cout << res - 1 << '\n';
    else cout << 0 << '\n';
  }
}