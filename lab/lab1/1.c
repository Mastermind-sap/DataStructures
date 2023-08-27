#include <stdio.h>
#include <time.h>

// recursive method
long fibonacci1(long n)
{
    if (n <= 1)
        return n;
    return fibonacci1(n - 1) + fibonacci1(n - 2);
}

// iterative method
long fibonacci2(long n)
{
    if (n <= 1)
        return n;
    long a = 0, b = 1;
    for (int i = 1; i < n; ++i)
    {
        b = a + b;
        a = b - a;
    }
    return b;
}

// DP method
long fibonacci3(long n)
{
    if (n <= 1)
        return n;
    long a[n + 2];
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}

// *****Matrix method***************************************************************************************

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

/* Optimized version of power() in method 4 */
void power(int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

/* function that returns nth Fibonacci number */
long fibonacci4(int n)
{
    int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

// ****************************************************************************************

// Hashing method

long fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
            55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
            6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229,
            832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986};
long fibonacci5(long n){
    return fib[n];
}

void main()
{
    clock_t start, end;
    double cpu_time_used;
    long n;
    printf("Enter n:");
    scanf("%ld", &n);
    start = clock();
    printf("%ldth fibonacci number: %ld\n", n, fibonacci1(n));
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time method 1: %lf seconds\n", cpu_time_used);
    start = clock();
    printf("%ldth fibonacci number: %ld\n", n, fibonacci2(n));
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time method 2: %lf seconds\n", cpu_time_used);
    start = clock();
    printf("%ldth fibonacci number: %ld\n", n, fibonacci3(n));
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time method 3: %lf seconds\n", cpu_time_used);
    start = clock();
    printf("%ldth fibonacci number: %ld\n", n, fibonacci4(n));
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time method 4: %lf seconds\n", cpu_time_used);
    start = clock();
    printf("%ldth fibonacci number: %ld\n", n, fibonacci5(n));
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time method 5: %lf seconds\n", cpu_time_used);
}