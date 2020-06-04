for cas in range(int(input())):
    n = int(input())
    pre, inf, suf = [], [], []
    for i in range(n):
        prex, *infx, sufx = input().strip().split("*")
        pre.append(prex)
        inf.extend(infx)
        suf.append(sufx)
    pr, su = max(pre, key=len), max(suf, key=len)
    okay = all(pr.startswith(p) for p in pre) and all(su.endswith(s) for s in suf)
    if okay:
        res = pr + ''.join(inf) + su
    else:
        res = '*'
    print("Case #" + str(cas+1) + ":", res)
