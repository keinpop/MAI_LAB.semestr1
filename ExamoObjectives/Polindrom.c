#include <stdio.h>
#include <stdint.h>

long long is_palindrome(long long x) 
{
    long long reversed_x = 0;
    long long x_copy = x;
    while (x_copy != 0) {
        reversed_x = reversed_x * 10 + x_copy % 10;
        x_copy /= 10;
    }

    return x == reversed_x;
}

int main() {
    long long x;
    scanf("%lld", &x);
    printf("%lld", is_palindrome(x));
    return 0;
}