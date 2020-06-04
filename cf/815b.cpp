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

#define N 200011
#define MOD 1000000007
ll fac[N], mmi[N], n, res, a;

ll modpow(ll b, ll e) {
  if (e == 0) return 1;
  if (e == 1) return b;
  res = modpow(b, e/2);
  res = (res * res) % MOD;
  if (e & 1) res = (res * b) % MOD;
  return res;
}

ll choose(ll n, ll k) {
  return (((fac[n] * mmi[k]) % MOD) * mmi[n-k]) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  fac[0] = fac[1] = 1;
  REP(i, 2, N-1) fac[i] = (i * fac[i-1]) % MOD;
  mmi[0] = mmi[1] = 1;
  REP(i, 2, N-1) mmi[i] = modpow(fac[i], MOD-2);
  cin >> n;
  res = 0;
  if (n % 4 == 0) {
    n = (n-2)/2;
    REP(i, 0, n) {
      cin >> a;
      res = (res + (a * choose(n, i)) % MOD) % MOD;
      cin >> a;
      res = (res - (a * choose(n, i)) % MOD) % MOD;
    }
  } else if (n % 4 == 1) {
    n = (n-1)/2;
    REP(i, 0, n) {
      cin >> a;
      res = (res + (a * choose(n, i)) % MOD) % MOD;
      cin >> a;
    }
  } else if (n % 4 == 2) {
    n = (n-2)/2;
    REP(i, 0, n) {
      cin >> a;
      res = (res + (a * choose(n, i)) % MOD) % MOD;
      cin >> a;
      res = (res + (a * choose(n, i)) % MOD) % MOD;
    }
  } else {
    n = (n-3)/2;
    cin >> a;
    res = (res + (a * choose(n, 0)) % MOD) % MOD;
    REP(i, 0, n) {
      cin >> a;
      res = (res + (a * 2 * choose(n, i)) % MOD) % MOD;
      cin >> a;
      res = (res + (a * (choose(n, i+1) - choose(n, i))) % MOD) % MOD;
    }
  }
  cout << (res + MOD) % MOD << '\n';
}