#include <stdio.h>
#include "safeint.h"
#include "util.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: safesubtract <num1> <num2>");
        return 1;
    }

    struct SafeInt num1 = safestrtoint(argv[1]);
    struct SafeInt num2 = safestrtoint(argv[2]);

    if (num1.errorflag || num2.errorflag) {
        printf("Arguments exceed allowable values.");
        return 1;
    }

    struct SafeInt result = safesubtract(num1.value, num2.value);
    if (result.errorflag) {
        PRINT_OVERFLOW_ERROR
        return 1;
    }

    printf("Result: %d\n", result.value);
    return 0;
}