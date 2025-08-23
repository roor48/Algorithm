#include <stdio.h>

int main()
{
  int N,M;
  scanf("%d %d", &N, &M);

  char grid[N][M];
  getchar();
  for(int i = 0 ; i < N; i++)
  {
    for (int j = 0; j < M; j++)
      grid[i][j] = getchar();
    getchar();
  }

  int answer = 64;

  for (int _ = 0; _ < 2; _++)
  {
    for (int n = 0; n <= N-8; n++)
    {
      for (int m = 0; m <= M-8; m++)
      {
        int cnt = 0;
        int nextCol = _;
        for (int i = n; i < n+8; i++)
        {
          for (int j = m; j < m+8; j++)
          {
            if (nextCol != (grid[i][j] == 'W'))
            {
              cnt++;
            }
            nextCol = !nextCol;
          }
          nextCol = !nextCol;
        }

        if (answer > cnt) answer = cnt;
      }
    }
  }

  printf("%d", answer);
  return 0;
}
