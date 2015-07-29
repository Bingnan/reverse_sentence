/*************************************************************************
    > File Name: reverse.c
    > Author: duanbingnan
    > Mail: duanbingnan@gmail.com 
    > Created Time: 2015-07-29 22:32
 ************************************************************************/

#include <stdio.h>
#include <string.h>

// reverse a word
char* Reverse(char* str, int len)
{
    if(str == NULL || len <= 0)
        return str;
    
    char *start = str;
    char *end = str + len - 1;
    char ch;

    while(start < end)
    {
        ch = *start;
        *start = *end;
        *end = ch;
        ++start;
        --end;
    }
    return str;
}

char* ReverseSentence(char* str)
{
    if(str == NULL)
        return str;
    //reverse every char in sentence
    Reverse(str, strlen(str));

    //reverse every word back.
    char *start = str;
    char *end = str;
    while(*end != '\0')
    {
       while(*end != '\0' && *end != ' ')
           ++end;
       Reverse(start, end-start);
       if(*end == '\0')
       {
           break;
       }
       ++end;
       start = end;
    }
    return str;
}

int main()
{
    char s[] = "I am a student";
    char ss[] = "I am a student";
    printf("len=%d\n", strlen(s));
    printf("reversed word is %s\n", Reverse(s,strlen(s)));
    printf("reversed sentence is %s\n", ReverseSentence(ss));
}
