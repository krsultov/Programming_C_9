#include <stdio.h>

void swap(void *a, void *b) {
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}

void bubble_sort(int *arr, int size, void (*swap)(void*, void*)) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + (j + 1))){
                swap(arr + j, arr + (j + 1));
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
    int arr[] = {3, 2, 1, 4, 5};

    bubble_sort(arr, 5, swap);
    print_arr(arr, 5);
    printf("\n");
    return 0;
}