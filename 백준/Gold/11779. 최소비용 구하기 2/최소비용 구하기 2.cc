#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int N, M;
int prices[1001];
bool visit[1001];
int S, E;

priority_queue<pair<int, int>> pq;
map<int, vector<pair<int, int>>> g;
vector<int> paths[1001];

int dijkstra()
{
    fill(prices, prices+1001, 100000000);
    pq.push(make_pair(0, S));
    prices[S] = 0;
    paths[S].push_back(S);

    while(!pq.empty())
    {
        int price = -pq.top().first;
        int node = pq.top().second;
        pq.pop();


        if (price > prices[node])
            continue;

        // cout << price << ", " << node << '\n';

        vector<pair<int, int>>::iterator next;
        for (next=g[node].begin(); next != g[node].end(); next++)
        {
            if (prices[next->second] > (prices[node] + next->first))
            {
                prices[next->second] = prices[node] + next->first;
                
                paths[next->second] = paths[node];
                paths[next->second].push_back(next->second);
                
                pq.push(make_pair(-prices[next->second], next->second));
                
            }
        }
    }

    return prices[E];
}

int main()
{
    cin >> N >> M;
    int a,b,c;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b)); // 단방향
    }
    cin >> S >> E;

    cout << dijkstra() << '\n';
    cout << paths[E].size() << '\n';

    for (int node : paths[E])
    {
        cout << node << ' ';
    }

    return 0;
}
