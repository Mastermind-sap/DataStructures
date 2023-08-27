#include <stdio.h>

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

void main(){
    long long a;
    printf("Enter a:");
    scanf("%lld", &a);
    long long b;
    printf("Enter b:");
    scanf("%lld", &b);
    printf("%lld to the power %lld id %lld",a,b,binpow(a,b));
}