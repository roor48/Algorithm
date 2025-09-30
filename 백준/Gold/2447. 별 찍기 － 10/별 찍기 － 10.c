#include <stdio.h>

int N;
char s[2187][2187];

void f(int n, int c, int y, int x) {
    if (c) {
        for (int i = y; i < y+n; i++) {
            for (int j = x; j < x+n; j++) {
                s[i][j] = ' ';
            }
        }
        return;
    }
    if (n==1) {
        s[y][x] = '*';
        return;
    }

    int divNum = n/3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            f(divNum, i*j==1, divNum * i + y, divNum * j + x);
        }
    }
}

int main() {
    scanf("%d", &N);

    f(N, 0, 0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", s[i][j]);
        }
        puts("");
    }

    return 0;
}
