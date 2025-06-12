#include <iostream>
using namespace std;

int N, M, K;
long long dp[101][101] = {0};
bool paths[101][101][4] = {0};

int dirX[2] = {0, 1};
int dirY[2] = {1, 0};
void f()
{
    dp[0][0] = 1;
    
    for (int y = 0; y <= M; y++)
    {
        for (int x = 0; x <= N; x++)
        {
            for (int i = 0; i < 2; i++)
            {
                int beforeX = x-dirX[i];
                int beforeY = y-dirY[i];
                
                if (beforeX < 0 || beforeY < 0)
                    continue;
                
                if (paths[beforeX][beforeY][i])
                    continue;
                
                dp[x][y] += dp[beforeX][beforeY];
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K;

    int a, b, c, d;
    for (int i = 0; i < K; i++)
    {
        cin >> a >> b >> c >> d;

        int work = -1; // 0: 상, 1: 우, 2: 하, 3: 좌
        if (b-d == -1)
            work = 0;
        else if (a-c == -1)
            work = 1;
        else if (b-d == 1)
            work = 2;
        else if (a-c == 1)
            work = 3;

        paths[a][b][work] = true;
        paths[c][d][(work+2)%4] = true;
    }
    f();

    cout << dp[N][M];
    return 0;
}
