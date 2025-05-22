#include <iostream>
#include <deque>
using namespace std;

int N;
deque<pair<int, int>> d;
int ans[1000], a_idx;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int t;
        cin >> t;
        d.push_back({t, i});
    }

    for (int i = 0; i < N; i++)
    {
        int v = d.front().first;
        int idx = d.front().second;
        d.pop_front();
        ans[a_idx++] = idx;

        if (d.empty())
            break;
    
        
        if (v > 0)
        {
            v--;
            for (int j = 0; j < v; j++)
            {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        else
        {
            for (int j = v; j < 0; j++)
            {
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }

    for (int i = 0; i < a_idx; i++)
        cout << ans[i] << ' ';
    return 0;
}
