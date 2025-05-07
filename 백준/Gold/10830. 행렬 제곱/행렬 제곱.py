S, N = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(S)]
unit_mat = [[0 for _ in range(S)] for _ in range(S)]
for i in range(S):
    unit_mat[i][i] = 1

def multi(a, b):
    v = [[None for _ in range(S)] for _ in range(S)]
    for i in range(S):
        for j in range(S):
            _sum = 0
            for idx in range(S):
                _sum = (_sum + a[i][idx] * b[idx][j]) % 1000
            v[i][j] = _sum
    return v            


def f(N):
    if N==1:
        return multi(mat, unit_mat)
    
    v = f(N//2)
    if N&1:
        return multi(multi(v, v), mat)
    return multi(v,v)

    

ans = f(N)

for i in ans:
    for j in i:
        print(j, end=' ')
    print()