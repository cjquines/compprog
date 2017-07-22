#include <bits/stdc++.h>
using namespace std;

int main() {
  stack<int> st;
  queue<int> qu;
  priority_queue<int> pr;
  int n, q, x, stf, quf, prf;
  while (cin >> n) {
    stf = quf = prf = 1;
    stack<int>().swap(st);
    queue<int>().swap(qu);
    priority_queue<int>().swap(pr);
    while (n--) {
      scanf("%d %d", &q, &x);
      if (q == 1) {
        if (stf) st.push(x);
        if (quf) qu.push(x);
        if (prf) pr.push(x);
      } else {
        if (stf) {
          if (st.empty()) stf = 0;
          else if (st.top() != x) stf = 0;
          else st.pop();
        }
        if (quf) {
          if (qu.empty()) quf = 0;
          else if (qu.front() != x) quf = 0;
          else qu.pop();
        }
        if (prf) {
          if (pr.empty()) prf = 0;
          else if (pr.top() != x) prf = 0;
          else pr.pop();
        }
      }
    }
    if (stf + quf + prf > 1) cout << "not sure\n";
    else if (stf) cout << "stack\n";
    else if (quf) cout << "queue\n";
    else if (prf) cout << "priority queue\n";
    else cout << "impossible\n";
  }
}