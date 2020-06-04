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

#define N 1000001
#define MOD 1000000007
ll x, c[N], r[N];
vi dv[N];

ll modpow(ll b, ll e) {
  if (e == 0) return 1;
  if (e == 1) return b;
  ll res = modpow(b, e/2);
  res = (res * res) % MOD;
  if (e & 1) res = (res * b) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  REP(i, 2, N-1) for (int j = i; j < N; j += i) dv[j].PB(i);
  cin >> x; while (cin >> x) for (auto i : dv[x]) c[i]++;
  x = 0;
  PER(i, N-1, 2) {
    r[i] = (modpow(2, c[i]-1)*c[i]) % MOD;
    for (int j = 2*i; j < N; j += i) r[i] = (r[i] - r[j]) % MOD;
    x = (x + (i*r[i]) % MOD) % MOD;
  }
  cout << (x + MOD) % MOD << '\n';
}