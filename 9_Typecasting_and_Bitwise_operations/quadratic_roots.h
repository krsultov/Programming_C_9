#ifndef QUADRATIC_ROOTS_H
#define QUADRATIC_ROOTS_H

struct Quadratic_Roots_Result {
    long double x1;
    long double x2;
    int no_real_roots;
};

struct Quadratic_Roots_Result find_roots(long double a, long double b, long double c);

#endif