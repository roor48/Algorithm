#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int x;
    int y;
}pos;
pos operator+(const pos& p1, const pos& p2)
{
    return {p1.x + p2.x, p1.y + p2.y};
}
pos operator-(const pos& p1, const pos& p2)
{
    return {p1.x - p2.x, p1.y - p2.y};
}
bool operator==(const pos& p1, const pos& p2)
{
    return (p1.x==p2.x) && (p1.y==p2.y);
}
const pos dir[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

int pos2int(pos d)
{
    for (int i = 0; i < 4; i++)
        if (d == dir[i])
            return i;

    return -1;
}
int rot90deg(int d)
{
    if (d<0 || d>3)
        return -1;

    d--;
    if (d<0)
        d = 3;
    return d;
}

vector<pos> make_dragon(int x, int y, int d, int g)
{
    vector<pos> v;
    v.push_back({x,y});
    v.push_back(v[0] + dir[d]);

    while (g--)
    {
        pos pivot = v.back();

        for (int i = v.size()-1; i > 0; i--)
        {
            d = pos2int(v[i-1] - v[i]);
            d = rot90deg(d);
            v.push_back(v.back() + dir[d]);
        }
    }

    return v;
}

bool arr[101][101];
int main()
{
    int N;
    cin >> N;
    
    // get dragon
    int x, y, d, g;
    while(N--)
    {
        cin >> x >> y >> d >> g;

        vector<pos> v = make_dragon(x,y,d,g);

        for (int i = v.size()-1; i >= 0; i--)
        {
            arr[v[i].y][v[i].x] = true;
        }
    }

    // get square
    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (arr[i][j] && arr[i][j+1] && arr[i+1][j+1] && arr[i+1][j])
                cnt++;
        }
    }

    cout << cnt;
    return 0;
}
