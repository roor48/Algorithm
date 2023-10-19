#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int len;
  char word[51];
}Info;

Info* arr;
Info* temp;

int isAFirst(Info a, Info b)
{
  if (a.len != b.len) return 0;
  for (int i = 0; i < a.len; i++)
  {
    if (a.word[i] < b.word[i]) return 1; 
    else if (a.word[i] > b.word[i]) return 0;
  }

  return 1;
}

int isSame(Info a, Info b)
{
  if (a.len != b.len) return 0;

  for (int i = 0; i < a.len; i++)
    if (a.word[i] != b.word[i]) return 0;

  return 1;
}

void merge(const int left, const int mid, const int right)
{
  int i = left, j = mid+1, k = left;

  while(i<=mid && j<=right)
  {
    // temp[k++] = arr[i].len < arr[j].len ? arr[i++].len : arr[j++].len;
    if(arr[i].len < arr[j].len || isAFirst(arr[i], arr[j]))
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  if(i>mid)
  {
    for(int l=j; l<=right; l++)
      temp[k++] = arr[l];
  }
  else
  {
    for(int l=i; l<=mid; l++)
      temp[k++] = arr[l];
  }

  for(int l=left; l<=right; l++)
  {
    arr[l] = temp[l];                                                                                                                                                                                                            
  }
}

void merge_sort(const int left, const int right)
{
  if (left<right)
  {
    int mid = (left+right)/2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
  }
}

int main()
{
  int N;
  scanf("%d", &N);

  arr = (Info*)malloc(sizeof(Info) * N);
  temp = (Info*)malloc(sizeof(Info) * N);

  for (int i = 0; i < N; i++)
  {
    scanf("%s", arr[i].word);
    arr[i].len = strlen(arr[i].word);
  }

  merge_sort(0, N-1);

  printf("%s\n", arr[0].word);
  for (int i = 1; i < N; i++)
    if (!isSame(arr[i], arr[i-1]))
      printf("%s\n", arr[i].word);

  return 0;
}
