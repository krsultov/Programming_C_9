#include "quadratic_roots.h"
#include <math.h>

struct Quadratic_Roots_Result find_roots(long double a, long double b, long double c) {
    struct Quadratic_Roots_Result result;
    result.x1 = 0;
    result.x2 = 0;
    result.no_real_roots = 0;

    float discriminant = b * b - 4.00 * a * c;

    if (discriminant > 0) {
        result.x1 = (-b + sqrtl(discriminant)) / (2.00 * a);
        result.x2 = (-b - sqrtl(discriminant)) / (2.00 * a);
        result.no_real_roots = 0;
    } else if (discriminant == 0) {
        result.x1 = -b / (2.00 * a);
        result.x2 = -b / (2.00 * a);
        result.no_real_roots = 0;
    } else {
        result.no_real_roots = 1;
    }

    return result;
}