from itertools import permutations
from math import atan2

for cas in range(int(input())):
    n = int(input())
    pt = []
    for _ in range(n):
        x, y = map(int, input().split())
        pt.append((x, y))
    res = 0
    if n <= 3:
        res = n
        print("Case #" + str(cas+1) + ":", res)
        continue

    for p in permutations(range(n)):
        
        atan2(p[2][0] - p[1][0], p[2][1] - p[1][1])
        atan2(y, x)

    print("Case #" + str(cas+1) + ":", res)
