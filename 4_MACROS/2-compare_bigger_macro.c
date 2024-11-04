#include <stdio.h>

#define COMPARE_BIGGER(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    int a = 5;
    int b = 10;

    printf("The bigger number is: %d\n", COMPARE_BIGGER(a, b));

    return 0;
}