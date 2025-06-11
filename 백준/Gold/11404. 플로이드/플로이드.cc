#include <iostream>
#define INF 10000000
using namespace std;


int N, M;
int prices[101][101];

void f()
{
    for (int mid = 1; mid <= N; mid++)
    {
        for (int start = 1; start <= N; start++)
        {
            for (int end = 1; end <= N; end++)
            {
                prices[start][end] = min(prices[start][end], prices[start][mid] + prices[mid][end]);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
            prices[i][j] = INF;
        prices[i][i] = 0;
    }

    cin >> N >> M;
    
    int a,b,c;
    while (M--)
    {
        cin >> a >> b >> c;

        prices[a][b] = min(prices[a][b], c);
    }

    f();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (prices[i][j] == INF)
                cout << "0 ";
            else
                cout << prices[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
