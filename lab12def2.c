#include <stdio.h> // Используем стандартную библиотеку 

int mypow(int base, int k) //Функция целочисленного возведения в степень
{
    int res = 1; // Начальная степень числа 1
    while (k != 0) { // Используем цикл пока степень k не 0
        res = res * base; // Формула возведения в степень
        k--; // Уменьшение степени на 1 при каждой итерации цикла
    }
    return res; // Функция выводит значение полученной степени
}

int get_num_digits(int num) //Количество разрядов числа - возвращает на один разряд меньше в числе
{
    int num_digits = 0; // Изначальный разряд числа 0
    while (num /= 10) { // Цикл деления поразрядно
        num_digits++; // Прибавляем в наше колличество разрядов при каждой итерации
    }
    return num_digits; // Функция выводит разряд
}

int main()
{
    int num;
    while(scanf("%d", &num) != EOF) {
        for (int num_digits = get_num_digits(num); num_digits >= 0; num_digits--){ 
            int digit = (num / mypow(10, num_digits)) % 10;
            if (digit % 3 == 0) {
                printf("%d", digit); 
            }
        }
        printf("\n");
    }
    return 0;
}