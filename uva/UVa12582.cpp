#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int(i) = int(a); (i) <= int(b); i++)
#define ALL(c) begin(c), end(c)

int c, tmp, ans[26];
stack<int> st;
string line;

int main() {
  scanf("%d\n", &c);
  REP(i, 1, c) {
    memset(ans, -1, sizeof(ans));
    getline(cin, line);
    for (auto it : line) {
      tmp = it - 'A';
      ans[tmp]++;
      if (!st.empty()) {
        if (tmp == st.top()) {
          st.pop();
          if (!st.empty()) ans[st.top()]++;
          else ans[tmp]--;
        } else st.push(tmp);
      } else st.push(tmp);
    }
    printf("Case %d\n", i);
    REP(j, 0, 25) {
      if (ans[j] > 0) printf("%c = %d\n", j + 'A', ans[j]);
    }
  }
}