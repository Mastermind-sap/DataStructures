#include <stdio.h>
#include <math.h>

void conventional(long n)
{
    for (long i = 2; i <= n; i++)
    {
        int flag = 0;
        long range = sqrt(i);
        for (long j = 2; j <= range; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)printf("%ld, ",i);
    }
    printf("\n");
}


void sieve_of_eratosthenes(int n)
{
    int is_prime[n + 1];
    is_prime[0] = is_prime[1] = 0;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d, ",i);
        }
    }
}

void main(){
    long n;
    printf("Enter n:");
    scanf("%ld", &n);
    printf("Prime numbers through conventional method:\n");
    conventional(n);
    printf("Prime numbers through sieve of eratosthenes method:\n");
    sieve_of_eratosthenes(n);
}