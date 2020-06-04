for cas in range(int(input())):
    n = input()
    a = int(n.replace('4', '3'))
    b = int(n) - a
    print("Case #" + str(cas+1) + ":", a, b)
