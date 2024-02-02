#include <stdio.h>
#include <string.h>

int alphabet[26][200001] = {0};
int main()
{
  char S[200001];
  int q;
  scanf("%s\n%d\n", S, &q);
  int len = strlen(S);

  for (int i = 1; i <= len; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      if (S[i-1]-'a' == j) alphabet[j][i] = alphabet[j][i-1]+1;
      else alphabet[j][i] = alphabet[j][i-1];
    }
  }

  for (int i = 0; i < q; i++)
  {
    char a;
    int l, r;
    scanf("%c %d %d\n", &a, &l, &r);

    printf("%d\n", alphabet[a-'a'][r+1] - alphabet[a-'a'][l]);
  }

  return 0;
}
