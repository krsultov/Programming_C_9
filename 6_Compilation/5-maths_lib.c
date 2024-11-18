#include "5-maths_lib.h"
#include <stdio.h>

int factoriel(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factoriel(n - 1);
}