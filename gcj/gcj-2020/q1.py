for cas in range(int(input())):
    n = int(input())
    a = [list(map(int, input().split())) for _ in range(n)]
    tr = sum(a[i][i] for i in range(n))
    x = sum(len(set(r)) < n for r in a)
    y = sum(len(set(c)) < n for c in zip(*a))
    print("Case #" + str(cas+1) + ":", tr, x, y)
