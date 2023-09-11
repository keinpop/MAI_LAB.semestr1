//ФИО: Железнов Илья Васильевич 
//Группа: М8О-104Б-22 
//Вариант: 25

#include <stdio.h> // Стандартная библиотека
#include <ctype.h> // Библиотека для работы с символами

#define STATE_SPACE_SYMS 1 // Все константы с припиской STATE_ - значения позиций в switch / case
#define STATE_ZERO_X_SYM 2
#define STATE_SKIP_TRASH_SYM 3
#define STATE_TRANS16_SYM 4
#define TRANS_NEW_SYST 16 // Именнованая константа для перевода в 10тичную сс

int main() {
    int state = STATE_SPACE_SYMS; // Начальное состояние 
    int c; // Переменная символа
    int digit = 0; // Число для перевода из 16ричной сс в 10тичную
    int last_num = 0; // Последнее запомненное число
    int pre_last_num = 0; //Предпоследнее запомненное число
    int count = 0; // Счетчик количества записанных чисел
    int num = 0; // Первое число
    int count_sec = 0; // Счетчик чисел записанных для проеблов

    while (1) { // Бесконечный цикл из-за (1)
        c = getchar(); // Ввод символов через терминал
        switch (state) { // Функция выбора switch из некоторых case
            case STATE_SPACE_SYMS: // Состояние проверяющее на пробельные символы
                count_sec = 0;
                if (!isspace(c)) { // Если не пробел
                    if (c == '0') 
                        state = STATE_ZERO_X_SYM; // Если символ 0, то во 2 состояние
                    else state = STATE_SKIP_TRASH_SYM; // Если нет, пропускаем его, оно нам не нужно
                    num = 0; // Число не записано
                }
                break; // Выход из цикла
            case STATE_ZERO_X_SYM: // Состояние проверяющее на 'x' после 0
                if (c == 'x') {
                    state = STATE_TRANS16_SYM;
                } else {
                    state = STATE_SKIP_TRASH_SYM;
                    }
                break;
            case STATE_SKIP_TRASH_SYM: // Состояние проверяющее на наличие ненужных символов 
                if (isspace(c) || c == EOF)
                 state = STATE_SPACE_SYMS; // если это пробел или конец файла - проверка дальше
                break;
            case STATE_TRANS16_SYM: // Перевод в 16ричную сс
                count_sec++;
                if (isspace(c) || c == EOF) { // Если это пробел или конец файла
                    state = STATE_SPACE_SYMS;
                    if (count_sec > 1) {
                    pre_last_num = last_num; // Запись последнего числа в предпоследнее число
                    state = STATE_SPACE_SYMS;
                    last_num = num; // Запись первого числа в предпоследнее 
                    count++;
                    } // Счетчик чисел записанных +1
                } else {
                    c = tolower(c); // Перевод в 16ричную
                    if(isdigit(c)) { // Если это число от (c) 
                        digit = c - '0'; // Перевод из char в int
                    } else if (c >= 'a' && c <= 'f') { // 16-ричные символы
                        digit = c - 'a' + 10; // Считаем буквы в 16-ричной
                    } else {
                        num = 0; // Не записываем
                        digit = 0;
                        state = STATE_SKIP_TRASH_SYM;
                    }
                    num = num * TRANS_NEW_SYST + digit; // Формула перевода в десятичную
                }
                break;
        }
        if (c == EOF) { // Если конец файла
            if (count > 1)
                printf("\n0x%x\n", pre_last_num); // Если количество записанных больше 1 - выводим предпоследнее
            else if (count == 0) 
                printf ("\nYou dont enter hexadecimal char:)\n"); // Если не ввели числа, то ничего:) 
            else printf("\n0x%x\n", last_num); // Если 1 число - его и выводим

        break;
        }
    }
    return 0;
}
