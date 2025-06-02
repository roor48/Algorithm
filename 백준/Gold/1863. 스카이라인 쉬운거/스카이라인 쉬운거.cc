#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> s;
pair<int, int> arr[50001];
int main()
{
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+N);

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        while (!s.empty() && (s.top().second > arr[i].second))
        {
            cnt++;
            s.pop();
        }

        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }

        if (s.top().second < arr[i].second)
        {
            s.push(arr[i]);
            continue;
        }
    }

    while (!s.empty() && (s.top().second > 0))
    {
        cnt++;
        s.pop();
    }
    cout << cnt;

    return 0;
}
