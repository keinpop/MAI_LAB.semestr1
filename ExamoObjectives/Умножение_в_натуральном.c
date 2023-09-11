#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>



int main (int argc, const char * argv[])
{
    char symbol;
    int counter1 = 0;
    int counter2 = 0;
    bool num1_scanned = false;
    while (true) {
        symbol = getchar();
        if (ispunct(symbol) && num1_scanned == false) {
            counter1++;
        }
        if (symbol == 'x') {
            num1_scanned = true;
        }
        if (ispunct(symbol) && num1_scanned == true) {
            counter2++;
        }
        if (symbol == EOF || isspace(symbol)) {
            break;
        }
    }
    printf("\n");
    for (int i = 0;i < counter1 * counter2;i++) {
        printf("|");
    }
    return 0;
}


