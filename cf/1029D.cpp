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

ll mod(ll a, ll m) { return ((a%m)+m)%m; }

ll modpow(ll b, ll e, ll m) {
  ll res = 1;
  while (e) {
    if (e & 1) res = mod(res*b, m);
    b = mod(b*b, m);
    e >>= 1;
  }
  return res;
}

ll eea(ll a, ll b, ll& x, ll& y) {
  ll xx = y = 0; ll yy = x = 1;
  while (b) {
    ll q = a / b;
    ll t = b; b = a%b; a = t;
    t = xx; xx = x - q*xx; x = t;
    t = yy; yy = y - q*yy; y = t;
  }
  return a;
}

ll ndigs(ll a) {
  ll res = 1;
  while (a /= 10) res++;
  return res;
}

// (a_i?) * 10^(len(a_j)) + a_j = 0 (mod k)

#define N 200011
ll n, k, arr[N], res;
map<int, int> cnt;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  REP(i, 1, n) cin >> arr[i];
  REP(i, 1, n) cnt[mod(arr[i], k)] += 1;
  res = 0;
  REP(i, 1, n) {
    ll a = modpow(10, ndigs(arr[i]), k);
    ll b = mod(-arr[i], k);
    ll x, y;
    ll g = eea(a, k, x, y);
    if (!(b%g)) {
      x = mod(x*(b/g), k);
      REP(j, 0, g-1) {
        auto it = cnt.find(mod(x+j*(k/g), k));
        if (it != cnt.end()) res += it->S;
        if (mod(arr[i], k) == mod(x+j*(k/g), k)) res--;
      }
    }
  }
  cout << res << endl;
}