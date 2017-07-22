// sorry, but i wanted to practice union-find

#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)

int t, ans;
string n;
int p[111];

int find(int v) {
  return p[v] ? p[v] = find(p[v]) : v;
}

void unite(int v, int s) {
  v = find(v), s = find(s);
  if (v != s) {
    if (p[v] == p[s]) p[v]++;
    if (p[v] > p[s]) p[v] = s;
    else p[s] = v;
    ans--;
  }
}

int main() {
  scanf("%d\n\n", &t);
  while (t--) {
    memset(p, 0, sizeof p);
    getline(cin, n);
    ans = n[0] - 'A' + 1;
    while (getline(cin, n), n[0]) {
      unite(n[0], n[1]);
    }
    printf("%d\n", ans);
    if (t) printf("\n");
  }
}