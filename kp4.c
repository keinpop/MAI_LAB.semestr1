#include <stdio.h>
#include <math.h>

double eps; // Глобальная переменная

double get_machine_eps()
{
    double epsylone = 1.0;
    while((1.0 + epsylone / 2) > 1.0) {
        epsylone /= 2;
    }
    return epsylone;
}

double f1(double x)
{
	return tan(x / 2) - (1 / tan(x / 2)) + x;
}

double F1(double x)
{
	return M_PI / 2 - atan(x / 2);
}

double derivative_f1(double x)
{
	return (1 / pow(cos(x / 2), 2) + 1 / pow(sin(x / 2), 2) + 2) / 2;
}

double f2(double x)
{
	return 0.4 + atan(sqrt(x)) - x;
}

double F2(double x)
{
	return 0.4 + atan(sqrt(x));
}

double derivative_f2(double x)
{
	return (1 / (2 * (pow(x, 3 / 2) + pow(x, 1 / 2)))) - 1;
}

void dichotomy_method(double a, double b, double (*f) (double))
{
	double c;
	int i = 0;

	while(fabs(a - b) >= eps)
	{
		c = (a + b) / 2;
		if ((*f)(a) * (*f)(c) > 0) a = c;
		else b = c;
		i++;
	}
	printf("| Dichotomy method  | %4d | %.16lf |\n", i, (a + b) / 2);
}

void iterative_method(double x1, double x2, double (*F) (double))
{
	int i = 0;

	x2 = (x1 + x2) / 2;
	do {
		x1 = x2;
		x2 = (*F)(x1);
		i++;
	} while(fabs(x1 - x2) >= eps);
	printf("| Iterative methode | % 4d | %.16lf |\n", i, x2);
}

void newton_method(double x1, double x2, double (*f) (double), double (*derivative_f) (double))
{
	int i = 0;

	x2 = (x1 + x2) / 2;
	do {
		x1 = x2;
		x2 = x1 - (*f)(x1) / (*derivative_f)(x1);
		i++;
	} while(fabs(x1 - x2) >= eps);
	printf("| Newton's method   | %4d | %.16lf |\n", i, x2);
}

void print_table(double a, double b, double (*f) (double), double (*F) (double), double (*derivative_f) (double))
{
	printf(" _______________________________________________\n");
	printf("|    Method name    | iter |        root        |\n");
	printf("|———————————————————|——————|————————————————————|\n");
	dichotomy_method(a, b, f);
	printf("|———————————————————|——————|————————————————————|\n");
	iterative_method(a, b, F);
	printf("|———————————————————|——————|————————————————————|\n");
	newton_method(a, b, f, derivative_f);
	printf(" ———————————————————————————————————————————————\n");
}

void main()
{
	double a = 1.0, b = 2.0;
	int k;

	scanf("%d", &k);
	eps = get_machine_eps() * pow(10, k);
	printf("epsylone = %g\n\n", eps);

	printf("             Root for equation №1\n");
	print_table(a, b, f1, F1, derivative_f1);
	printf("             Root for equation №2\n");
	print_table(a, b, f2, F2, derivative_f2);
}