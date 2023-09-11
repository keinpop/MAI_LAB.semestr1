#include <stdio.h>

int main()
{
    double a = 0.1, b = 0.2, c = 0.3;
    if ((a + b) + c == 0.6) {
        printf("Yes\n");
    } else printf("No, because a+b=%0.17lf\n", (a + b) + c);

    if (a + (b + c) == 0.6) {
        printf("Yes\n");
    } else printf("No, because a+b=%0.17lf\n", a + (b + c));

    return 0;
}