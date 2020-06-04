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

#define N 25
int b, n, a[N], fa, fb;
int d[12] = {0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
int r[12] = {0, 31, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  REP(i, 1, n) {
    cin >> a[i];
    if (a[i] <= 29) {
      if (!fa) fa = i;
      else if (!fb) fb = i;
      else {
        cout << "No\n";
        return 0;
      }
    }
  }
  if (fb) {
    if (fb - fa != 12) {
      cout << "No\n";
      return 0;
    }
    if (a[fb] == 29 && a[fa] == 29) {
      cout << "No\n";
      return 0;
    }
  }
  if (n >= 12 && !fa) {
    cout << "No\n";
    return 0;
  }
  if (fa) {
    // check before
    int b = 1;
    while (fa-b > 0 && b <= 11) {
      if (a[fa-b] != r[b]) {
        cout << "No\n";
        return 0;
      }
      b++;
    }
    //cout << "CLEAR BEFORE" << endl;
    if (fa-b > 1) {
      cout << "No\n";
      return 0;
    }
    // check after
    b = 1;
    while (fa+b <= n && b <= 11) {
      if (a[fa+b] != d[b]) {
        cout << "No\n";
        return 0;
      }
      b++;
    }
    //cout << "CLEAR AFTER" << endl;
    if (!fb && fa+b < n) {
      cout << "No\n";
      return 0;
    }
    if (fb) {
      // check after fb
      b = 1;
      while (fb+b <= n && b <= 11) {
        if (a[fb+b] != d[b]) {
          cout << "No\n";
          return 0;
        }
        b++;
      }
    }
    cout << "Yes\n";
    return 0;
  } else {
    b = 0;
    while (n+b <= 12) {
      bool flag = true;
      //cout << b << endl;
      REP(i, 1, n) {
        if (a[i] != d[i+b]) {
          flag = false;
          //cout << "BREAK " << i << endl;
        }
      }
      if (flag) {
        cout << "Yes\n";
        return 0;
      }
      b++;
    }
    cout << "No\n";
    return 0;
  }
}