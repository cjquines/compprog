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

#define N 100
int n, k, a[N], t[N], ans;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> s;
  STREP(i,s) a[s[i] - 'a' + 1] = 1;
  REP(i,1,26) {
    if (a[i] && !t[i-1]) ans += i, k--, t[i] = 1;
    if (!k) break;
  }
  if (k != 0) cout << -1 << endl;
  else cout << ans << endl;
}