//ФИО: Железнов Илья Васильевич 
//Группа: М8О-104Б-22 
//Вариант: 4

#include <stdio.h>

#define MATR_SIZE 7

void scanMatr(int n, int m, int matr[n][m]) // Функция ввода матрицы
{
    for (int i = 0; i < n; i++) { // Цикл строк
        for (int j = 0; j < m; j++) { // Цикл столбцов
            scanf("%d", &matr[i][j]); // Ввод квадратной матрицы
        }
    }
}

void printMatr(int n, int matr[n][n]) // Функция вывода 'матричного' результата
{ 
    int row_shift = 0; // Вспомогательная переменная для строк 
    int column_shift = 0; // Вспомогательная переменная для стобцов
 
    for (int i = 0; i < 2 * n - 1; i++) { // Цикл вывода строк
        for (int j = d; j < row_shift + 1; j++) { // Цикл вывода стобцов
            printf("%d ", matr[row_shift - j + column_shift][j]); //Вывод порядка 
        }
        
        if (i < n - 1) 
            row_shift++;
        else 
            column_shift++; 
    }
    printf("\n");
}

int main() 
{
    int matrix_size; 
    int matr[MATR_SIZE][MATR_SIZE]; // Переменная размера

    while (scanf("%d", &matrix_size) != EOF) { // Ввод размера матрицы
        scanMatr(matrix_size, matrix_size, matr); // Ввод
        printMatr(matrix_size, matr); // Вывод
    }

    return 0;
}