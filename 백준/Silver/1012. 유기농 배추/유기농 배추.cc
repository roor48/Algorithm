#include <bits/stdc++.h>
using namespace std;

int M, N, K;
bool arr[50][50];

int dirY[4] = {-1, 0, 1, 0};
int dirX[4] = {0, 1, 0, -1};
int f() {
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!arr[i][j])
                continue;

            q.push(make_pair(i, j));
            arr[i][j] = false;


            while(!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nextY = y+dirY[i];
                    int nextX = x+dirX[i];

                    if (nextY<0 || nextY>=N || nextX<0 || nextX>=M || !arr[nextY][nextX])
                        continue;
                    
                    q.push(make_pair(nextY, nextX));
                    arr[nextY][nextX] = false;
                }
            }

            ans++;
        }
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    int a, b;
    while (T--) {
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            cin >> a >> b;
            arr[b][a] = true;
        }

        cout << f() << '\n';
    }
    
    return 0;
}