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
    

    int max = matrix[0][0]; // максимальный элемент - 1 в матрице
    int min = matrix[0][0];
    int j_last = 0; // Полсдений минимальный столбец, куда вводим сумму
    int i_last = 0;


    for (i = 0; i < matrix_size; i++) {  // обход строк
        for  (j = 0; j < matrix_size; j++) { // обход столбцов
            if (matrix[i][j] > max || (matrix[i][j] == max && j > j_last)) { // нахождение минимального символа и минимального столбца
                max = matrix[i][j];
                j_last = j;
            }
            if (matrix[i][j] <= min) {
                min = matrix[i][j];
                i_last = i;
            }       
        }
    }

    int res = 0;

    for (int i = 0; i < matrix_size; i++) {
        printf("%d %d\n", matrix[i][j_last], matrix[i_last][i]);
        res += matrix[i][j_last] * matrix[i_last][i];
        }

    printf("%d ", res);

    return 0;
}