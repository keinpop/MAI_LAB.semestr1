#include <stdio.h>
#include <ctype.h>

int rank_digit(int digit) // Функция вычесления разряда
{
    int rank = 0;
    while (digit /= 10) {
        rank++;
    }
    return rank;
}

int my_pow(int base, int k) // Функция вычисления степени, можно и <math.h>, но лень компилить с -lm
{
    int res = 1;
    while (k != 0) {
        res = res * base;
        k--;
    }
    
    return res;
}

int cheak(int num) // Проверка на наличие 'специальных' десяток 
{
    int digit = num / my_pow(10, rank_digit(num));
    int res = num - digit * 100;
    return res;
}

void hundred_rank(int num) // Замена сотен
{
    switch (num) {
                case 1:
                    printf("one hundred ");
                    break;
                case 2:
                    printf("two hundred ");
                    break;
                case 3:
                    printf("three hundred ");
                    break;
                case 4:
                    printf("four hundred ");
                    break;
                case 5:
                    printf("five hundred ");
                    break;
                case 6:
                    printf("six hundred ");
                    break;
                case 7:
                    printf("seven hundred ");
                    break;
                case 8:
                    printf("eight hundred ");
                    break;
                case 9:
                    printf("nine hundred ");
                    break;
                }    
}

void tenth_rank(int num) // Замена десяток 
{
    switch (num) {
                case 2:
                    printf("twenty ");
                    break;
                case 3:
                    printf("therty ");
                    break;
                case 4:
                    printf("fourty ");
                    break;
                case 5:
                    printf("fifty ");
                    break;
                case 6:
                    printf("sixty ");
                    break;
                case 7:
                    printf("seventy ");
                    break;
                case 8:
                    printf("eighy ");
                    break;
                case 9:
                    printf("ninety ");
                    break;
                }    
}

void tenth_special_rank(int num) // Замена на специальные десятки
{
    switch (num) {
        case 10:
            printf("ten");
            break;
        case 11:
            printf("eleven");
            break;
        case 12:
            printf("twelve");
            break;
        case 13:
            printf("thirteen");
            break;
        case 14:
            printf("fourteen");
            break;
        case 15:
            printf("fifteen");
            break;
        case 16:
            printf("sixteen");
            break;
        case 17:
            printf("seventeen");
            break;
        case 18:
            printf("eighteen");
            break;
        case 19:
            printf("nineteen");
            break;
    }
}

void single_rank(int num) // Замена единиц
{
    switch (num) {
                case 1:
                    printf("one");
                    break;
                case 2:
                    printf("two");
                    break;
                case 3:
                    printf("three");
                    break;
                case 4:
                    printf("four");
                    break;
                case 5:
                    printf("five");
                    break;
                case 6:
                    printf("six");
                    break;
                case 7:
                    printf("seven");
                    break;
                case 8:
                    printf("eight");
                    break;
                case 9:
                    printf("nine");
                    break;
                }    
}

// Спеллинг будет работать для чисел от -999 до 999
int main()
{
    int num; // Переменная над которой проводим спеллинг
    
    while (scanf("%d", &num) !=EOF) { // Цикл ввода переменной
        if (num < 0) { // Проверка на минус
            printf("minus ");
            num = - num;
        }
        if (num == 0) printf("zero\n"); // Проверка на ноль

        if(num > 9 && num < 20) {
            tenth_special_rank(num);
        } else {
            for (int rank = rank_digit(num); rank >= 0; rank--) { // Цикл посимвольного спеллинга
                int digit = (num / my_pow(10, rank)) % 10; // Запись разряда числа
                switch (rank) { // Меняем числа на слова
                    case 2: // Сотни
                        hundred_rank(digit);
                        break;
                    case 1: // Десятки
                        // Эта проверка делается, т.к. в англ. языке от 10 до 19 говорится ten, eleven, twelve, ..., а не ten zero, ten one, ten two, ...
                        if (cheak(num) > 9 && cheak(num) < 20) { // Если от 9 до 20 невключительно, то меняем на другой порядок замен
                            tenth_special_rank(cheak(num));

                        } else tenth_rank(digit); // Если не так, то меняем по обычному порядку чисел
                        break;
                    case 0: // Единицы
                        if (cheak(num) > 9 && cheak(num) < 20) break; // Если использовали специальный порядок чисел,то ничего в единицы не пишем
                        else single_rank(digit);
                        break;
                }
            }
         }
        printf("\n");
    }

    return 0;
}