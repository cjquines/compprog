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

#define N 200011
ll a[N], n, st, ed, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 1, n) cin >> a[i];
  ans = 1;
  ed = st;
  REP(st, 1, n) {
    if (ed < st) ed = st;
    while (ed <= n-1 && (a[ed+1] <= 2*a[ed])) ed++;
    ans = max(ans, ed - st + 1);
  }
  cout << ans << '\n';
}