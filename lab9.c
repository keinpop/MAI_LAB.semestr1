//ФИО: Железнов Илья Васильевич 
//Группа: М8О-104Б-22 
//Вариант: 20

//Используем 2 стандартные библиотеки
#include <stdio.h>
#include <stdlib.h>

//ВВедём константы, которые даны нам в условии (Координаты точки)
#define I_START -25
#define J_START -9
#define L_START -8

//Количество шагов, за которое пройдет точка
#define STEPS 50    

//Расстояние полосы
#define COND_1 -20
#define COND_2 -10

//Введем целочисленную переменную sign, входяющую в формулы 
int sign(int a)
{
    if (a > 0) {
        return 1;
    }
    if (a < 0) {
        return -1;
    }
    return 0;
}

//Введем целочисленную переменную max, входяющую в формулы 
int max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

//Введем целочисленную переменную min, входящую в формулы
int min(int a, int b)
{
    if (a < b) {
        return a;
    }
    return b;
}

//Введем функцию get_i_next, которая отвечает за формулу i от k+1 (Данная функция возвращает нам результат формулы)
int get_i_next(int i, int j, int k, int l)
{
    return (abs(i - j) * l - abs(j - l) * i + abs(i - l) * j) % 20 - k;
}

//Введем функцию get_j_next, которая отвечает за формулу j от k+1
int get_j_next(int i, int j, int k, int l)
{ 
    return (min(i, j) * max(j, l) * min(i, l)) % 25 + 5 * sign(i) + k;  
}

//Введем функцию get_l_next, которая отвечает за формулу l от k+1 
int get_l_next(int i, int j, int k, int l)
{
    return abs(l) * sign(i - j) - abs(i) * sign(j - l) + abs(j) * sign(i - l);
}

//Наша главная функци, которая и будет проверять попадём ли мы в наш интервал или нет
int main()
{

    //Присвоим переменным i, k, l значение констант
    int i = I_START;
    int j = J_START;
    int l = L_START;
    // Добавим цикл for, для проверки попадания за K шагов
    for (int k = 1; k <= STEPS; k++) {
        //Точки i_next, j_next, l_next это точки, находящиеся на каждом новом шаге k
        int i_next = get_i_next(i, j, k, l);
        int j_next = get_j_next(i, j, k, l);
        int l_next = get_l_next(i, j, k, l);

        //В операторе if указываем наше расстояние (куда нам надо попасть(дано в условии))
        if (i_next + j_next >= COND_1 && i_next + j_next <= COND_2) {
            //Здесь мы выведем "да", если попадем (Да и все значения шага попадания)
            printf("Yes: k = %d, i = %d, j = %d, l = %d\n", k, i_next, j_next, l_next);

            return 0; 
        }

        //Мы приравняли эти значения для того, чтобы цикл for не забывал каждый k-ый шаг значения i, j, l
        i = i_next;
        j = j_next;
        l = l_next;
    }
    //Здесь мы выведем "нет", если не попадем
    printf("No.\n");

    return 0;
}
