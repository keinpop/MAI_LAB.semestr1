//ФИО: Железнов Илья Васильевич
//Группа: М8О-104Б-22
//Вариант: 6
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>

#define VOWELS_SEARCH (1u << ('y' - 'a') | \ // Составляем множество гласных, которые нам нужны
                    1u << ('u' - 'a') | \
                    1u << ('e' - 'a'))   
#define VOWELS_NULL (1u << ('a' - 'a') | \ // Которые не нужны
                1u << ('i' - 'a') | \
                1u << ('o' - 'a'))


int main() {

    bool has_search_vowels = false; // Проверка наличия нужных гласных
    bool new_word = false; // Проверк на новое слово
    bool result = false; // Получен ли, нужный результат
    int res = 0; // Накопление нужного результата

    while (1) { // Пока ввод не достиг конца файла
        char c = getchar(); // Ввод символов
        if (isalpha(c)) { // Если "с" - буква
            c = tolower(c); // Переводим букву в нижний регистр
            if ((1u << (c - 'a'))& VOWELS_SEARCH) { // если это битовое значение и оно искомая гласная
                if (!has_search_vowels && !new_word) { // проверка на новое слово и искомую гласную
                    result = true; 
                    has_search_vowels = true;
                }
                
            } else if ( (1u << (c - 'a')) & VOWELS_NULL) { // если это не нужная гласная
                has_search_vowels = false;
                new_word = true;
                result = false;
            }
        } else if ((isspace(c)) || (c == EOF)) { // Если "с" - разделительный знак или конец файла
            if (result == true) { // если результат найден
                res++; // Накапливаем
            break; // Выходим из цикла
            }
            has_search_vowels = false;
            new_word = false;
            result = false;

            if (c == EOF) { // Если 'c' - конец файла 
                break;
            }
        }
    }
    if (res != 0) {
        printf("\n You have the searching word. \n");
    } else printf("\n You dont have the searching word. \n");
    return 0;
}