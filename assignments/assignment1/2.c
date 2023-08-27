#include <stdio.h>
#include "multiply.h"

void main()
{
    char res[2048];
    char a[1024], b[1024];
    printf("Enter first number:");
    scanf("%s", a);
    printf("Enter second number:");
    scanf("%s", b);
    multiply(a, b, res);
    printf("The product of %s and %s is %s", a, b, res);
}