import math

mod = 999999999999999073
N = 200

fact = [0] * (N + 1)
inv = [0] * (N + 1)

def binpow(a, n):
    res = 1
    while n:
        if n & 1:
            res = (res * a) % mod
            n -= 1
        else:
            a = (a * a) % mod
            n >>= 1
    return res

def precalc():
    fact[0] = 1
    inv[0] = 1
    for i in range(1, N + 1):
        fact[i] = (fact[i - 1] * i) % mod
        inv[i] = binpow(fact[i], mod - 2) % mod

def solve():
    precalc()

    n, k = map(int, input().split())

    a = [0] * (k + 1)

    for i in range(k + 1):
        x = fact[n] * inv[i] % mod * inv[n - i] % mod
        d = x // 2
        if x % 2:
            d += 1
        a[i] = d

    res = 0
    for i in range(k + 1):
        if i + i == k:
            res += 2 * a[i]
        else:
            res += a[i]

    print(res)



solve()
