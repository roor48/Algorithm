#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int y;
    int x;
}pos;
int operator|(const pos& p1, const pos& p2)
{
    return abs(p1.y - p2.y) + abs(p1.x - p2.x);
}


int N, M, H;
int town[10][10];
vector<pos> milk;
pos home;

int m_cnt = 0;
bool flag = false;
void f(int hp, pos p, int cnt)
{
    int homeDist = p|home;
    if (flag && homeDist == 0)
    {
        m_cnt = max(m_cnt, cnt);
        return;
    }
    flag = true;

    for (int i = milk.size()-1; i>=0; i--)
    {
        // 현재 위치에서 다음 우유 위치까지 필요한 체력
        int price = p | milk[i];

        if (price <= hp)
        {
            pos t = milk[i];
            milk.erase(milk.begin() + i);

            f(hp-price+H, t, cnt+1);

            milk.insert(milk.begin() + i, t);
        }
    }

    if (homeDist <= hp)
    {
        f(hp-homeDist, home, cnt);
    }
}

int main()
{
    cin >> N >> M >> H;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> town[i][j];
            if (town[i][j] == 1)
                home = {i, j};
            else if (town[i][j] == 2)
                milk.push_back({i, j});
        }
    }

    // cout << f(M, home);

    f(M, home, 0);
    cout << m_cnt;

    return 0;
}
