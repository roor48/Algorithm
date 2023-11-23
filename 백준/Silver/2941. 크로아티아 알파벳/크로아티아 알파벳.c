#include <stdio.h>
#include <string.h>

int main()
{
  char S[101];
  scanf("%s", S);
  int cnt = 0, len;
  len = strlen(S);
  for (int i = 0; i < len; i++)
  {
    if (i<(len-1) && S[i]=='c' && S[i+1]=='=')
    {
      i++;
      cnt++;
    }
    else if (i<(len-2) && S[i]=='d' && S[i+1]=='z' && S[i+2]=='=')
    {
      i+=2;
      cnt++;
    }
    else if (i<(len-1) && S[i]=='l' && S[i+1]=='j')
    {
      i++;
      cnt++;
    }
    else if (i<(len-1) && S[i]=='n' && S[i+1]=='j')
    {
      i++;
      cnt++;
    }
    else if (i<(len-1) && S[i]=='c' && S[i+1]=='-')
    {
      i++;
      cnt++;
    }
    else if (i<(len-1) && S[i]=='d' && S[i+1]=='-')
    {
      i++;
      cnt++;
    }
    else if (i<(len-1) && S[i]=='s' && S[i+1]=='=')
    {
      i++;
      cnt++;
    }
    else if (i<(len-1) && S[i]=='z' && S[i+1]=='=')
    {
      i++;
      cnt++;
    }
    else
      cnt++;
  }

  printf("%d", cnt);
}