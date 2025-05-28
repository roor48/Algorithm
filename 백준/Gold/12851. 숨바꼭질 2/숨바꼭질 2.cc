#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, K;
int arr[199999];
queue<pair<int, int>> q;

int getCnt(int pos)
{
    if (pos == K)
        return 1;
    
    int ans = 0;
    for (int i = 0;  i < 3; i++)
    {
        int next = -1;
        if (i==0)
            next = pos*2;
        else if (i==1)
            next = pos+1;
        else if (i==2)
            next = pos-1;

        if (next > 199998 || next < 0)
            continue;
        
        if ((arr[next] - arr[pos]) == 1)
        {
            ans += getCnt(next);
        }
    }


    return ans;
}

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

        if (pos > 199998 || pos < 0 || arr[pos] != -1)
            continue;
        
        arr[pos] = cnt;
        
        q.push(make_pair(pos*2, cnt+1));
        q.push(make_pair(pos+1, cnt+1));
        q.push(make_pair(pos-1, cnt+1));
    }

    cout << arr[K] << ' ';


    cout << getCnt(N);
    
    return 0;
}
