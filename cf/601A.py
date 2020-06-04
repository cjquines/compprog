from Queue import Queue as qu
import sys

n, m = map(int, raw_input().strip().split())
mat = [n*[0] for i in xrange(n)]
edges = [map(int, l.strip().split()) for l in sys.stdin]
for i, j in edges: mat[i-1][j-1] = mat[j-1][i-1] = 1

if mat[0][n-1] == 1:
  for i in xrange(n):
    for j in xrange(n):
      mat[i][j] ^= 1

q = qu()
q.put((0, 0))
t = n*[-1]

while not q.empty():
  v, d = q.get()
  for u, w in enumerate(mat[v]):
    if w == 1 and t[u] == -1:
      q.put((u, d+1))
      t[u] = d+1

print t[n-1]