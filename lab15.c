//ФИО: Железнов Илья Васильевич
//Группа: М8О-104Б-22
//Вариант: 6
#include <stdio.h> // Стандартная библиотека

int main()
{
    int i, j, matrix_size; // переменные строк столбцов, размера квадратичной матрицы
  
    scanf("%d", &matrix_size); // Ввод размера матрицы
    if (matrix_size <= 0) { // Если размер матрицы меньше или равен нулю - ошибка
        printf("You input erroneous digit size, that error\n"); // Вывод текстово ошибки
        return 0; // Ранний выход из программы
    }
    
    int matrix[matrix_size][matrix_size]; // матрица, с которой работаем
  
    for (i = 0; i < matrix_size; i++) { // Вложенный цикл
        for (j = 0; j < matrix_size; j++ ) {
            scanf("%d", &matrix[i][j]); // Ввод символов матрицы
        }
    }
    printf("\n"); // отступ от результата
    
    int min = matrix[0][0]; // Минимальный элемент - 1 в матрице
    int j_last = 0; // Полсдений минимальный столбец, куда вводим сумму
    for (i = 0; i < matrix_size; i++) {  // обход строк
        for (j = 0; j < matrix_size; j++) { // обход столбцов
            if (matrix[i][j] <= min) { // нахождение минимального символа и минимального столбца
                min = matrix[i][j];
                j_last = j;
            }      
        }
    }
    
    for (j = 0; j < j_last; j++) { // обход столбцов
        for (i = 0; i < matrix_size; i++) { // обход строк
            if (matrix[i][j] == min) { // если элемент равен мнимальному
                for (int k = 0; k < matrix_size; ++k) { // начинаем обходить нашу новую матрицу-столбец
                    matrix[k][j_last] += matrix[k][j]; // прибавляем элементы
                }
                break; // Выход из цикла
            }
        }
    }

    for (int i = 0; i < matrix_size; ++i) { // Вывод получившейся матрицы
        for (int j = 0; j < matrix_size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}