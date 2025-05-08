#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[500000];
int ans[500000];
int main()
{
    cin >> N;
    for (int i = N-1; i >= 0; i--)
        cin >> arr[i]; // 좌측 -> 우측 증가하는
    
    stack<pair<int, int>> s;
    for (int i = 0; i < N; i++)
    {
        if (s.empty())
        {
            s.push({arr[i], N-i-1});
            continue;
        }

        while (s.top().first < arr[i])
        {
            ans[s.top().second] = N-i;
            s.pop();

            if (s.empty())
                break;
        }

        s.push({arr[i], N-i-1});
    }
    
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << ' ';
    }


    return 0;
}
