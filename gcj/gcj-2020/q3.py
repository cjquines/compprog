for cas in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())) + [i] for i in range(n))
    res = []
    c, j = 0, 0
    for s, e, i in a:
        if s >= c: c = e; res.append((i, "C"))
        elif s >= j: j = e; res.append((i, "J"))
        else: res = 0; break
    print("Case #" + str(cas+1) + ":", ''.join(x[1] for x in sorted(res)) if res else "IMPOSSIBLE")
