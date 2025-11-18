#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
    int y;
    int x;
    int cnt;
} Pos;

typedef struct {
    int front, rear, size;
    Pos *arr;
} Queue;

Queue init(int _size) {
    Queue temp;
    temp.front = -1;
    temp.rear = -1;
    temp.size = _size;
    temp.arr = (Pos*)malloc(sizeof(Pos) * _size);
    return temp;
}

void push(Queue *this, Pos t) {
    (this->rear) = (this->rear + 1) % this->size;
    this->arr[this->rear] = t;
}

Pos pop(Queue *this) {
    (this->front) = (this->front + 1) % this->size;
    return this->arr[this->front];
}

int empty(Queue *this) {
    return this->front == this->rear;
}

void destroy(Queue *this) {
    free(this->arr);
}

int N, M;
int arr[101][101];
int visited[101][101];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    visited[1][1] = 1;
    Queue q = init(10001);
    push(&q, (Pos){1, 1, 1});

    int answer = 0;
    while (!empty(&q)) {
        Pos cur = pop(&q);
        
        if (cur.y == N && cur.x == M) {
            answer = cur.cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 1 || ny > N || nx < 1 || nx > M || visited[ny][nx] || arr[ny][nx] == 0)
                continue;

            visited[ny][nx] = 1;
            push(&q, (Pos){ny, nx, cur.cnt + 1});
        }
    }

    printf("%d\n", answer);
    destroy(&q);
    
    return 0;
}
