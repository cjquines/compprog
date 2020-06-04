s, n = 2, 3
mat = [1000*[0] for i in range(1000)]
mat[0][2] = mat[2][0] = 1
k = int(raw_input())

for p in [3, 7, 31, 127, 233]:
  if k % p == 0:
    for i in xrange(s+1, s+p+1):
      mat[s][i] = mat[i][s] = mat[i][s+p+1] = mat[s+p+1][i] = 1
    s += p + 1
    n += p + 1
    k /= p

k = [i[0] for i in enumerate(bin(k)[:1:-1]) if i[1] == '1']
m = max(k)

for ind in k:
  l = n
  r = n + 2*ind
  n = r + m + 1 - ind
  if l < r:
    mat[s][l] = mat[s][l+1] = mat[l][s] = mat[l+1][s] = 1
    for i, j in zip(xrange(l, r-2, 2), xrange(l+1, r-2, 2)):
      mat[i][i+2] = mat[i][j+2] = mat[j][i+2] = mat[j][j+2] = 1
      mat[i+2][i] = mat[j+2][i] = mat[i+2][j] = mat[j+2][j] = 1
    mat[r-2][r] = mat[r-1][r] = mat[r][r-2] = mat[r][r-1] = 1
  else: mat[s][r] = mat[r][s] = 1
  for i in xrange(r, n-1): mat[i][i+1] = mat[i+1][i] = 1
  mat[1][n-1] = mat[n-1][1] = 1

print n
for i in xrange(n):
  print "".join(map(lambda x: "Y" if mat[i][x] == 1 else "N", xrange(n)))