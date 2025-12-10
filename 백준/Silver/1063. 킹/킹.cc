#include <bits/stdc++.h>
using namespace std;

int N;

bool isValid(pair<int,int> p) {
    return p.first >= 0 && p.first < 8 && p.second >= 0 && p.second < 8;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string K, S;
    cin >> K >> S >> N;

    pair<int, int> king, stone;
    king = make_pair(K[1]-'1', K[0]-'A');
    stone = make_pair(S[1]-'1', S[0]-'A');
    
    for (int i = 0; i < N; i++) {
        string query;
        cin >> query;
        
        pair<int, int> nextKing, nextStone;
        nextKing = king;
        nextStone = stone;

        if (query.find('R') != string::npos) {
            nextKing.second++;
            nextStone.second++;
        }
        if (query.find('L') != string::npos) {
            nextKing.second--;
            nextStone.second--;
        }
        if (query.find('B') != string::npos) {
            nextKing.first--;
            nextStone.first--;
        }
        if (query.find('T') != string::npos) {
            nextKing.first++;
            nextStone.first++;
        }

        if (!isValid(nextKing)) {
            continue;
        }
        
        if ((nextKing.first == stone.first) && (nextKing.second == stone.second)) {
            if (!isValid(nextStone)) {
                continue;
            }
            
            stone = nextStone;
        }
        king = nextKing;
    }

    cout << (char)(king.second + 'A') << (char)(king.first + '1') << '\n';
    cout << (char)(stone.second + 'A') << (char)(stone.first + '1');

    return 0;
}
