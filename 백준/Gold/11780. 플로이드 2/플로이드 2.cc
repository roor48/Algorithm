#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


int N, M;
int prices[101];

int g[101][101];
priority_queue<pair<int, int>> pq;

vector<string> ans;

void dijkstra(int S)
{
    fill(prices, prices+101, 2047483647);
    
    
    vector<int> paths[101];
    paths[S] = vector<int>{S};
    pq.push(make_pair(0, S));
    prices[S] = 0;
    
    
    while (!pq.empty())
    {
        int price = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (price > prices[node])
            continue;
        
        for (int i = 1; i <= N; i++)
        {
            if (!g[node][i])
                continue;
            
            if (prices[i] > (prices[node] + g[node][i]))
            {
                prices[i] = prices[node] + g[node][i];

                paths[i] = paths[node];
                paths[i].push_back(i);
                
                pq.push(make_pair(-prices[i], i));
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (prices[i] == 2047483647)
            cout << "0 ";
        else
            cout << prices[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= N; i++)
    {
        ans.push_back("");
        int size = paths[i].size();
        if (size == 1)
        {
            ans.back().push_back('0');
            continue;
        }

        ans.back() += to_string(size);

        for (int j = 0; j < size; j++)
        {
            ans.back().push_back(' ');
            ans.back() += to_string(paths[i][j]);
        }
    }
}

int main()
{
    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        if (!g[a][b] || g[a][b] > c)
        {
            g[a][b] = c;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        dijkstra(i);
    }
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}
