#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int (i) = int(a); (i) <= int(b); (i)++)
#define F first
#define S second
typedef pair<int, string> is;

int t, n, m;
string s1, s2;
vector<is> dna;

template <class T>
int invmerge(T f, T m, T l);

template <class T>
int inv(T f, T l) {
  if (l - f > 1) {
    T m = f + (l - f) / 2;
    int res = inv(f, m);
    res += inv(m, l);
    res += invmerge(f, m, l);
    return res;
  } return 0;
}

template <class T>
int invmerge(T f, T m, T l) {
  int res = 0;
  while (f != l && m != l && m != f) {
    if (*f <= *m) f++;
    else res += m - f, rotate(f, m, m + 1), f++, m++;
  }
  return res;
}

int main() {
  cin >> t;
  while (t--) {
    vector<is>().swap(dna);
    cin >> n >> m;
    while (m--) cin >> s1, s2 = s1,
      dna.emplace_back(inv(s2.begin(), s2.end()), s1);
    stable_sort(dna.begin(), dna.end(),
      [](const is &l, const is &r) -> bool {
        return l.first < r.first;
      });
    for (auto it : dna) cout << it.second << endl;
    if (t) cout << endl;
  }
}