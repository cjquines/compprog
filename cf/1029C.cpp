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

// intersection is max(L), min(R)

#define N 300011
ll l[N], r[N], n, res;
ll mxl, mxl2, mnr, mnr2;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 1, n) cin >> l[i] >> r[i];
  mxl = l[1]; mxl2 = l[2];
  if (mxl < mxl2) swap(mxl, mxl2);
  mnr = r[1]; mnr2 = r[2];
  if (mnr > mnr2) swap(mnr, mnr2);
  REP(i, 3, n) {
    if (l[i] > mxl) {
      mxl2 = mxl;
      mxl = l[i];
    } else if (l[i] > mxl2) mxl2 = l[i];
    if (r[i] < mnr) {
      mnr2 = mnr;
      mnr = r[i];
    } else if (r[i] < mnr2) mnr2 = r[i];
  }
  res = 0;
  REP(i, 1, n) {
    if (l[i] == mxl && r[i] == mnr) {
      res = max(res, max(ll(0), mnr2 - mxl2));
    } else if (l[i] == mxl) {
      res = max(res, max(ll(0), mnr - mxl2));
    } else if (r[i] == mnr) {
      res = max(res, max(ll(0), mnr2 - mxl));
    } else {
      res = max(res, max(ll(0), mnr - mxl));
    }
  }
  cout << res << endl;
}