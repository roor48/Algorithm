#include <bits/stdc++.h>
using namespace std;

int N, M, tree[262145];
int bottom = 1;

void update(int node, int val) {
    node += bottom;
    tree[node] = val;

    int parent = node>>1;
    int leftNode = node & ~1;
    int rightNode = node | 1;

    if (tree[rightNode] == 0) {
        tree[parent] = leftNode - bottom;
    } else if (tree[leftNode] <= tree[rightNode]) {
        tree[parent] = leftNode - bottom;
    } else {
        tree[parent] = rightNode - bottom;
    }

    node = parent;
    while(node>1) {
        parent = node>>1;
        leftNode = node & ~1;
        rightNode = node | 1;

        int leftVal = tree[bottom + tree[leftNode]];
        int rightVal = tree[bottom + tree[rightNode]];

        // 왼쪽부터 채우기 때문에 leftNode가 0인 경우는 없음
        if (tree[rightNode]==0) {
            tree[parent] = tree[leftNode];
        } else if (leftVal <= rightVal) {
            tree[parent] = tree[leftNode];
        } else {
            tree[parent] = tree[rightNode];
        }

        node = parent;
    }
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
            cout << tree[1] << '\n';
        }
    }
    
    return 0;
}
