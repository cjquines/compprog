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

char a[3000011];
int n, k, x, lst, len;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  len = -1;
  while (n--) {
    cin >> s >> k >> x; k--;
    STREP(i, s) a[x+i] = s[i];
    lst = x + int(s.length()) - 1;
    while (k--) {
      cin >> x;
      REP(i, max(lst+1, x), x + int(s.length()) - 1)
        a[i] = s[i - x];
      lst = x + int(s.length()) - 1;
    }
    len = max(len, lst);
  }
  REP(i, 1, len) {
    if (!a[i]) cout << 'a';
    else cout << a[i];
  }
  cout << endl;
}