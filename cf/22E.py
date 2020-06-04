n = input()
g = [int(x) - 1 for x in raw_input().strip().split()]
t = n*[True]

ind = n*[0]
for i in g: ind[i] += 1

starts = []
ends = []

def dfs(i):
  starts.append(i)
  t[i] = False
  while t[g[i]]:
    i = g[i]
    t[i] = False
  ends.append(i)

for i, v in enumerate(ind):
  if not v: dfs(i)

if len(starts) > 0:
  for i in xrange(n):
    if t[i]: dfs(i)

  ends = ends[1:] + ends[:1]
  print len(starts)
  print "\n".join(["{} {}".format(i+1, j+1) for i, j in zip(ends, starts)])
else:
  for i in xrange(n):
    if t[i]: dfs(i)

  if len(starts) > 1:
    ends = ends[1:] + ends[:1]
    print len(starts)
    print "\n".join(["{} {}".format(i+1, j+1) for i, j in zip(ends, starts)])
  else:
    print 0