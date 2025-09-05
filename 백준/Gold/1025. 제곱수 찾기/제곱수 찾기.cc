#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int n) {
    if (n <= 1)
    return true;
    
    for (int i = 2; i*i <= n; i++)
    {
        if (i*i == n)
        return true;
    }
    
    return false;
}

int N, M, arr[9][9];
int dirY, dirX;
int ans = -1;
void f(int y, int x, int hap) {
    if (isPerfect(hap)) {
        ans = max(ans, hap);
    }

    if (dirY==0 && dirX==0) {
        return;
    }
    
    int nextY = y+dirY;
    int nextX = x+dirX;
    if (nextY>=N || nextY<0 || nextX>=M || nextX<0) {
        return;
    }

    f(nextY, nextX, hap*10 + arr[nextY][nextX]);
}

int main() {

    cin >> N >> M;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j]-'0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (dirY=-N+1; dirY<N; dirY++) {
                for (dirX=-M+1; dirX<M; dirX++) {
                    f(i, j, arr[i][j]);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
