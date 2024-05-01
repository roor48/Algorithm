#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* rny_string) {
    char* answer = (char*)malloc(201);
    int answerIdx = 0;
    
    int rnyLen = strlen(rny_string);
    
    for (int i = 0; i < rnyLen; i++)
    {
        if (rny_string[i] == 'm')
        {
            answer[answerIdx++] = 'r';
            answer[answerIdx++] = 'n';
        }
        else
        {
            answer[answerIdx++] = rny_string[i];
        }
    }
    answer[answerIdx] = '\0';
    
    printf("%s", answer);
    
    return answer;
}