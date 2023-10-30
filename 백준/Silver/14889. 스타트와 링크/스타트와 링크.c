#include <stdio.h>
#include <stdbool.h>

int S[20][20]={0};
int sTeam[20]={0}, lTeam[20]={0};
bool check[20]={0};
int N, minNum = 2147483647;

int sum(int i, int j)
{
  return S[i][j] + S[j][i];
}
int min(int a, int b)
{
  return a < b ? a : b;
}
int abs(int a)
{
  return a < 0 ? -a : a;
}

void getNum()
{
  int sSum = 0, lSum = 0;
  for (int i = 0; i < N/2; i++)
  {
    for (int j = i+1; j < N/2; j++)
    {
      sSum += sum(sTeam[i], sTeam[j]);
      lSum += sum(lTeam[i], lTeam[j]);
    }
  }

  minNum = min(minNum, abs(sSum - lSum));
}

void f(int n, int z)
{
  if (n==N/2)
  {
    int sIdx = 0, lIdx = 0;
    for (int i = 0; i < N; i++)
    {
      if (check[i])
        sTeam[sIdx++] = i;
      else
        lTeam[lIdx++] = i;
    }

    getNum();

    return;
  }

  for (int i = z; i < N; i++)
  {
    check[i] = true;
    f(n+1, i+1);
    check[i] = false;
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &S[i][j]);

  f(0, 0);
  printf("%d", minNum);

  return 0;
}
