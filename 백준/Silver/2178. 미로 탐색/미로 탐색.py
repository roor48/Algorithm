from collections import deque

N, M = map(int, input().split())
arr = []
for i in range(N):
    arr.append(list(map(int, input())))

isVisited = [[False for _ in range(M)] for _ in range(N)]
isVisited[0][0] = True

# Y좌표, X좌표, 이동한 횟수
bfs = deque([(0,0,1)])

dirY = [-1, 0, 1, 0]
dirX = [0, 1, 0, -1]
min_count = 5050
while len(bfs) > 0:
    cur_pos = bfs.popleft()

    if cur_pos[0] == N-1 and cur_pos[1] == M-1:
        min_count = min(min_count, cur_pos[2])

    for i in range(4):
        y_pos = cur_pos[0] + dirY[i]
        x_pos = cur_pos[1] + dirX[i]

        if y_pos >= N or y_pos < 0 or x_pos >= M or x_pos < 0 or arr[y_pos][x_pos]==0 or isVisited[y_pos][x_pos]:
            continue

        bfs.append((y_pos, x_pos, cur_pos[2]+1))
        isVisited[y_pos][x_pos] = True

print(min_count)