#include <iostream>
using namespace std;

int N, M;
int arr[6][6];
int f(int y, int x, int status)
{
    if (y==N)
        return 0;

    int ans = 600;
    for (int i = 0; i < 3; i++)
    {
        if (status == i) // 이전 행동 금지
            continue;
        
        int nextY = y+1;
        int nextX = x + i-1; // i: 0~2 이므로 i-1: -1 ~ 1
        if (nextX>=0 && nextX<M)
            ans = min(ans, f(nextY, nextX, i) + arr[y][x]);
    }

    return ans;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    int ans = 600;
    for (int i = 0; i < M; i++)
    {
        ans = min(ans, f(0, i, -1));
    }
    cout << ans;
}
