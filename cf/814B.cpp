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

#define N 1001
bitset<N> seen;
int n, a[N], b[N], m1, m2, s1, s2;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 1, n) cin >> a[i];
  REP(i, 1, n) cin >> b[i];
  REP(i, 1, n) {
    if (a[i] == b[i]) seen[a[i]] = 1;
    else if (!m1) m1 = i;
    else m2 = i;
  }
  if (!m2) {
    REP(i, 1, m1-1) cout << a[i] << ' ';
    REP(i, 1, n) if (!seen[i]) cout << i << ' ';
    REP(i, m1+1, n) cout << a[i] << ' ';
    cout << endl;
  } else {
    REP(i, 1, n) if (!seen[i]) {
      if (!s1) s1 = i;
      else s2 = i;
    }
    // case 1: m1 = s1 and m2 = s2
    if (((a[m1] == s1)^(a[m2] == s2)) == 1 &&
        ((b[m1] == s1)^(b[m2] == s2)) == 1) {
      REP(i, 1, m1-1) cout << a[i] << ' ';
      cout << s1 << ' ';
      REP(i, m1+1, m2-1) cout << a[i] << ' ';
      cout << s2 << ' ';
      REP(i, m2+1, n) cout << a[i] << ' ';
      cout << endl;
    } else {
      REP(i, 1, m1-1) cout << a[i] << ' ';
      cout << s2 << ' ';
      REP(i, m1+1, m2-1) cout << a[i] << ' ';
      cout << s1 << ' ';
      REP(i, m2+1, n) cout << a[i] << ' ';
      cout << endl;
    }
  }
}