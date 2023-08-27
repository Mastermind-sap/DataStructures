#include <stdio.h>
#include <string.h>
#include "add.h"

void multiply(char *a, char *b, char *result)
{
    int len1 = 0;
    for (; a[len1] != '\0'; len1++)
        ;
    int shift = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        char res[2048] = "";
        for (int j = 0; j < (a[i] - '0'); j++)
        {
            char temp[2048] = "";
            add(res, b, temp);
            strcpy(res, temp);
        }
        int k = 0;
        for (; res[k] != '\0'; k++)
            ;
        for (int j = 0; j < shift; j++, k++)
        {
            res[k] = '0';
        }
        res[k] = '\0';
        shift++;
        char temp1[2048] = "";
        add(result, res, temp1);
        strcpy(result, temp1);
    }
}