#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

int main() {
  queue<pair<int,int>> cars[2];
  vector<int> ans(11111);
  bool cur, flg;
  char side[11];
  int c, n, t, m, tmp, tim, load;
  scanf("%d", &c);
  while (c--) {
    queue<pair<int,int>>().swap(cars[0]);
    queue<pair<int,int>>().swap(cars[1]);
    cur = false;
    tim = 0;

    scanf("%d %d %d", &n, &t, &m);
    REP(i, 0, m-1) {
      scanf("%d %s", &tmp, side);
      if (side[0] == 'l') cars[0].emplace(tmp, i);
      else cars[1].emplace(tmp, i);
    }

    while (!cars[0].empty() || !cars[1].empty()) {
      load = 0, flg = false;
      if (!cars[cur].empty() && cars[cur].front().first <= tim) {
        tim += t, cur = !cur, flg = true;
      } else if (!cars[!cur].empty() && cars[!cur].front().first <= tim) {
        tim += 2*t, flg = true;
      }
      if (flg) {
        while (load < n && !cars[!cur].empty() &&
          cars[!cur].front().first <= tim - t) {
          ans[cars[!cur].front().second] = tim;
          cars[!cur].pop();
          load++;
        }
      } else {
        if (cars[0].empty()) tim = cars[1].front().first;
        else if (cars[1].empty()) tim = cars[0].front().first;
        else tim = min(cars[0].front().first, cars[1].front().first);
      }
    }
    REP(i, 0, m-1) printf("%d\n", ans[i]);
    if (c) printf("\n");
  }
}