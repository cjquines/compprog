#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define N 21000000

char c, s[1024];
int t, n, m, x, q, q1, a, b, arr[N], tr[N], d[N];

void build(int p = 1, int i = 0, int j = n) {
  d[p] = 0;
  if (j-i == 1) tr[p] = arr[i];
  else {
    int m = (i + j) >> 1;
    build(p<<1, i, m);
    build(p<<1|1, m, j);
    tr[p] = tr[p<<1] + tr[p<<1|1];
  }
}

void push(int p, int i, int j) {
  if (d[p] == 1) {
    tr[p] = (j-i) - tr[p];
    if (j-i > 1) d[p<<1] ^= 1, d[p<<1|1] ^= 1;
    d[p] = 0;
  } else if (d[p] > 1) {
    tr[p] = (d[p] == 2) ? j-i : 0;
    if (j-i > 1) d[p<<1] = d[p<<1|1] = d[p];
    d[p] = 0;
  }
}

void modify(int I, int J, int v, int p = 1, int i = 0, int j = n) {
  if (I <= i and j <= J) {
    d[p] = (v > 1) ? v : d[p]^v;
    push(p, i, j);
  } else {
    push(p, i, j);
    if (!(J <= i or j <= I)) {
      int m = (i + j) >> 1;
      modify(I, J, v, p<<1, i, m);
      modify(I, J, v, p<<1|1, m, j);
      tr[p] = tr[p<<1] + tr[p<<1|1];
    }
  }
}

int query(int I, int J, int p = 1, int i = 0, int j = n) {
  push(p, i, j);
  if (I <= i and j <= J) return tr[p];
  if (J <= i or j <= I) return 0;
  int m = (i + j) >> 1;
  return query(I, J, (p<<1), i, m) + query(I, J, (p<<1|1), m, j);
}

int main() {
  scanf("%d", &t);
  REP(k, 1, t) {
    n = q1 = 0;
    scanf("%d", &m);
    while (m--) {
      scanf("%d %s", &x, s);
      while (x--) for (int i = 0; s[i]; i++, n++)
        arr[n] = (s[i] == '1');
    }
    build();
    scanf("%d", &q);
    printf("Case %d:\n", k);
    while (q--) {
      scanf("%s %d %d", &c, &a, &b);
      if (c == 'F') modify(a, b+1, 2);
      else if (c == 'E') modify(a, b+1, 3);
      else if (c == 'I') modify(a, b+1, 1);
      else printf("Q%d: %d\n", ++q1, query(a, b+1));
    }
  }
}