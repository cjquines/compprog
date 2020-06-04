#include <bits/stdc++.h>
using namespace std;
#define STREP(i, s) for (int(i) = 0; (s)[(i)]; (i)++)
#define REP(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)
#define ALL(c) begin(c), end(c)
#define SIZE(c) int((c).size())
#define INF 0x3f3f
#define EB emplace_back
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int s, v1, v2, t1, t2;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> s >> v1 >> v2 >> t1 >> t2;
  if (2*t1 + v1*s == 2*t2 + v2*s) {
    cout << "Friendship" << endl;
  } else {
    if (2*t1 + v1*s < 2*t2 + v2*s) {
      cout << "First" << endl;
    } else cout << "Second" << endl;
  }
}