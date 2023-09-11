#include <stdio.h>

long long int reversed(long long n) {
    
    long long new_n = 0;
    
    while (n > 0) {
        
        new_n = new_n * 10 + n % 10;
        n /= 10;
        printf("%lld - is new_n\n", new_n);
        printf("%lld - is n\n", n);
    }
    return new_n;
    
}

int main() {
    
    long long n;
    
    scanf("%lld", &n);
    
    
    if (n == 0 || (n == reversed(n))) {
        printf("N = %lld is polyndrom\n", n);
    }
    else {
        printf("N = %lld not is polyndrom\n", n);
    }
    
}