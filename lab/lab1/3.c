#include <stdio.h>

double sroot(long n)
{
    double approx;
    for (long i = 0; i <= n / 2; i++)
    {
        if (i * i <= n)
            approx = i;
        else
            break;
    }
    double inc = 0.1;int precision = 5;
    for (int i = 0; i < precision; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (approx * approx < n)
                approx += inc;
            else
                break;
        }
        inc /= 10.0;
    }
    return approx;
}

void main()
{
    long n;
    printf("Enter n:");
    scanf("%ld", &n);
    printf("Square root of %ld is: %Lf", n, sroot(n));
}