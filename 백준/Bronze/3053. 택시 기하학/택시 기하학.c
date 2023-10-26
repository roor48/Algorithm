#include <stdio.h>
#define PI 3.1415926535897932384626433

double Euclidean(int r)
{
  return PI*r*r;
}

double Taxi(int r)
{
  return r*r*2;
}

int main()
{
  int r;
  scanf("%d", &r);
  printf("%f\n%f", Euclidean(r), Taxi(r));
}