#include <iostream>
#include <queue>
using namespace std;

int N, K;
int arr[100001];
queue<int> q;
int ans=0;

int main()
{
    fill(arr, arr+100001, 1e9);
    cin >> N >> K;

    if (N==K)
    {
        cout << "0 1";
        return 0;
    }

    arr[N] = 0;
    q.push(N);

    while(!q.empty())
    {
        int pos = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int next = -1;
            if (i==0)
                next = pos-1;
            else if (i==1)
                next = pos+1;
            else if (i==2)
                next = pos*2;

            if (next > 100000 || next < 0)
                continue;
            if (arr[next] < arr[pos]+1)
                continue;

            arr[next] = arr[pos] + 1;
            if (next==K)
            {
                ans++;
                continue;
            }
            
            q.push(next);
        }
    }

    cout << arr[K] << ' ' << ans;
    
    return 0;
}
