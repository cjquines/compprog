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

int t, k;
string s, first[6];
vector<char> same[6], res;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> k;
    memset(same, 0, sizeof(same));
    vector<char>().swap(res);
    REP(i, 0, 5) cin >> first[i];
    REP(i, 0, 5) {
      cin >> s;
      REP(j, 0, 4) REP(k, 0, 5) {
        if (s[j] == first[k][j]) {
          same[j].PB(s[j]); break;
        }
      }
    }
    k--;
    PER(i, 4, 0) {
      sort(ALL(same[i]));
      same[i].erase(unique(ALL(same[i])), same[i].end());
      // for (auto j : same[i]) cout << j << ' '; cout << endl;
      if (!SIZE(same[i])) goto deads;
      res.PB(same[i][k % SIZE(same[i])]);
      // cout << k << endl;
      k /= SIZE(same[i]);
    }
    if (k > 0) cout << "NO\n";
    else { PER(i, 4, 0) cout << res[i]; cout << '\n'; }
    continue;
deads:
    cout << "NO\n";
  }
}