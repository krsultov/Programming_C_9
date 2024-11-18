#include <stdio.h>
#include <math.h>

int main(void) {
    long numbers[4] = {1, 2, 3, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++) {
        numbers[i] = pow(numbers[i], 4);
    }

    for (int i = 0; i < size; ++i) {
        printf("%ld ", numbers[i]);
    }

    return 0;
}