#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int x;
  int y;
}Vector2;

Vector2* vec;

void swap(int a, int b)
{
  Vector2 t = vec[a];
  vec[a] = vec[b];
  vec[b] = t;
}

void f(int fr, int ba)
{
  if (fr>=ba) return;

  int pos = fr;

  int pivot = (rand() % (ba-fr+1)) + fr;
  swap(pivot, ba);

  for (int i = fr; i < ba; i++)
  {
    if ((vec[ba].x > vec[i].x) || ((vec[ba].x == vec[i].x) && (vec[ba].y > vec[i].y)))
    {
      swap(pos++, i);
    }
  }
  swap(pos, ba);

  f(fr, pos-1);
  f(pos+1, ba);
}

int main()
{
  int N;
  scanf("%d", &N);

  vec = (Vector2*)malloc(sizeof(Vector2) * N);

  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &vec[i].x, &vec[i].y);
  }

  f(0, N-1);

  for (int i = 0; i < N; i++)
    printf("%d %d\n", vec[i].x, vec[i].y);
  free(vec);
  return 0;
}
