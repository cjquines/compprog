"""
(8, 0, 1)    (8, 0, 1)    (8, 0, 1)
(9, 1, 1)    (9, 1, 1)    (9, 1, 1)
(8, 2, 2)    (8, 2, 2) -> (8, 2, 2)
(6, 4, 2) -> (6, 4, 4) -> (7, 4, 5)
(2, 6, 2) -> (7, 8, 1) (7-6)*4*4
(7, 8, 1) (6-2)*6*2
"""

t = int(input())
for cas in range(t):
    n = int(input())
    p = map(int, input().split())
    st = []

    def compare():
        v2, i2, c2 = st[-1]
        v1, i1, c1 = st[-2]
        v0, i0, c0 = st[-3]
        return v0 > v1 < v2

    def apply():
        v2, i2, c2 = st.pop()
        v1, i1, c1 = st.pop()
        v0, i0, c0 = st.pop()
        if v0 < v2:
            res = (v0 - v1)*i1*c1
            st.append((v0, i0, c0 + c1))
            st.append((v2, i2, c2))
        elif v0 > v2:
            res = (v2 - v1)*i1*c1
            st.append((v0, i0, c0))
            st.append((v2, i1, c1 + c2))
        else:
            res = (v0 - v1)*i1*c1
            st.append((v0, i0, c0 + c1 + c2))
        return res

    ans = 0
    for i, v in enumerate(p):
        if len(st) >= 1 and st[-1][0] == v:
            v0, i0, c0 = st.pop()
            st.append((v0, i0, c0 + 1))
        else:
            st.append((v, i, 1))
            while len(st) >= 3 and compare():
                ans += (n - i)*apply()
                ans %= 10**9 + 7

    print("Case #" + str(cas + 1) + ": " + str(ans))
