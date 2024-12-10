#include "quadratic_roots.h"
#include <stdio.h>

void print_roots(struct Quadratic_Roots_Result result) {
    if (result.no_real_roots == 0) {
        printf("Roots are: %Lf and %Lf\n", result.x1, result.x2);
    } else {
        printf("No real roots\n");
    }
}

int main() {
    int a_int = 5;
    int b_int = 6;
    int c_int = 1;

    float a_float = 5.0;
    float b_float = 6.0;
    float c_float = 1.0;

    double a_double = 5.0;
    double b_double = 6.0;
    double c_double = 1.0;

    print_roots(find_roots(a_int, b_int, c_int));
    print_roots(find_roots(a_float, b_float, c_float));
    print_roots(find_roots(a_double, b_double, c_double));

    return 0;
}