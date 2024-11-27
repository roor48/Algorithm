def f(n, c, y, x):
    if c:
        for i in range(y, y+n):
            for j in range(x, x+n):
                s[i][j] = ' '
        return
    if n==1:
        s[y][x] = '*'
        return

    divideNum = n//3
    for i in range(3):
        for j in range(3):
            f(divideNum, i*j==1, divideNum * i + y, divideNum * j + x)

N = int(input())
s = [[ '' for _ in range(N) ] for _ in range(N)]

f(N, 0, 0, 0)

for i in range(N):
    for j in range(N):
        print(s[i][j], end='')
    print()