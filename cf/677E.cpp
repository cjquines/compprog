#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define PER(i, a, b) for (int(i) = int(a); (i) >= int(b); (i)--)
#define N 1011
#define LOG23 1.58496250072
#define MOD 1000000007
typedef long long ll;

ll modpow (int a, short b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b & 1) return (modpow(a, b-1) * a) % MOD;
  ll v = modpow(a, b/2);
  return (v * v) % MOD;
}


struct p23 {
  short p2, p3, rad;

  p23 (short p2 = 0, short p3 = 0, short rad = 0):
    p2(p2), p3(p3), rad(rad) { }

  void add (int v, bool ch) {
    if (ch) rad++;
    if (v == 2) p2++;
    else if (v == 3) p3++;
    else if (v == 0) p2 = p3 = rad = 0;
  }

  int val () {
    if (rad == 0) return 0;
    return int((modpow(2, p2) * modpow(3, p3)) % MOD);
  }
};

bool operator< (const p23& lhs, const p23& rhs) {
  return float(lhs.p2 - rhs.p2) < LOG23*float(rhs.p3 - lhs.p3);
}

int n, brd[N][N], pi, pj, qi, qj;
p23 dp[N][N][8], ncr, crs, ans;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void build(int i, int j, int k) {
  pi = i + dy[k]; pj = j + dx[k];
  if (min(pi, pj) >= 0 && max(pi, pj) < n)
    dp[i][j][k] = dp[pi][pj][k];
  dp[i][j][k].add(brd[i][j], true);
  //printf("dp[%d][%d][%d]: %d %d %d\n", i, j, k, dp[i][j][k].p2, dp[i][j][k].p3, dp[i][j][k].rad);
}

void process(int i, int j) {
  ncr = crs = p23(0, 0, N);
  REP(k, 0, 3) {
    ncr.rad = min(ncr.rad, dp[i][j][2*k].rad);
    crs.rad = min(crs.rad, dp[i][j][2*k+1].rad);
  }
  ncr.add(brd[i][j], false);
  if (ncr.rad - 1 > 0) REP(k, 0, 3) {
    pi = i + dy[2*k]; pj = j + dx[2*k];
    qi = i + ncr.rad*dy[2*k]; qj = j + ncr.rad*dx[2*k];
    if (min(qi, qj) >= 0 && max(qi, qj) < n) {
      ncr.p2 += dp[pi][pj][2*k].p2 - dp[qi][qj][2*k].p2;
      ncr.p3 += dp[pi][pj][2*k].p3 - dp[qi][qj][2*k].p3;
    } else {
      ncr.p2 += dp[pi][pj][2*k].p2;
      ncr.p3 += dp[pi][pj][2*k].p3;
    }
  }
  //printf("ncr[%d][%d]: %d %d %d\n", i, j, ncr.p2, ncr.p3, ncr.rad);
  ans = max(ncr, ans);
  crs.add(brd[i][j], false);
  if (crs.rad - 1 > 0) REP(k, 0, 3) {
    pi = i + dy[2*k+1]; pj = j + dx[2*k+1];
    qi = i + crs.rad*dy[2*k+1]; qj = j + crs.rad*dx[2*k+1];
    if (min(qi, qj) >= 0 && max(qi, qj) < n) {
      crs.p2 += dp[pi][pj][2*k+1].p2 - dp[qi][qj][2*k+1].p2;
      crs.p3 += dp[pi][pj][2*k+1].p3 - dp[qi][qj][2*k+1].p3;
    } else {
      crs.p2 += dp[pi][pj][2*k+1].p2;
      crs.p3 += dp[pi][pj][2*k+1].p3;
    }
  }
  //printf("crs[%d][%d]: %d %d %d\n", i, j, crs.p2, crs.p3, crs.rad);
  ans = max(crs, ans);
}

int main() {
  scanf("%d", &n);
  REP(i, 0, n-1) REP(j, 0, n-1) scanf("%1d", &brd[i][j]);
  REP(i, 0, n-1) REP(j, 0, n-1) REP(k, 0, 3) build(i, j, k);
  PER(i, n-1, 0) PER(j, n-1, 0) REP(k, 4, 7) build(i, j, k);
  REP(i, 0, n-1) REP(j, 0, n-1) process(i, j);
  //printf("ans: %d %d\n", ans.p2, ans.p3);
  //printf("modpow: %I64d %I64d\n", modpow(2, ans.p2), modpow(3, ans.p3));
  printf("%d\n", ans.val());
}