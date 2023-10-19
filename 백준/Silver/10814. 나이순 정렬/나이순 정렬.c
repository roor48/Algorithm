#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int age;
  char name[101];
}Info;
Info* list;
Info* temp;

void merge(int left, int mid, int right)
{
  int leftPos = left, midPos = mid+1, tempPos = left;

  while(leftPos <= mid && midPos <= right)
  {
    temp[tempPos++] = list[leftPos].age <= list[midPos].age ? list[leftPos++] : list[midPos++];
  }

  if(leftPos > mid)
    for (int i = midPos; i <= right; i++)
      temp[tempPos++] = list[i];
  else
    for (int i = leftPos; i <= mid; i++)
      temp[tempPos++] = list[i];
  
  for (int i = left; i <= right; i++)
    list[i] = temp[i];
}

void sort(int left, int right)
{
  if (left < right)
  {
    int mid = (left + right)/2;
    sort(left, mid);
    sort(mid+1, right);

    merge(left, mid, right);
  }
}

int main()
{
  int N;
  scanf("%d", &N);
  list = (Info*)malloc(sizeof(Info) * N);
  temp = (Info*)malloc(sizeof(Info) * N);

  for (int i = 0; i < N; i++)
  {
    scanf("%d %s", &list[i].age, list[i].name);
  }

  sort(0, N-1);

  for (int i = 0; i < N; i++)
    printf("%d %s\n", list[i].age, list[i].name);
}