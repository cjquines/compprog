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

#define N 100011
int n, a[N], d[N], r[N];
vi eq;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 1, n) cin >> a[i];
  eq.PB(1);
  REP(i, 2, n) {
    if (a[i] > a[i-1]) d[i] = d[i-1] + 1;
    else if (a[i] < a[i-1]) d[i] = d[i-1] - 1;
    else { d[i] = 0; eq.PB(i); }
  }
  eq.PB(n+1);
  for (auto l = eq.begin(); l != eq.end(); l++) {
    if (*l == n+1) break;
    auto r = l; r++;
    int mn = d[*l];
    REP(i, *l, (*r) - 1) { mn = min(mn, d[i]); }
    REP(i, *l, (*r) - 1) { r[i] = mn + a[i]; }
  }
  REP(i, 1, n) cout << r[i] << ' ';
}