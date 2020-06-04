from heapq import *

def solve(c, d, x, g):
    res = [10**6]*d
    missing = []
    n_visited = 1
    for w in sorted(-i for i in x if i < 0):
        if w > n_visited:
            missing.extend([n_visited] * (w - n_visited))
            n_visited = w+1
        else:
            n_visited += 1
    missing.extend([n_visited] * (c - n_visited))

    it = iter(missing)
    vis_order = [-1]*(c+1)
    sorted_ = sorted(zip(x, range(2, c+1)))

    for w, u in sorted_:
        if w < 0:
            vis_order[u] = -w
        else:
            vis_order[u] = next(it)

    vis_time = [10**9]*(c+1)
    vis_time[1] = 0
    queue = [(0, 1, 0, 0)]
    last, last_u = 0, 0
    while queue:
        _, u, p, ee = heappop(queue)
        if u != 1 and vis_time[u] < 10**9: continue
        if u >= 2 and x[u-2] > 0:
            vis_time[u] = x[u-2]
        elif vis_order[u] == vis_order[last_u]:
            vis_time[u] = last
        else:
            vis_time[u] = last + 1
        # print(u, p, vis_time[u], vis_time[p])
        res[ee] = vis_time[u] - vis_time[p]
        if res[ee] == 0:
            res[ee] = 10**6
            vis_time[u] = -1
            continue
        for v, ee in g[u]:
            if vis_order[v] <= vis_order[u]: continue
            heappush(queue, (vis_order[v], v, u, ee))
        last, last_u = vis_time[u], u

    return res

def check(c, d, x, g, res):
    vis_time = [10**7]*(c+1)
    queue = [(0, 1)]
    vis_time[1] = 0
    while queue:
        t, u = heappop(queue)
        if vis_time[u] != t: continue
        for v, ee in g[u]:
            vis_time[v] = min(vis_time[v], vis_time[u] + res[ee])
            heappush(queue, (vis_time[u] + res[ee], v))
    print(vis_time, x)


for cas in range(int(input())):
    c, d = map(int, input().split())
    x = list(map(int, input().split()))
    g = [[] for _ in range(c+1)]
    for _ in range(d):
        u, v = map(int, input().split())
        g[u].append((v, _))
        g[v].append((u, _))
    res = solve(c, d, x, g)
    # check(c, d, x, g, res)
    print("Case #" + str(cas+1) + ":", *res)
