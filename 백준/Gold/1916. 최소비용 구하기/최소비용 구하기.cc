#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef struct
{
    int node;
    long long dist;
}Node;
bool operator<(const Node &a, const Node &b)
{
    return a.dist > b.dist;
}

int N, M;
map<int, vector<Node>> graph; // {dist, node}
priority_queue<Node> pq;
long long ans[1001];

int main()
{
    cin.tie(0); cout.tie(0);
    fill(ans, ans+1001, 10000000000);

    cin >> N >> M;
    int a, c;
    long long b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        Node t = {b, c};
        graph[a].push_back(t);
    }

    int s, e;
    cin >> s >> e;
    pq.push({s, 0});
    ans[s] = 0;

    while(!pq.empty())
    {
        int node = pq.top().node;
        long long dist = pq.top().dist;
        pq.pop();


        if (ans[node] < dist)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i].node;
            long long nextDist = dist + graph[node][i].dist;

            if (ans[nextNode] > nextDist)
            {
                ans[nextNode] = nextDist;
                Node t = {nextNode, nextDist};
                pq.push(t);
            }
        }
    }
    
    cout << ans[e];

    return 0;

}
