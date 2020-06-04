#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define N 1011

bool flag;
bitset<N> p;
int t, k, l, res;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  REP(h, 1, t) {
    cin >> s >> k;
    l = res = flag = 0;
    for (; s[l]; l++) p[l] = int(s[l] == '+');
    REP(i, 0, l-k) if (!p[i]) {
      res++;
      REP(j, i, i+k-1) p.flip(j);
    }
    REP(i, l-k+1, l-1) if (!p[i]) flag = 1;
    if (!flag) cout << "Case #" << h << ": " << res << '\n';
    else cout << "Case #" << h << ": IMPOSSIBLE\n";
  }
}