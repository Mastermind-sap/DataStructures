#include <stdio.h>
#include "add.h"

void main()
{
    char res[1100];
    char a[1024], b[1024];
    printf("Enter first number:");
    scanf("%s", a);
    printf("Enter second number:");
    scanf("%s", b);
    add(a, b, res);
    printf("The sum of %s and %s is %s", a, b, res);
}