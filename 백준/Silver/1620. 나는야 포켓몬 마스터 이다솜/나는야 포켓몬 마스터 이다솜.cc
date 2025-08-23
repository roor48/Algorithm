#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    string name;
    map<string, int> encyc_name;
    map<int, string> encyc_id;
    
    for (int i = 1; i <= N; i++) {
        cin >> name;
        encyc_name[name] = i;
        encyc_id[i] = name;
    }

    while(M--) {
        cin >> name;
        
        if (encyc_name.find(name) != encyc_name.end()) {
            cout << encyc_name[name] << '\n';
        } else {
            cout << encyc_id[atoi(name.c_str())] << '\n';
        }
    }
    
    return 0;
}
