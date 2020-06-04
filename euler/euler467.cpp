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

#define N 10011
bitset<N> t[N], r[N], d[N], x[N];
char a[N], b[N];
short n, scs_memo[N][N];

short scs(int i, int j) {
  if (!~scs_memo[i][j]) {
    if (i == 0 || j == 0)
      scs_memo[i][j] = max(i, j);
    else if (a[i] == b[j])
      scs_memo[i][j] = min(min(scs(i, j-1), scs(i-1, j)), scs(i-1, j-1)) + 1;
    else 
      scs_memo[i][j] = min(scs(i, j-1), scs(i-1, j)) + 1;
  }
  return scs_memo[i][j];
}

void build(int i, int j) {
  if (t[i][j]) return;
  if (i == 0 && j == 0) return;
  if (i == 0) {
    r[i][j-1] = 1;
    return build(i, j-1);
  }
  if (j == 0) {
    d[i-1][j] = 1;
    return build(i-1, j);
  }
  if (a[i] == b[j]) {
    x[i-1][j-1] = 1;
    build(i-1, j-1);
  }
  if (scs(i, j) == scs(i-1, j) + 1) {
    d[i-1][j] = 1;
    build(i-1, j);
  }
  if (scs(i, j) == scs(i, j-1) + 1) {
    r[i][j-1] = 1;
    build(i, j-1);
  }
  t[i][j] = 1;
}

void rcn(int i, int j) {
  if (x[i][j]) {
    cout << a[i+1];
    rcn(i+1, j+1);
  } else if (d[i][j] && r[i][j]) {
    if (a[i+1] < b[j+1]) {
      cout << a[i+1];
      rcn(i+1, j);
    } else {
      cout << b[j+1];
      rcn(i, j+1);
    }
  } else if (d[i][j]) {
    cout << a[i+1];
    rcn(i+1, j);
  } else if (r[i][j]) {
    cout << b[j+1];
    rcn(i, j+1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 1, n) cin >> a[i];
  REP(i, 1, n) cin >> b[i];
  memset(scs_memo, -1, sizeof(scs_memo));
  // build the scs table
  cout << scs(n, n) << endl;
  // build the graph of all possible scses
  build(n, n);

  // pretty-prints the graph
  // cout << "    ";
  // REP(j, 1, n) cout << b[j] << ' ';
  // cout << '\n';
  // REP(i, 0, n) {
  //   if (i != 0) cout << a[i] << ' ';
  //   else cout << "  ";
  //   REP(j, 0, n) {
  //     if (x[i][j] && (d[i][j] || r[i][j])) cout << '*';
  //     else if (x[i][j]) cout << '\\';
  //     else if (d[i][j] && r[i][j]) cout << '+';
  //     else if (d[i][j]) cout << 'v';
  //     else if (r[i][j]) cout << '>';
  //     else cout << ' ';
  //     // cout << scs(i, j);
  //     cout << ' ';
  //   }
  //   cout << '\n';
  // }

  // traverse graph greedily
  rcn(0, 0);
}