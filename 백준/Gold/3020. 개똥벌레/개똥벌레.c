#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int *imosUp, *imosDown;

int main()
{
  int N, H;
  scanf("%d %d", &N, &H);
  imosUp = (int*)calloc(H+1, sizeof(int));
  memset(imosUp, 0, sizeof(int) * (H+1));
  imosDown = (int*)calloc(H+1, sizeof(int));
  memset(imosDown, 0, sizeof(int) * (H+1));

  for (int i = 0; i < N; i++)
  {
    int num;
    scanf("%d", &num);
    if (i%2)
      imosUp[num]++;
    else
      imosDown[num]++;
  }

  for (int i = H-1; i > 0; i--)
  {
    imosUp[i] += imosUp[i+1];
    imosDown[i] += imosDown[i+1];    
  }

  int minNum = N, minCnt = 1;
  for (int i = 1; i <= H; i++)
  {
    int num = imosDown[i] + imosUp[H-i+1];
    if (minNum > num)
    {
      minNum = num;
      minCnt = 1;
    }
    else if(minNum == num)
      minCnt++;
  }
  
  printf("%d %d", minNum, minCnt);

  free(imosUp); free(imosDown);
  return 0;
}
