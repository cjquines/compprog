n = input()
p = n*[-1]

def find(n):
  if p[n] < 0: return n
  p[n] = find(p[n])
  return p[n]

def union(u, v):
  u, v = find(u), find(v)
  if u == v: return False
  if p[u] < p[v]: u, v = v, u
  p[u] += p[v]
  p[v] = u
  return True

old = []
new = []

for i in xrange(n-1):
  a, b = map(int, raw_input().strip().split())
  if not union(a-1, b-1): old.append([a, b])

for i in xrange(n-1):
  if union(i, i+1): new.append([i+1, i+2])

print len(old)
for [a, b], [c, d] in zip(old, new):
  print a, b, c, d