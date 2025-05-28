#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, K;
queue<pair<int, int>> q;
int arr[199999];
int main()
{
    memset(arr, -1, sizeof arr);
    cin >> N >> K;

    q.push(make_pair(N, 0));
    
    while(!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (pos > 199998 || pos < 0)
            continue;
        
        if (arr[pos] != -1 && arr[pos] <= cnt)
            continue;

        arr[pos] = cnt;
        
        
        q.push(make_pair(pos*2, cnt));
        q.push(make_pair(pos+1, cnt+1));
        q.push(make_pair(pos-1, cnt+1));

    }

    cout << arr[K];

    return 0;
}