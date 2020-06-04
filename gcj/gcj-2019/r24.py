# import sys
# sys.stdout.flush()
# sys.exit()

def read(x): return int(x) - 1
MOD = 1000000007

for cas in range(1, int(input()) + 1):
  m = int(input())
  moves = []
  for i in range(m):
    moves.append(list(map(read, input().split())))
  g = list(map(int, input().split()))
  # loop 1000 times
  for _ in range(m*m + m):
    for i in range(1, m):
      if g[i] <= 0: continue
      g[moves[i][0]] += g[i]
      g[moves[i][1]] += g[i]
      g[i] = 0
  ans = g[0]
  # check unbounded
  if g[0] > 0:
    g[0] -= 1
    g[moves[0][0]] += 1
    g[moves[0][1]] += 1
    for _ in range(m*m + m):
      for i in range(1, m):
        if g[i] <= 0: continue
        g[i] -= 1
        g[moves[i][0]] += 1
        g[moves[i][1]] += 1
  if g[0] > ans:
    print("Case #" + str(cas) + ": UNBOUNDED")
  else:
    print("Case #" + str(cas) + ": " + str(ans % MOD))
