#include <bits/stdc++.h>
using namespace std;

int N, M, tree[262145];
int bottom = 1;

void update(int node, int val) {
    node += bottom;
    tree[node] = val;

    while(node>1) {
        int parent = node>>1;

        int otherNode = node + ((node&1) ? -1 : 1);

        if (tree[otherNode]==0) {
            tree[parent] = tree[node];
        }
        else {
            tree[parent] = min(tree[node], tree[otherNode]);
        }

        node = parent;
    }
}

int find() {
    int node = 1;

    while (node <= bottom) {
        int left = node*2;
        int right = node*2+1;

        if (tree[node] == tree[left]) {
            node = left;
        } else {
            node = right;
        }
    }

    return node-bottom;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (bottom < N) {
        bottom <<= 1;
    }
    bottom--;
    int t;
    for (int i = 1; i <= N; i++) {
        cin >> t;
        update(i, t);
    }

    cin >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a;

        if (a==1) {
            cin >> b >> c;
            update(b, c);
        } else {
            cout << find() << '\n';
        }
    }
    
    return 0;
}
