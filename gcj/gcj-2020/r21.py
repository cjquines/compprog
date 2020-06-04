import math
from random import randint

def isqrt(n):
    est = int(math.sqrt(2*n))
    est += 20
    while est*(est+1)//2 > n:
        est -= 1
    return est

def res(l, r):
    swap, i = False, 1
    if r > l: swap, l, r = not swap, r, l
    # initial drop
    n = isqrt(l - r)
    l -= n*(n+1)//2
    i = n+1
    if r > l: swap, l, r = not swap, r, l
    if l == r and swap: swap = False
    # second drop
    k = l//i
    while l < k*i + k*k - k or r < k*i + k*k: k -= 1
    l -= k*i + k*k - k
    r -= k*i + k*k
    i += 2*k
    # iterate
    while True:
        if r > l: swap, l, r = not swap, r, l
        if l == r and swap: swap = False
        if l < i: break
        l -= i
        i += 1
    if swap: l, r = r, l
    return i, l, r

def res2(l, r):
    swap, i = False, 1
    while True:
        if r > l: swap, l, r = not swap, r, l
        if l == r and swap: swap = False
        if l < i: break
        l -= i
        i += 1
    if swap: l, r = r, l
    return i, l, r

for cas in range(int(input())):
    l, r = map(int, input().split())
    i, l, r = res(l, r)
    print("Case #" + str(cas+1) + ":", i-1, l, r)
