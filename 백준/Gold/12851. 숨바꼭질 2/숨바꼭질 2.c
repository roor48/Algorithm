#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
    int n;
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

int N, K;
int visited[100001];

int main() {
    memset(visited, -1, sizeof visited);
    scanf("%d %d", &N, &K);

    Queue q = init(1000000);
    push(&q, (Pos){N, 0});
    visited[N] = 0;

    int ans = -1;
    int ansCnt = 0;

    while (!empty(&q)) {
        Pos cur = pop(&q);

        if (ans != -1 && cur.cnt > ans)
            break;

        if (cur.n == K) {
            ans = cur.cnt;
            ansCnt++;
            continue;
        }

        int next[3] = {cur.n - 1, cur.n + 1, cur.n * 2};
        for (int i = 0; i < 3; i++) {
            int nn = next[i];
            
            if (nn < 0 || nn > 100000)
                continue;
            
            if (visited[nn] == -1 || visited[nn] == cur.cnt + 1) {
                visited[nn] = cur.cnt + 1;
                push(&q, (Pos){nn, cur.cnt + 1});
            }
        }
    }
    
    printf("%d\n%d", ans, ansCnt);

    destroy(&q);
    return 0;
}
