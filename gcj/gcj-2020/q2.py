for cas in range(int(input())):
    s = list(map(int, input()))
    print("Case #" + str(cas+1) + ":", "("*s[0] + "".join(str(c) + ("()"[c > n])*abs(c - n) for c, n in zip(s, s[1:])) + str(s[-1]) + ")"*s[-1])
