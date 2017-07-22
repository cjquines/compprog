#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

// wait i don't understand how this is related to
// this week's topic of advanced data structures

#define N 50111
int t, k, s[N], res[N];
vector<int> idx;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    vector<int>().swap(idx);
    cin >> k;
    REP(i, 0, k-1) cin >> s[k-1-i];
    REP(i, 0, k-1) idx.insert(idx.begin() + s[i], i);
    REP(i, 0, k-1) res[k-1-idx[i]] = i + 1;
    cout << res[0];
    REP(i, 1, k-1) cout << ' ' << res[i];
    cout << '\n';
  }
}