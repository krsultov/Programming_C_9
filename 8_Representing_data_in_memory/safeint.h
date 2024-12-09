#ifndef SAFEINT_H
#define SAFEINT_H

struct SafeInt {
    int value;
    int errorflag;
};

struct SafeInt safeadd(int a, int b);
struct SafeInt safesubtract(int a, int b);
struct SafeInt safemultiply(int a, int b);
struct SafeInt safedivide(int a, int b);
struct SafeInt safestrtoint(char *str);

#endif
