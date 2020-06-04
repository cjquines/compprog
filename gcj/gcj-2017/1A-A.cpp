#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f3f3f
#define EB emplace_back
#define MP make_pair
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool sempty = 1, lstempty = 1, found = 0;
int t, r, c, debt;
string s, lst;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  REP(k, 1, t) {
    cin >> r >> c;
    cout << "Case #" << k << ":" << endl;
    sempty = lstempty = 1;
    debt = 0;
    REP(i, 1, r) {
      cin >> s;
      int j = 0;
      found = 0;
      for (; j <= c-1; j++) if (s[j] != '?') {
        found = 1;
        break;
      }
      if (!found) {
        if (!lstempty) s = lst, sempty = 0;
        else debt++;
      } else {
        REP(n, 0, j-1) s[n] = s[j];
        for (int n = j; s[n]; n++) {
          if (s[n] == '?') {
            s[n] = s[j];
          } else {
            j = n;
          }
        }
        lst = s;
        lstempty = 0;
        sempty = 0;
      }
      if (!sempty) {
        REP(i, 0, debt) cout << s << endl;
        debt = 0;
      }
    }
  }
}