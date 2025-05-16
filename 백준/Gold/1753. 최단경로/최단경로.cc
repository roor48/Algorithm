#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define INF 2147483647
using namespace std;

typedef struct
{
    int node;
    int dist; // 시작노드에서 Node.node까지 오는 데 필요한 거리 값
}Node;
bool operator<(const Node &a, const Node &b) // pq 사용시 거리가 짧은게 우선순위
{
    return a.dist > b.dist;
}

int V, E, S;
map<int, vector<Node>> graph;
priority_queue<Node> pq;

int ans[20001];

int main()
{
    cin.tie(0); cout.tie(0);
    fill(ans, ans+20001, INF);

    cin >> V >> E >> S;

    int a, b, c;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    pq.push({S, 0});
    ans[S] = 0;
    while(!pq.empty())
    {
        Node n = pq.top();
        pq.pop();

        if (ans[n.node] < n.dist)
            continue;

        for (int i = 0; i < graph[n.node].size(); i++)
        {
            int nextNode = graph[n.node][i].node;
            int nextDist = n.dist + graph[n.node][i].dist;

            if (nextDist < ans[nextNode])
            {
                ans[nextNode] = nextDist;
                pq.push({nextNode, nextDist});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (ans[i] == INF)
            cout << "INF\n";
        else
            cout << ans[i] << '\n';
    }

    return 0;
}
