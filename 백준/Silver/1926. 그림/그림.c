#include <stdio.h>

int max(int a, int b){return a>b?a:b;}

int arr[500][500] = {0};
int visited[500][500] = {0};


int N, M;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int f(int y, int x)
{
    if (y>=N || y<0 || x>=M || x<0 || visited[y][x] || arr[y][x]==0)
    {
        return 0;
    }
    visited[y][x] = 1;


    int area = 0;
    for (int i = 0; i < 4; i++)
    {
        area += f(y+dirY[i], x+dirX[i]);
    }

    return area + 1;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);   


    int count = 0;
    int area = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] || arr[i][j]==0)
                continue;

            count++;
            area = max(area, f(i, j));
        }
    }

    printf("%d\n%d", count, area);

    return 0;
}
