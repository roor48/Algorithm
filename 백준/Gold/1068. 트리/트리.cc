#include <bits/stdc++.h>
using namespace std;

int N, K;
map<int, vector<int>> tree;
int f(int n) {
    if (tree.find(n) == tree.end())
        return 0;
    if (tree[n].size()==0)
        return 1;
    if (tree[n].size()==1 && tree[n][0]==K)
        return 1;

    int cnt = 0;
    for (int i = 0; i < tree[n].size(); i++) {
        if (tree[n][i] != K)
            cnt += f(tree[n][i]);
    }

    return cnt;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        tree[i] = vector<int>();
    int t, root;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t==-1) {
            root = i;
            continue;
        }
        
        tree[t].push_back(i);
    }
    cin >> K;
    tree.erase(K);

    cout << f(root);

    return 0;
}
