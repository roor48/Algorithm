#include <iostream>
using namespace std;

int N, M;

string s[100];
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
        for (int j = 0; j < M; j++)
        {
            switch (s[i][j])
            {
                case '-':
                    s[i][j] = '|';
                    break;
                case '|':
                    s[i][j] = '-';
                    break;
                case '/':
                    s[i][j] = '\\';
                    break;
                case '\\':
                    s[i][j] = '/';
                    break;
                case '^':
                    s[i][j] = '<';
                    break;
                case '<':
                    s[i][j] = 'v';
                    break;
                case 'v':
                    s[i][j] = '>';
                    break;
                case '>':
                    s[i][j] = '^';
                    break;
            }
        }
    }

    for (int i = M-1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
            cout << s[j][i];
        cout << '\n';
    }

    return 0;
}
