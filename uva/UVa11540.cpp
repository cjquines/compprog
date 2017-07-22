#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define STREP(i, c) for(int(i) = 0; c[(i)]; (i)++)
#define F first
#define S second
#define PB push_back
#define SZ(c) int(c.size())
#define N 111
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> ii;

// perform a left rotate on the ID of subtree until it matches
// original, say it takes r moves and subtree has n children. this
// means we need to consider symmetries in Z_(n/r). let k = n/r
// and suppose we rotated i times. gcd(i, k) is the number of fixed
// parts, find product of children 1..gcd(i,k) for this. then take
// sum of all and divide by k, orbit-counting theorem ftw.

bitset<N> tr;
int t, n, c, v;
ll res, dp[N];
string tree;
stack<ii> cur;
vector<int> ch[N], sym(N), rot(N);
vector<string> id[N];

int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  return (b == 0) ? a : gcd(a % b, b);
}

void gcdx(int a, int b, int& x, int& y) {
  if (a == 0) {
    x = 0, y = 1;
    return;
  }
  int x1 = x, y1 = y;
  gcdx(b % a, a, x1, y1);
  x = y1 - (b/a) * x1, y = x1;
}

ll modpow(int b, int e) {
  if (e == 0) return 1;
  if (e == 1) return b;
  if (e & 1) return (b * modpow(b, e-1)) % MOD;
  ll b2 = modpow(b, e/2);
  return (b2 * b2) % MOD;
}

int modinv(int b) {
  int x = 0, y = 0; gcdx(b, MOD, x, y);
  return (x % MOD + MOD) % MOD;
}

void dfs(int v) {
  if (!SZ(ch[v])) dp[v] = c;
  else {
    dp[v] = 0; ll pc = 1;
    for (auto it : ch[v]) dfs(it);
    REP(i, 0, rot[v]-1) pc = (pc * dp[ch[v][i]]) % MOD;
    //cout << v << ": " << pc << endl;
    REP(i, 0, SZ(ch[v])-1) {
      //cout << "rotation " << i << ": ";
      dp[v] = (dp[v] + modpow(pc, gcd(sym[v], i/rot[v]))) % MOD;
      //cout << modpow(pc, gcd(sym[v], i/rot[v])) << endl;
    }
    //cout << "total " << dp[v] << ", ";
    dp[v] = (dp[v] * modinv(SZ(ch[v]))) % MOD;
    //cout << "div by nch is " << dp[v] << ", ";
    dp[v] = (dp[v] * c) % MOD;
    //cout << "mul by c is " << dp[v] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  REP(i, 1, t) {
    n = 0; stack<ii>().swap(cur); tr.reset();
    memset(ch, 0, sizeof(ch)); memset(id, 0, sizeof(id));
    cin >> tree >> c;
    STREP(i, tree) {
      if (tree[i] == '[') {
        n++;
        if (!cur.empty()) ch[cur.top().F].PB(n), tr[n] = 1;
        cur.emplace(n, i);
      } else if (tree[i] == ']') {
        ii v = cur.top(); cur.pop();
        if (!cur.empty()) id[cur.top().F].PB(tree.substr(v.S, i-v.S+1));
      }
    }
    REP(i, 1, n) {
      vector<string> idr = id[i];
      int nch = SZ(id[i]);
      for (rot[i] = 1; rot[i] <= nch; rot[i]++) {
        rotate(idr.begin(), ++idr.begin(), idr.end());
        if (id[i] == idr) break;
      }
      sym[i] = nch/rot[i];
    }
    /*REP(i, 1, n) {
      cout << i << ", " << SZ(id[i]) << ", " << rot[i] << ": ";
      for (auto it : id[i]) cout << it << ' ';
      cout << endl;
    }*/
    res = 1;
    REP(i, 1, n) if (!tr[i]) dfs(i), res = (res * dp[i]) % MOD;
    cout << "Case #" << i << ": " << res << '\n';
  }
}