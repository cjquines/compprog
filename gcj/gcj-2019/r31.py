import sys
# sys.stdout.flush()
# sys.exit()
n = 10**12
k = 10**10

# shamelessly stolen from testing_tool
def apply(status, p):
    new_status = []
    found_valid = False
    for a, b in status:
        if a <= p <= b - k:
            found_valid = True
            if p - a >= k:
                new_status.append((a, p))
            if b - (p + k) >= k:
                new_status.append((p + k, b))
        else:
            new_status.append((a, b))
    if not found_valid:
        return False
    return new_status

def countvalid(status):
    return sum((b - a - k + 1) for a, b in status)

def ithpoint(status, i):
    for j, (a, b) in enumerate(status):
        if b - a - k + 1 > i:
            return a + i
        i -= b - a - k + 1
    print("no ith point i")
    sys.exit(1) # shouldnt happen

def mirror(p):
    return n - (p - 1) - (k - 1)

t, w = map(int, input().split())
for cas in range(t):
    status = [(1, n + 1)]
    # p = int(input())
    # status = apply(status, p)
    # q = n//2 - k//2
    # new_status = apply(status, q)
    # if new_status:
    #     print(q)
    #     status = new_status
    # else:
    #     q = ithpoint(status, 0)
    #     print(q)
    #     status = apply(status, q)
    # sys.stdout.flush()
    while True:
        p = int(input())
        if p == -1:
            print("p is -1")
            sys.exit(1)  # shouldnt happen
        if p == -2 or p == -3:
            break
        status = apply(status, p)
        q = mirror(p)
        new_status = apply(status, q)
        if new_status:
            print(q)
            status = new_status
        else:
            q = ithpoint(status, 0)
            print(q)
            status = apply(status, q)
        sys.stdout.flush()
