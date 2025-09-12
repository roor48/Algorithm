#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int main() {
    int K, a, b;
    cin >> K;

    v.push_back({10});
    v.push_back({1});
    v.push_back({6, 2, 4, 8});
    v.push_back({1, 3, 9, 7});
    v.push_back({6, 4});
    v.push_back({5});
    v.push_back({6});
    v.push_back({1, 7, 9, 3});
    v.push_back({6, 8, 4, 2});
    v.push_back({1, 9});

    while (K--) {
        cin >> a >> b;
        a %= 10;
        b %= v[a].size();
        cout << v[a][b] << '\n';
    }
    
    return 0;
}
