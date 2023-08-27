#include <stdio.h>

int sort(char *a, char *b)
{
    int len1 = 0;
    for (; a[len1] != '\0'; len1++)
        ;
    int len2 = 0;
    for (; b[len2] != '\0'; len2++)
        ;
    if (len1 != len2 && len1 > len2)
    {
        int t = len1;
        len1 = len2;
        len2 = t;
        char *temp = a;
        a = b;
        b = temp;
    }
    else if (len1 == len2)
    {
        for (int i = 0; i < len1; i++)
        {
            if (a[i] > b[i])
            {
                int t = len1;
                len1 = len2;
                len2 = t;
                char *temp = a;
                a = b;
                b = temp;
                break;
            }
        }
    }
    return len1;
}