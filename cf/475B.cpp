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

int n, m;
string a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> a >> b;
  if ((a[0] == '<' && a[n-1] == '>' && b[0] == 'v' && b[m-1] == '^') ||
      (a[0] == '>' && a[n-1] == '<' && b[0] == '^' && b[m-1] == 'v'))
    cout << "YES\n";
  else cout << "NO";
}