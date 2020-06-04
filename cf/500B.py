n = input()
p = map(int, raw_input().strip().split())
g = []
for i in xrange(n):
  g.append(map(int, raw_input()))

t = n*[False]
grp = []
q = []

def dfs(v):
  t[v] = True
  grp.append(v)
  q.append(p[v])
  for u, w in enumerate(g[v]):
    if w == 1 and not t[u]:
      dfs(u)

for i, v in enumerate(g):
  if not t[i]:
    grp = []
    q = []
    dfs(i)
    grp.sort()
    q.sort()
    for j, w in zip(grp, q):
      p[j] = w

print " ".join(map(str, p))