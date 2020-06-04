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

#define N 511
bitset<N> t[N];
char b[N][N];
int n, m, k, fs, ls;
ii q[N*N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  memset(q, -1, sizeof(q));
  #define IND(i, j) n*(i) + (j)
  REP(i, 0, n-1) REP(j, 0, m-1) cin >> b[i][j];
  REP(i, 0, n-1) REP(j, 0, m-1)
    if (b[i][j] == '.') { q[ls].F = i, q[ls].S = j, t[i][j] = 1, ls++; goto endloop; }
endloop:
  while (fs < ls) {
    int i = q[fs].F, j = q[fs].S; fs++;
    REP(k, 0, 3) {
      int I = i + dx[k], J = j + dy[k];
      if (min(I, J) >= 0 && I < n && J < m && b[I][J] == '.' && !t[I][J])
        q[ls].F = I, q[ls].S = J, t[I][J] = 1, ls++;
    }
  }
  while (k--) {
    ls--;
    b[q[ls].F][q[ls].S] = 'X';
  }
  REP(i, 0, n-1) {
    REP(j, 0, m-1) cout << b[i][j];
    cout << '\n';
  }
}