def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

T = int(input())
for i in range(T):
    a, b = map(int, input().split())
    print(a * b // gcd(a, b))
