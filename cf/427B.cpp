#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f
#define EB emplace_back
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

char x;
int k, sm, ans, d[10], pt;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> k;
  while (cin >> x) d[x - '0']++;
  REP(i, 0, 9) sm += i*d[i];
  while (sm < k) {
    while (d[pt] == 0) pt++;
    sm += 9 - pt;
    d[pt]--;
    ans++;
  }
  cout << ans << endl;
}