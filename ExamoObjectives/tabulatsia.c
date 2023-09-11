#include <stdio.h>
#include <math.h>
 
int main() {

    double lbor, rbor, step;
    printf("Left border: ");
    scanf("%lf", &lbor);
    printf("\n");
    printf("Right border: ");
    scanf("%lf", &rbor);
    printf("\n");
    printf("Step: ");
    scanf("%lf", &step);
    printf("\n");
    printf("_____________________________________________\n");
    printf("X___________________________________________Y\n");

    for (double x = lbor; x <= rbor; x += step) {
        printf("%lf\n", x);
        long long y = 43*pow(x, 4) + 72*pow(x, 3) - 92*pow(x, 2) + 34*x - 95;

        printf("%f                               %lld\n", x, y);

    }

}