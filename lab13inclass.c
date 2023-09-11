#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>

int main(){

    int64_t set1 = 0;
    int64_t set2 = 0;
    bool is_equal = false;
    bool already_check = false;

    int c;


    while ((c = getchar())) {
        
        if (isalpha(c)) {
            set1 |= (1u << (c - 'a'));
            already_check = false;
        } else if (!already_check && (isspace(c) || c == EOF)) {
            if (set1 == set2 && set1 > 0) {
                printf("YES\n");
                is_equal = true;
                break;
            }
            set2 = set1;
            set1 = 0;
            already_check = true;
        }
        if (c == EOF) break;
    } 
    if (!is_equal) {
        printf("NO\n");
    }
    return 0;
}