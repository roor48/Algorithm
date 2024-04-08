#include <stdio.h>
#include <string.h>

char rhkahrvudwja[9][3] = {"A+", "A0", "B+", "B0",
                           "C+", "C0", "D+", "D0", "F"};
float avgNumArr[9] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};

int main()
{
  char subject[51];
  float gkrwja;
  char emdrmq[3];

  float scoreSum = 0;
  float sum = 0;

  for (int i = 0; i < 20; i++)
  {
    scanf("%s %f %s\n", subject, &gkrwja, emdrmq);

    for (int j = 0; j < 9; j++)
    {
      if (!strcmp(emdrmq, j[rhkahrvudwja]))
      {
        scoreSum += gkrwja;
        sum += j[avgNumArr] * gkrwja;
        break;
      }
    }
  }
  printf("%f", sum / scoreSum);

  return 0;
}