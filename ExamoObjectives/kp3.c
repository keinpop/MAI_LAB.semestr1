#include <stdio.h>
#include <limits.h>
#include <math.h>

#define K 1
#define A 0.1
#define B 0.6
#define MAX_STEPS 100

// При использовании факториала быстро достигается переполнение integera, т.к. он может хранить в себе относительно небольшое число.
// При использовании 'double' не достигается переполнение, т.к. этот тип может хранить в себе большую степень, хоть и с меньшей точностью.
double antifactorial(int x) 
{
    double y = 1;
    for(int i = 1; i <= x; i++) {
        y /= i;
    }
    return y;
}

double get_machine_eps() 
{
    double eps = 1.0;
    while (2.0 + eps / 2.0 > 2.0) {
        eps /= 2.0;
    }

    return eps;
}

int main()
{
    int n;
    printf("Write n: \n");
    scanf("%d", &n);
    printf("n = %d, \n", n);

    double eps = get_machine_eps();
    printf("Machine eps double = %.16le\n", eps);

    printf(" _________________________________________________________\n");
    printf("|   Table of values for Taylor series and f(x) = e^(2x)   |\n");
    printf("|_________________________________________________________|\n");
    printf("|  step  | iter |    Taylor series   |   Function e^(2x)  |\n");
    printf("|________|______|____________________|____________________|\n");

    for (int i = 0; i < n; i++) {
        double x = (B - A) / n * i + A;  
        double y = exp(2 * x); 
        int j; // Номер шага на котором достигается точность ряда Тейлора
        double sum; // Значение ряда Тейлора на j-том шаге
        for (j = 0, sum = 0; fabs(y - sum) > eps * K && j < MAX_STEPS; ++j) {
            sum += pow(2 * x, j) * antifactorial(j);
        }

        printf("| %.4lf | %4d | %.16lf | %.16lf |\n", x, j, sum, y);
    }
    
    printf("|________|______|____________________|____________________|\n");
    
    return 0;
}