#include <stdio.h>
#include "compare.h"
#include "swap_ptr.h"

void bubble_sort(int *arr, int size, int (*compare)(void*, void*), void (*swap)(void*, void*)) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(&arr[j], &arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int x = 1, y = 2;
    printf("compare_asc(&x, &y) = %d\n", compare_asc(&x, &y));
    printf("compare_desc(&x, &y) = %d\n", compare_desc(&x, &y));
    printf("compare_asc(&y, &x) = %d\n", compare_asc(&y, &x));
    printf("compare_desc(&y, &x) = %d\n", compare_desc(&y, &x));
    printf("compare_asc(&x, &x) = %d\n", compare_asc(&x, &x));
    printf("compare_desc(&x, &x) = %d\n", compare_desc(&x, &x));

    printf("Before swap: a = %d, b = %d\n", x, y);
    swap(&x, &y);
    printf("a = %d, b = %d\n", x, y);

    int arr[] = {3, 2, 1, 4, 5};

    bubble_sort(arr, 5, compare_asc, swap);
    print_arr(arr, 5);
    printf("\n");
    bubble_sort(arr, 5, compare_desc, swap);
    print_arr(arr, 5);
    return 0;
}