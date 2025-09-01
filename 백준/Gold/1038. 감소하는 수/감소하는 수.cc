#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;

    queue<string> q;

    int cnt = 0;
    for (int i = 0; i < 10; i++)
        q.push(to_string(i));

    while(!q.empty())
    {
        string str = q.front();
        q.pop();
        
        if (cnt == N) {
            cout << str;
            return 0;
        }
        cnt++;

        int lastNum = str[str.size()-1] - '0';

        for (int i = 0; i < lastNum; i++) {
            q.push(str + to_string(i));
        }
    }

    cout << "-1";

    return 0;
}
