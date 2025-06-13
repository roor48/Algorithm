#include <iostream>
using namespace std;
int max(int a, int b){return a>b?a:b;}
int min(int a, int b){return a<b?a:b;}

int N;
int dp[6];
int arr[100001][3];

int f(int (*comp)(int, int))
{
    dp[0] = dp[1] = dp[2] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j==0)
                dp[j+3] = comp(dp[j], dp[j+1]);
            else if (j==1)
                dp[j+3] = comp(dp[j-1], comp(dp[j], dp[j+1]));
            else if (j==2)
                dp[j+3] = comp(dp[j-1], dp[j]);
            
            
            dp[j+3] += arr[i][j];
        }

        for (int j = 0; j < 3; j++)
            dp[j] = dp[j+3];
    }
    
    return comp(dp[0], comp(dp[1], dp[2]));
}


int main()
{
    cin.tie(0);

    cin >> N;
    int a, b, c;
    for (int i = 1; i <= N; i++)
    {
        cin >> a >> b >> c;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = c;
    }

    cout << f(max) << ' ' << f(min);
    

    return 0;
}
