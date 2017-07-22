#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); (i)++)
#define PER(i, a, b) for(int(i) = int(a); (i) >= int(b); (i)--)
#define INF 0x3f3f3f3f
#define N 2200000
#define K 22
typedef vector<int> vi;

// i am particularly happy with this solution. this can be made online
// so that memory turns to O(K lg N), but i'm too lazy. the sequence
// stored in lv is A045412
// time: O(NK), memory: O(N + K lg N)

bitset<N> lv;
int n, k, w[N];
vi t(K), t1(K), t2(K);
stack<vi> dp;

int main() {
  ios_base::sync_with_stdio(0);
  for (int p = 0, i = 1; p < N; i++) p += lv[i] ? 1 : 3, lv[p] = 1;
  while (cin >> n >> k, ~n) {
    stack<vi>().swap(dp);
    PER(i, (1<<(n+1))-1, 1) cin >> w[i];
    REP(i, 1, (1<<(n+1))-1) {
      vi(K, -INF).swap(t), t[1] = w[i];
      if (lv[i]) {
        t1 = dp.top(); dp.pop(); t2 = dp.top(); dp.pop();
        REP(j, 2, k) REP(h, 1, j-1) t[j] = max(t[j], t1[h] + t2[j-h]);
      }
      dp.push(t);
    }
    cout << *max_element(dp.top().begin(), dp.top().end()) << endl;
  }
}