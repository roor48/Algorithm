#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define INF 2147483647
using namespace std;

int N, M;
map<int, vector<int>> graph;
int answer[20001];

void f()
{
    fill(answer, answer+20001, INF);
    priority_queue<pair<int, int>> q; // { 현재 노드까지 오는 데 필요한 비용, 현재 노드}
    q.push(make_pair(0, 1));
    answer[1] = 0;
    
    vector<int>::iterator iter;
    while(!q.empty())
    {
        int cost = -q.top().first;
        int node = q.top().second;
        q.pop();

        if (answer[node] < cost) continue; // 계산한 최소비용보다 현재 비용이 더 크면

        int nextCost = cost+1;
        for (iter=graph[node].begin(); iter!=graph[node].end(); iter++)
        {
            if (answer[*iter] > nextCost)
            {
                answer[*iter] = nextCost;
                q.push(make_pair(-nextCost, *iter));
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    f();

    int maxCost = 0;
    int maxIndex = 0;
    int maxCostCnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (answer[i] == INF) continue;
        if (maxCost < answer[i])
        {
            maxCost = answer[i];
            maxIndex = i;
            maxCostCnt = 1;
        }
        else if (maxCost == answer[i])
        {
            maxCostCnt++;
        }
    }

    cout << maxIndex << ' ' << maxCost << ' ' << maxCostCnt;

    return 0;
}