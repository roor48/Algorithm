#include <iostream>
using namespace std;

int dp[1001];

int f(int n)
{
    if (n<0 || n>1000) return 0;
    if (dp[n]) return dp[n];

    if (f(n-1)==1)
        return dp[n] = 2;
    if (f(n-3)==1)
        return dp[n] = 2;
    return dp[n] = 1;
}

int main()
{
    int n;
    cin >> n;

    dp[0] = 2;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;

    cout << (f(n)==1 ? "SK" : "CY");
    return 0;
}
