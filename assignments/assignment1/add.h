#include <stdio.h>

void add(char *a, char *b, char *res)
{
    int len1 = 0, len2 = 0;
    for (; a[len1] != '\0'; len1++)
        ;
    for (; b[len2] != '\0'; len2++)
        ;
    int carry = 0, k = 0;
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--, k++)
    {
        if (i > -1 && j > -1)
        {

            int temp = (a[i] - '0') + (b[j] - '0') + carry;
            if (temp > 9)
            {
                carry = temp / 10;
                temp = temp % 10;
            }
            else
                carry = 0;
            res[k] = (temp + '0');
        }
        else if (i > -1)
        {
            int temp = (a[i] - '0') + carry;
            if (temp > 9)
            {
                carry = temp / 10;
                temp = temp % 10;
            }
            else
                carry = 0;
            res[k] = (temp + '0');
        }
        else if (j > -1)
        {
            int temp = (b[j] - '0') + carry;
            if (temp > 9)
            {
                carry = temp / 10;
                temp = temp % 10;
            }
            else
                carry = 0;
            res[k] = (temp + '0');
        }
    }
    if (carry == 0)
        res[k] = '\0';
    else
    {
        while (carry != 0)
        {
            res[k] = (carry % 10) + '0';
            carry /= 10;
            k++;
        }
        res[k] = '\0';
    }
    int lenRes = 0;
    for (; res[lenRes] != '\0'; lenRes++)
        ;
    for (int i = 0; i < lenRes / 2; i++)
    {
        char t = res[i];
        res[i] = res[lenRes - i - 1];
        res[lenRes - i - 1] = t;
    }
}
