#include <stdio.h>

#define SWAP(X, Y, TYPE) \
TYPE temp = X;           \
X = Y;                   \
Y = temp;

#define SORT(ARRAY, SIZE, TYPE, COMPARE)                     \
for (int i = 0; i < SIZE - 1; ++i) {                         \
for (int j = 0; j < SIZE - 1 - i; ++j) {                     \
if (ARRAY[j] COMPARE ARRAY[j + 1]) {                         \
SWAP(ARRAY[j], ARRAY[j + 1], TYPE);                          \
}                                                            \
}                                                            \
}

int main(void) {
    int array[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Before sort: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    SORT(array, size, int, >);

    printf("After sort (>): ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    SORT(array, size, int, <);

    printf("After sort (<): ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}