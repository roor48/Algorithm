#include <stdio.h>
#include <stdbool.h>

int arr[10][10] = {0};

bool v1[10][10] = {0};
bool v2[10][10] = {0};
bool v3[10][10] = {0};

int squar(int x, int y)
{
  return (x/3)*3+(y/3);
}

int f(int z)
{
  if (z==81)
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
        printf("%d ", arr[i][j]);
      puts("");
    }
    return true;
  }

  int y = z/9;
  int x = z%9;
  if (arr[y][x] != 0)
    return f(z+1);

  for (int i = 1; i <= 9; i++)
  {
    if (v1[y][i]==0 && v2[x][i]==0 && v3[squar(y, x)][i] == 0)
    {
      v1[y][i] = v2[x][i] = v3[squar(y, x)][i] = 1;
      arr[y][x] = i;
      if (f(z+1)) return true;

      v1[y][i] = v2[x][i] = v3[squar(y, x)][i] = 0;
      arr[y][x] = 0;
    }
  }

  return false;
}

int main()
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      scanf("%d", &arr[i][j]);
      if (arr[i][j] != 0)
      {
        v1[i][arr[i][j]] = true;
        v2[j][arr[i][j]] = true;
        v3[squar(i, j)][arr[i][j]] = true;
      }
    }
  }
  f(0);
}
