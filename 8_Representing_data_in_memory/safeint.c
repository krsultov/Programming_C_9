#include "safeint.h"

#include <limits.h>

struct SafeInt safeadd(int a, int b) {
    struct SafeInt result;
    result.errorflag = 0;
    result.value = 0;
    long long temp = (long long)a + b;
    if (temp > INT_MAX || temp < INT_MIN) {
        result.errorflag = 1;
    } else {
        result.value = (int)temp;
    }
    return result;
}

struct SafeInt safesubtract(int a, int b) {
    struct SafeInt result;
    result.errorflag = 0;
    result.value = 0;
    long long temp = (long long)a - b;
    if (temp > INT_MAX || temp < INT_MIN) {
        result.errorflag = 1;
    } else {
        result.value = (int)temp;
    }
    return result;
}

struct SafeInt safemultiply(int a, int b) {
    struct SafeInt result;
    long long temp = (long long)a * b;
    result.errorflag = 0;
    result.value = 0;
    if (temp > INT_MAX || temp < INT_MIN) {
        result.errorflag = 1;
    } else {
        result.value = (int)temp;
    }
    return result;
}

struct SafeInt safedivide(int a, int b) {
    struct SafeInt result;
    result.errorflag = 0;
    result.value = 0;
    if (b == 0) {
        result.errorflag = 1;
    } else {
        result.value = a / b;
    }
    return result;
}

struct SafeInt safestrtoint(char *str) {
    struct SafeInt result;
    result.errorflag = 0;
    result.value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            result.errorflag = 1;
            result.value = 0;
            return result;
        }
        int digit = str[i] - '0';
        struct SafeInt multiplyResult = safemultiply(result.value, 10);
        struct SafeInt addResult = safeadd(result.value*10, digit);

        if (multiplyResult.errorflag || addResult.errorflag) {
            result.errorflag = 1;
            result.value = 0;
            return result;
        }

        result = addResult;
    }
    return result;
}
