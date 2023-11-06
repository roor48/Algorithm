#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int isGroup()
{
  char s[101];
  scanf("%s", s);
  bool check[26] = {0};
  int len = strlen(s);

  char last = s[0];
  for (int i = 1; i < len; i++)
  {
    if(check[s[i]-'a'])
    {
      return 0;
    }
    else if (last!=s[i])
    {
      check[last-'a'] = 1;
      last = s[i];
    }
  }

  return 1;
}

int main()
{
  int N;
  scanf("%d", &N);
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    if (isGroup())
      cnt++;
  }

  printf("%d", cnt);
}