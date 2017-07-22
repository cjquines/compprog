#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define EB emplace_back
#define F first
#define S second

// this is a DAG, so we can use DP: O(V+E).
// sorry for not using this week's lessons :( :(

#define N 1011
int n, x, y, w;
vector<double> d;
vector<int> pn;
vector<pair<int, int>> pt;

int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(3);
  while (cin >> n, n) {
    vector<double>(N, HUGE_VAL).swap(d);
    vector<int>(1,0).swap(pn);
    vector<pair<int, int>>(1,{0,0}).swap(pt);
    REP(i, 1, n) cin >> x >> y >> w, pt.EB(x, y), pn.EB(w);
    pt.EB(100,100);
    partial_sum(pn.begin(), pn.end(), pn.begin());
    d[0] = 0;
    REP(i, 1, n+1) REP(j, 0, i-1)
      d[i] = min(d[i], d[j] + pn[i-1] - pn[j] + 1
        + hypot(pt[i].F-pt[j].F, pt[i].S-pt[j].S));
    cout << d[n+1] << '\n';
  }
}