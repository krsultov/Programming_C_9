#include <stdio.h>

union Number {
    long odd;
    short even;
};

int main(void) {
    union Number numbers[10];

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            numbers[i].even = i;
        } else {
            numbers[i].odd = i;
        }
    }

    printf("Odd indices:\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            printf("%ld\n", numbers[i].odd);
        }
    }

    printf("Even indices:\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            printf("%d\n", numbers[i].even);
        }
    }

    return 0;
}