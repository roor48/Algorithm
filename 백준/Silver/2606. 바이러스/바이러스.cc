#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool graph[101][101];
bool visited[101];

int main()
{
    cin >> N >> M;

    int a,b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    int ans = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i < 101; i++)
        {
            if (graph[cur][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
