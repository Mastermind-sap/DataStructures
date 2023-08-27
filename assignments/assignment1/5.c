#include <stdio.h>

double binpow(double a, int b)
{
    if (b == 0)
        return 1;
    double res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

void main()
{
    double a;
    printf("Enter a:");
    scanf("%lf", &a);
    int b;
    printf("Enter b:");
    scanf("%d", &b);
    printf("%lf to the power %d id %lf", a, b, binpow(a, b));
}