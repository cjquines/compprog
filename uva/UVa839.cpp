#include <bits/stdc++.h>
using namespace std;

struct obj { int wt, dt, wr, dr; } tmp, tmp2;
bool flag;
char inp[111];
int t;
stack<obj> st;

int main() {
  scanf("%d\n\n", &t);
  while (t--) {
    flag = true;
    while (gets(inp) && inp[0]) {
      sscanf(inp, "%d%d%d%d", &tmp.wt, &tmp.dt, &tmp.wr, &tmp.dr);
      st.push(tmp);
      while (!st.empty() && st.top().wt && st.top().wr) {
        tmp = st.top(); st.pop();
        if (tmp.wt*tmp.dt != tmp.wr*tmp.dr) flag = false;
        if (!st.empty()) {
          tmp2 = st.top(); st.pop();
          if (!tmp2.wt) tmp2.wt = tmp.wt+tmp.wr;
          else if (!tmp2.wr) tmp2.wr = tmp.wt+tmp.wr;
          st.push(tmp2);
        }
      }
    }
    flag ? printf("YES\n") : printf("NO\n");
    if (t) printf("\n");
  }
}