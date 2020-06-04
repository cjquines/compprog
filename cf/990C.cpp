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

typedef pair<ii, int> iii;

const int N = 300111;
ll n, res;
ii d[N];
vector<iii> dd;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 0, n-1) {
    cin >> s;
    STREP(j, s) {
      d[i].F += (s[j] == '(') ? 1 : -1;
      d[i].S = min(d[i].S, d[i].F);
    }
  }
  sort(d, d + n);
  // REP(i, 0, n-1) {
  //   cout << d[i].F << ' ' << d[i].S << endl;
  // }
  dd.EB(ii(d[0].F, d[0].S), 1);
  REP(i, 1, n-1) {
    if (d[i].F != d[i-1].F || d[i].S != d[i-1].S)
      dd.EB(ii(d[i].F, d[i].S), 1);
    else dd.rbegin()->S++;
  }
  int i = 0, j = SIZE(dd)-1;
  for (; i < SIZE(dd) && j >= 0; i++) {
    if (dd[i].F.F == 0 && dd[i].F.S == 0) break;
    while (j >= 0 && dd[i].F.F + dd[j].F.F > 0) j--;
    if (j < 0) break;
    if (dd[j].F.F == 0 && dd[j].F.S == 0) break;
    // cout << i << j << endl;
    if (dd[i].F.F + dd[j].F.F == 0 && dd[j].F.S >= 0 && dd[j].F.F + dd[i].F.S >= 0)
      res += ll(dd[i].S) * ll(dd[j].S);
  }
  if (dd[i].F.F == 0 && dd[i].F.S == 0) res += ll(dd[i].S) * ll(dd[i].S);
  else if (dd[j].F.F == 0 && dd[j].F.S == 0) res += ll(dd[j].S) * ll(dd[j].S);
  cout << res << endl;
}