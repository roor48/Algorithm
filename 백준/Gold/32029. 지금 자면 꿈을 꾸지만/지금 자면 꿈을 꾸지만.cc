#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, A, B;
int T[100];

int visit[100][10001][101];

int f(int n, int time, int duration)
{
    if (n==N)
        return 0;
    if (time > 10000)
        return -1;

    if (visit[n][time][duration])
        return visit[n][time][duration];


    int ans = 0;
    
    // 하는 경우
    if (time+duration <= T[n])
        ans = f(n+1, time+duration, duration) + 1;
    
    // 안하는 경우
    ans = max(ans, f(n+1, time, duration));
    
    // 자는 경우
    if (duration == A)
    {
        for (int X = 1; X < A; X++)
            ans = max(ans, f(n, time+X*B, A-X));
    }

    return visit[n][time][duration] = ans;
}

int main()
{
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++)
        cin >> T[i];
    sort(T, T+N);



    int ans = f(0, 0, A);

    cout << ans;



    return 0;
}

//          70 75 95 105
// X:       15  0  0   0
// Time:    45 60 75  90
// need:    15 15 15  15
// have:    25 15 20  15
