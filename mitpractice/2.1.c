#include <stdio.h>

void main()
{
    int val = 0xCAFE;
    printf("%x", val);
    //%x for hexa %o for octal

    // a
    int ans = 0, check = 1, value = val;
    while (check == 1)
    {
        if ((value & check) == 1)
            ans++;
        check=(value & check);
        value >> 1;
    }
    printf("%d", ans);

    // b


}