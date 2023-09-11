#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LEN 100

int main() {

    char text[MAX_INPUT_LEN];
    char word[MAX_INPUT_LEN];
    printf("Enter text:\n");
    scanf("%s", text);
    printf("Enter a word you want to find: ");
    scanf("%s", word);

    int text_len = strlen(text);
    int word_len = strlen(word);

    for (int i = 0; i < text_len; i++) {
        for (int j = 0; j < word_len; j++) {
            if (text[i + j] != word[j]) {
                break;
            } else if (j == word_len - 1) {
                printf("\nThe word you're searching starts at the %d letter of the text", i + 1);
                break;
            }
        }
    }

    return 0;
}