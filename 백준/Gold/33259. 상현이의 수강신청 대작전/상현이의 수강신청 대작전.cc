#include <iostream>
#include <vector>
using namespace std;

// C의 합이 M을 넘지 않으면서 P의 합이 가장 크게 
int N, M;
int P[5001], C[5001];

int dp[5001][5001]; // i번 물건 볼때 j 학점을 얻는 모든 경우의 가치 중 최대치


int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i] >> C[i];
    }


    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (j < C[i])
                dp[i][j] = dp[i-1][j];
            else
                // dp[i][j] = max(i번 강의을 안들었을때, 들었을때) 총 학점이 j가 되는 상황
                dp[i][j] = max (dp[i-1][j], dp[i-1][j-C[i]] + P[i]);
        }
    }


    int maxVal = -1, lastNum = -1, lastCredit = -1;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (maxVal < dp[i][j])
            {
                maxVal = dp[i][j];
                lastNum = i;
                lastCredit = j;
            }
        }
    }

    if (lastNum==0 && lastCredit==0)
    {
        cout << "-1";
        return 0;
    }
    vector<int> ans;
    for (int num = lastNum; num > 0; num--)
    {
        if (dp[num][lastCredit] == dp[num-1][lastCredit]) // num번 강의를 안 들었으면
            continue;
        
        // num번 강의를 들었으면 num번 강의를 듣기 전 상황으로 가기
        lastCredit -= C[num];
        ans.push_back(num);
    }

    cout << ans.size();
    for (int i = ans.size()-1; i>=0; i--)
        cout << ' ' << ans[i];

    return 0;
}
