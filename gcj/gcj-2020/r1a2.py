def br(x, y): return (x+1, y+1)
def bl(x, y): return (x+1, y)
def ri(x, y): return (x, y+1)
def le(x, y): return (x, y-1)

def solve(n):
    s = bin(n)
    bits = [i for i in range(1, n.bit_length() + 1) if s[-i] == "1"]
    cur = (1, 1)
    res = [cur]
    for i in bits:
        while cur[0] != i:
            if cur[1] == 1:
                cur = bl(*cur)
                res.append(cur)
            else:
                cur = br(*cur)
                res.append(cur)
        if cur[1] == 1:
            while cur[1] != cur[0]:
                cur = ri(*cur)
                res.append(cur)
        else:
            while cur[1] != 1:
                cur = le(*cur)
                res.append(cur)
    return res

def walkint(n):
    return n + n.bit_length() - sum(1 for c in bin(n) if c == "1")

for cas in range(int(input())):
    n = int(input())
    sub = max(1, n - 11)
    res = solve(sub)
    score = walkint(sub)
    cur = res[-1]
    while score != n:
        if cur[1] == 1: cur = bl(*cur)
        else: cur = br(*cur)
        res.append(cur)
        score += 1
    print("Case #" + str(cas+1) + ":")
    print(*[' '.join(str(n) for n in tup) for tup in res], sep='\n')
