#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_AXIS_LEN 101
#define DEFAULT_UNIT 5.0
#define DEFAULT_PRECISION 0.3

int main() {

    double unit = DEFAULT_UNIT;
    float precision = DEFAULT_PRECISION;
    printf("How many characters will be taken for 1 unit: ");
    scanf("%lf", &unit);
    printf("Enter precision (0.3 - is good for most cases): ");
    scanf("%f", &precision);

    char coord[MAX_AXIS_LEN][MAX_AXIS_LEN];

    printf("\n");
    int mid_axis = MAX_AXIS_LEN / 2 + 1;
    for (int y = 0; y < MAX_AXIS_LEN; y++) {
        for (int x = 0; x < MAX_AXIS_LEN; x++) {
            if (y == mid_axis) {
                coord[y][x] = '-';
            } else {
                coord[y][x] = ' ';
            }
        }
        coord[y][mid_axis] = '|';
    }

    double sized_x, sized_y;

    for (int y = -mid_axis; y < mid_axis; y++) {
        sized_y = y / unit;
        for (int x = -mid_axis; x < mid_axis; x++) {
            sized_x = x / unit;
            if (fabs(sin(sized_x) - sized_y) < precision) {
                coord[mid_axis - y][mid_axis + x] = '*';
            }
        }
    }    

    for (int y = 0; y < MAX_AXIS_LEN; y++) {
        for (int x = 0; x < MAX_AXIS_LEN; x++) {
            printf("%c", coord[y][x]);
        }
        printf("\n");
    }

    return 0;
}