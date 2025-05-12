#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int x;
    pair<int, int> cur_pos;
    pair<int, int> desired;
}d;

int N, K;
int dist(int a)
{
    if (a < 0)
        a += N;
    else if (a > N)
        a -= N;

    return a;
}


d X[10000];
int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> X[i].x >> X[i].desired.first >> X[i].desired.second; // 목표 위치 지정

        X[i].cur_pos = {(X[i].x - 1) / N + 1, (X[i].x - 1) % N + 1}; // 초기 위치 지정
    }


    for (int i = 0; i < K; i++)
    {
        int distY = dist(X[i].desired.first - X[i].cur_pos.first);
        int distX = dist(X[i].desired.second - X[i].cur_pos.second);

        for (int j = i; j < K; j++)
        {
            if (X[i].cur_pos.first == X[j].cur_pos.first) // 같은 열에 있으면 행 회전
                X[j].cur_pos.second = dist(X[j].cur_pos.second + distX);
        }
            
        for (int j = i; j < K; j++)
        {
            if (X[i].cur_pos.second == X[j].cur_pos.second) // 같은 행에 있으면 열 회전
                X[j].cur_pos.first = dist(X[j].cur_pos.first + distY);
        }
            
        cout << distY + distX << '\n';
    }

    return 0;
}

// X의 위치가 C열이 될 때 까지, X가 있는 행을 회전시킨다.
// X의 위치가 R행이 될 때 까지, X가 있는 열을 회전시킨다.

