#include <stdio.h>

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
    int i = 0;
    int word = 0;
    while (word != n * n) {
    for (int j = 0; j < n ; j++) { // Цикл вывода строк по столбцам
            printf("%d ", matr[j][i]); //Вывод порядка
            word++;    
    }  
    i++;
    if (word == n * n) break;
    for (int j = n-1; j >= 0; j--) { // Цикл вывода строк по столбцам
            printf("%d ", matr[j][i]); //Вывод порядка
            word++;  
    }
    i++;
    }
}

int main() 
{
    int n; 
    int matr[7][7]; // Переменная размера
    while (scanf("%d", &n) != EOF) { // Ввод размера матрицы
        scanMatr(n, n, matr); // Ввод
        printMatr(n, matr); // Вывод
    }
return 0;
}