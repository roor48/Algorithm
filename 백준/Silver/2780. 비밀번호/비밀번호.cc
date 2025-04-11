#include <iostream>
#include <vector>
using namespace std;


int dp[1001][10]; // dp[n][m] = 길이가 n일때 m이 마지막으로 오는 경우의 수

vector<vector<int>> graph(10);

int main()
{
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    graph[0].push_back(7);
    graph[1].insert(graph[1].end(), {2, 4});
    graph[2].insert(graph[2].end(), {1, 3, 5});
    graph[3].insert(graph[3].end(), {2, 6});
    graph[4].insert(graph[4].end(), {1, 5, 7});
    graph[5].insert(graph[5].end(), {2, 4, 6, 8});
    graph[6].insert(graph[6].end(), {3, 5, 9});
    graph[7].insert(graph[7].end(), {4, 8, 0});
    graph[8].insert(graph[8].end(), {5, 7, 9});
    graph[9].insert(graph[9].end(), {6, 8});

    vector<int>::iterator iter;
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (iter=graph[j].begin(); iter!=graph[j].end(); iter++)
            {
                // dp[i][j] = (dp[i][j] + dp[i-1][*iter]) % 1234567;
                dp[i+1][*iter] = (dp[i+1][*iter] + dp[i][j]) % 1234567;
            }
        }
    }
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 0; i < 10; i++)
            sum = (sum + dp[n][i]) % 1234567;
        
        cout << sum << '\n';
    }

    return 0;
}
