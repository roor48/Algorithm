#include<bits/stdc++.h>
using namespace std;

typedef struct {
    int node;
    int cost;
} Node;

struct comp {
    bool operator()(Node &a, Node &b) {
        if (a.cost > b.cost)
            return true;
        return false;
    }
};

int N, D;
set<int> nodes;
map<int, int> dist;
map<int, map<int, int>> graph;
// 그래프로 변환해서 다익스트라로 풀기
int main() {
    cin >> N >> D;

    int s, e, l;
    graph[0][D] = D;
    dist[D] = INT32_MAX;
    for (int i = 0; i < N; i++) {
        cin >> s >> e >> l;
        
        if (s>=D || e>D || l>=(e-s))
            continue;
        
        if (graph[s][e]==0) {
            graph[s][e] = l;
        }
        else {
            graph[s][e] = min(graph[s][e], l);
        }
        
        dist[s] = INT32_MAX;
        dist[e] = INT32_MAX;
        
        nodes.insert(s);
        nodes.insert(e);
    }
    nodes.insert(0);
    nodes.insert(D);

    set<int>::iterator iter2;
    set<int>::iterator iter3;
    for (iter2=nodes.begin(); iter2!=nodes.end(); iter2++) {
        for (iter3=nodes.begin(); iter3!=nodes.end(); iter3++) {
            if (*iter3 < *iter2)
                continue;
            
            if (graph[*iter2].find(*iter3) == graph[*iter2].end())
                graph[*iter2][*iter3] = *iter3 - *iter2;
        }
    }
    
    priority_queue<Node, vector<Node>, comp> pq;
    map<int, int>::iterator iter;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();

        if (cost > dist[node])
            continue;
        
        for (iter=graph[node].begin(); iter!=graph[node].end(); iter++) {
            int nextNode = iter->first;
            int nextCost = iter->second;
            if ((node != nextNode) && (dist[nextNode] > (dist[node] + nextCost))) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }

    cout << dist[D];
    
    return 0;
}
