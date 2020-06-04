from copy import deepcopy
from random import randint
from itertools import product
from collections import deque
from pprint import pprint
dns = [(-1, 0), (0, -1), (1, 0), (0, 1)]

def solve2(R, C, a):
    def inb(x, y): return 0 <= x < R and 0 <= y < C
    res = 0
    changed = True
    while changed:
        cur_sum = sum(sum(w for w in r) for r in a)
        # print(cur_sum)
        # pprint(a, width=35)
        res += cur_sum
        changed = False
        to_change = []
        for x, y in product(range(R), range(C)):
            if not a[x][y]: continue
            ns = []
            for dx, dy in dns:
                k = 1
                while inb(x + dx*k, y + dy*k) and not a[x + dx*k][y + dy*k]: k += 1
                nx, ny = x + dx*k, y + dy*k
                if inb(nx, ny): ns.append(a[nx][ny])
            if a[x][y]*len(ns) < sum(ns):
                to_change.append((x, y))
        for x, y in to_change:
            changed = True
            a[x][y] = 0
    return res

def solve(R, C, a):
    def ind(x, y): return x*C + y
    def rev(c): return (c//C, c%C)
    def inb(x, y): return 0 <= x < R and 0 <= y < C

    ns = [[(0,0,0)]*4 for _ in range(R*C)]

    for x, y in product(range(R), range(C)):
        indd = ind(x, y)
        for i, (dx, dy) in enumerate(dns):
            nx, ny = x + dx, y + dy
            if not inb(nx, ny): continue
            ns[indd][i] = (a[nx][ny], nx, ny)

    res = 0
    cur_sum = sum(sum(w for w in r) for r in a)
    cur_round = deque(range(R*C))
    next_round = []
    while cur_round:
        # print("this round", cur_sum)
        # pprint(a, width=35)
        res += cur_sum
        to_change = []
        while cur_round:
            chk = cur_round.popleft()
            cx, cy = rev(chk)
            if not a[cx][cy]: continue
            # print(cx, cy)
            fil = [i[0] for i in ns[chk] if i[0]]
            # print(ns[chk])
            if a[cx][cy]*len(fil) < sum(fil):
                # print("rm", cx, cy)
                cur_sum -= a[cx][cy]
                a[cx][cy] = 0
                to_change.append((cx, cy))
        for (cx, cy) in to_change:
            # print(cx, cy)
            for i, (ww, nx, ny) in enumerate(ns[ind(cx, cy)]):
                if not ww: continue 
                dx, dy = dns[i]
                wwww, ox, oy = ns[ind(cx, cy)][(i+2)%4]
                # ox, oy = cx - dx, cy - dy
                # print(nx, ny, cx, cy, ox, oy)
                if wwww:
                    ns[ind(nx, ny)][(i+2)%4] = (a[ox][oy], ox, oy)
                    # print(nx, ny, ns[ind(nx,ny)])
                else:
                    ns[ind(nx, ny)][(i+2)%4] = (0, 0, 0)
                    # print(nx, ny, ns[ind(nx,ny)])
                # print("add", nx, ny)
                next_round.append(ind(nx, ny))
        for (cx, cy) in to_change: a[cx][cy] = 0
        cur_round = deque(sorted(next_round))
        next_round = []

    return res

while True:
    R, C = randint(1, 10), randint(1, 10)
    # a = [[78, 93, 71, 50, 21, 74, 100], [80, 81, 39, 33, 32, 75, 60]]
    a = [[randint(1, 100) for _ in range(C)] for _ in range(R)]
    a2 = deepcopy(a)
    a3 = deepcopy(a)
    res, res2 = solve(R, C, a), solve2(R, C, a2)
    if res != res2: print(R, C, a3, res, res2); break
