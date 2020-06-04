#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define IDX(i, j) (i)*101 + (j)
#define N 11111

bitset<N> bd, bp, bc, bo;
char md;
int dp[] = {-101, -1, 1, 101}, dc[] = {-102, -100, 100, 102};
int t, n, m, mdi, mdj, res, mxm;
vector<tuple<char, int, int>> cur, ans;

#define MOVEP(i) REP(d, 0, 3) {\
  int ni = (i); while (ni >= 0 && ni/101 < n && ni%101 < n) {\
    ni += dp[d]; if (ni >= 0 && ni/101 < n && ni%101 < n) bc[ni] = 0;}}
#define MOVEC(i) REP(d, 0, 3) {\
  int ni = (i); while (ni >= 0 && ni/101 < n && ni%101 < n) {\
    ni += dc[d]; if (ni >= 0 && ni/101 < n && ni%101 < n) bp[ni] = 0;}}

void backtrack(int ni, int nj) {
  //cout << ni << ' ' << nj << endl;
  bool flag = true;
  bitset<N> rbp(bp), rbc(bc);
  int i = ni-1;
  REP(j, nj-1, n-1) {
    int id = IDX(i, j);
    if (bc[id] && bp[id] && !bo[id] && bd[id]) {
      flag = false;
      cur.emplace_back('o', i+1, j+1);
      //printf("o %d %d\n", i+1, j+1);
      bo[id] = 1, bd[id] = 0, res += 2;
      MOVEP(id);
      MOVEC(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 0, bd[id] = 1, res -= 2;
      bp = rbp, bc = rbc;
    }
    if (bc[id] && bp[id] && !bo[id] && !bd[id]) {
      flag = false;
      cur.emplace_back('o', i+1, j+1);
      //printf("o %d %d\n", i+1, j+1);
      bo[id] = 1, res++;
      MOVEP(id);
      MOVEC(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 1, res--;
      bp = rbp, bc = rbc;
    }
    if (bc[id] && bd[id]) {
      flag = false;
      cur.emplace_back('x', i+1, j+1);
      //printf("x %d %d\n", i+1, j+1);
      bd[id] = 0, res++;
      MOVEP(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 1, res--;
      bp = rbp;
    }
    if (bp[id] && bd[id]) {
      flag = false;
      cur.emplace_back('+', i+1, j+1);
      //printf("+ %d %d\n", i+1, j+1);
      bd[id] = 0, res++;
      MOVEC(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 1, res--;
      bc = rbc;
    }
  }
  REP(i, ni, n-1) REP(j, 0, n-1) {
    int id = IDX(i, j);
    if (bc[id] && bp[id] && !bo[id] && bd[id]) {
      flag = false;
      cur.emplace_back('o', i+1, j+1);
      //printf("o %d %d\n", i+1, j+1);
      bo[id] = 1, bd[id] = 0, res += 2;
      MOVEP(id);
      MOVEC(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 0, bd[id] = 1, res -= 2;
      bp = rbp, bc = rbc;
    }
    if (bc[id] && bp[id] && !bo[id] && !bd[id]) {
      flag = false;
      cur.emplace_back('o', i+1, j+1);
      //printf("o %d %d\n", i+1, j+1);
      bo[id] = 1, res++;
      MOVEP(id);
      MOVEC(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 1, res--;
      bp = rbp, bc = rbc;
    }
    if (bc[id] && bd[id]) {
      flag = false;
      cur.emplace_back('x', i+1, j+1);
      //printf("x %d %d\n", i+1, j+1);
      bd[id] = 0, res++;
      MOVEP(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 1, res--;
      bp = rbp;
    }
    if (bp[id] && bd[id]) {
      flag = false;
      cur.emplace_back('+', i+1, j+1);
      //printf("+ %d %d\n", i+1, j+1);
      bd[id] = 0, res++;
      MOVEC(id);
      backtrack(i+1, j+1);
      //printf("up: %d %d\n", ni, nj);
      cur.pop_back();
      bo[id] = 1, res--;
      bc = rbc;
    }
  }
  if (flag) {
    //printf("flagged: %d\n", res);
    if (res > mxm) {
      mxm = res;
      ans = cur;
      //printf("mxm: %d\n", mxm);
      //for (auto it : ans) cout << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  REP(k, 1, t) {
    bp.reset(), bp.flip(), bc.reset(), bc.flip(), bd.reset(), bd.flip();
    bo.reset();
    vector<tuple<char, int, int>>().swap(ans);
    vector<tuple<char, int, int>>().swap(cur);
    res = mxm = 0;
    cin >> n >> m;
    REP(i, 1, m) {
      cin >> md >> mdi >> mdj, res++;
      int id = IDX(--mdi, --mdj);
      bd[id] = 0;
      if (md == 'o') bo[id] = 1, res++;
      if (md == 'x' || md == 'o') MOVEP(id);
      if (md == '+' || md == 'o') MOVEC(id);
    }
    /*REP(i, 0, n-1) REP(j, 0, n-1) {
      int id = IDX(i, j);
      cout << id << ": " << bc[id] << ' ' << bp[id] << ' ' << bo[id] << ' ' << bd[id] << endl;
    }*/
    backtrack(1, 1);
    cout << "Case #" << k << ": " << mxm << ' ' << ans.size() << '\n';
    for (auto it : ans) cout << get<0>(it) << ' ' << get<1>(it) << ' ' << get<2>(it) << '\n';
  }
}