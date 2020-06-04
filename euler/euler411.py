# 1^5 + ... + 30^5 ~ 1.3e8
# The NlgN LIS algorithm is doable. We can define increasing as “x and y
# coordinates never decrease” and the LIS algorithm will still work. Sorry 
# for not using DP.

def pointless(a, b):
  return a[0] <= b[0] and a[1] <= b[1]

def lis(a):
  m, p = len(a)*[None], len(a)*[None]
  l, m[0] = 1, 0
  for i in xrange(1, len(a)):
    L, R = 0, l
    if pointless(a[m[R-1]], a[i]): j = R
    else:
      while R - L > 1:
        M = (L + R) / 2
        if pointless(a[m[M-1]], a[i]): L = M
        else: R = M
      j = L
    p[i] = m[j-1]
    if j == l or pointless(a[i], a[m[j]]):
      m[j] = i
      l = max(l, j+1)
  return l

res = 0

for n in xrange(1, 30):
  k = n ** 5
  x = list(set([(pow(2, i, k), pow(3, i, k)) for i in xrange(2*k + 1)]))
  x.sort()
  res += lis(x)
  print res