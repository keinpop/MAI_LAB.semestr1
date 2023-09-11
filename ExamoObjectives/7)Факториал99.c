#include <stdio.h>
#include <malloc.h>

#define MAX_LEN 170

int main() 
{
    int *x = calloc(MAX_LEN + 1, sizeof(int));
    x[0] = 1;
    
    for (int fact = 1; fact <= 99; fact++) {
        int carry = 0;
        for (int i = 0; i < MAX_LEN; i++) {
            int mult = x[i] * fact + carry;
            printf("%d - is mult\n", mult);
            x[i] = mult % 10;
            carry = mult / 10;
            }
        }

    printf("Factorial of 99 is: ");
    int achieved_num = 0;
    for (int i = MAX_LEN - 1; i >= 0; i--) {
        if ((x[i] != 0) || (achieved_num)) {
            printf("%d", x[i]);
            achieved_num = 1;
        }
    }
    return 0;
}