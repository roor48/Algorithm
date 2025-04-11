#include <iostream>
#include <cstring>
using namespace std;
int max(int a,int b){return a>b?a:b;}

int N;
int yj_arr[500], hg_arr[500];
int lis[500];


int next(int n)
{
    if (n>=N)
        n-=N;
    return n;
}

int f(const int *arr, const int pos)
{
    int maxNum = 0;
    memset(lis, 0, sizeof lis);
    for (int i = 0; i < N; i++)
    {
        lis[next(pos+i)] = max(lis[next(pos+i)], 1);
        for (int j = 0; j < i; j++)
        {
            if (arr[next(pos+i)] > arr[next(pos+j)])
            {
                lis[next(pos+i)] = max(lis[next(pos+i)], lis[next(pos+j)]+1);
                maxNum = max(maxNum, lis[next(pos+i)]);
            }
        }
    }

    return maxNum;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> yj_arr[i];
    for (int i = 0; i < N; i++)
        cin >> hg_arr[i];

    int yj = 0;
    for (int pos = 0; pos < N; pos++)
    {
        yj = max(yj, f(yj_arr, pos));
    }
    int hg = 0;
    for (int pos = 0; pos < N; pos++)
    {
        hg = max(hg, f(hg_arr, pos));
    }

    // cout << "yj: " << yj << ", hg: " << hg << "\n\n";
    cout << (yj==hg ? "Both Win!" : yj>hg ? "YJ Win!" : "HG Win!");
        
    return 0;
}