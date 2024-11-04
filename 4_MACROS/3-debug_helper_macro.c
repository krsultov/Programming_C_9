#include <stdio.h>

#define DEBUG_VAR(var) printf("Variable " #var " = %d in %s at line %d\n", var, __FILE__, __LINE__)

int main(void) {
    int x = 10;
    int y = 20;

    DEBUG_VAR(x);
    DEBUG_VAR(y);

    return 0;
}