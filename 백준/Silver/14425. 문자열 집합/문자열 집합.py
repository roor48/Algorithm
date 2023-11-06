N, M = map(int, input().split())

sets = {}
tests = []

for i in range(N):
  sets[input()] = 1
for i in range(M):
  tests.append(input())

cnt = 0
for i in tests:
  if (i in sets):
    cnt+=1

print(cnt)