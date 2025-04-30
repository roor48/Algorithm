#include <iostream>
using namespace std;

int main()
{
    int X;
    cin >> X;


    int L = 1;
    int y=1, x=1;
    int dirY=0, dirX=1;
    for (int i = 2; i <= X; i++)
    {
        x += dirX;
        y += dirY;

        if (x<=0)
            x = 1;
        if (y<=0)
            y = 1;

        if (x > L) // 우측 -> 좌측
        {
            dirX = -1;
            dirY = 1;

            L++;
        }

        if (y > L) // 좌측 -> 우측
        {
            dirX = 1;
            dirY = -1;

            L++;
        }
    }

    cout << y << '/' << x;
    return 0;
}
