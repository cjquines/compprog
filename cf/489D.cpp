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

#define N 3011
bitset<N> t;
int n, m, a, b, cnt[N][N], res;
vi gin[N], gout[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  REP(i, 1, m) {
    cin >> a >> b;
    gout[a].PB(b);
    gin[b].PB(a);
  }
  REP(i, 1, n)
    for (auto v : gin[i]) for (auto u : gout[i])
      cnt[v][u]++;
  REP(i, 1, n) REP(j, 1, n) if (i != j) REP(k, 1, cnt[i][j]-1)
    res += k;
  cout << res << '\n';
}