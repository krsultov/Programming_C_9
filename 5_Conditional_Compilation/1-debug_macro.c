#include <stdio.h>

#define DEBUG

void sort_and_add(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

#ifdef DEBUG
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
#endif

    int sum = 0;
#ifdef DEBUG
    printf("Elements at indexes divisible by 3: ");
#endif
    for (int i = 0; i < size; i++) {
        if (i % 3 == 0) {
            sum += arr[i];
#ifdef DEBUG
            printf("%d ", arr[i]);
#endif
        }
    }
    printf("\nSum: %d\n", sum);
}

int main(void) {
    int arr[] = {7, 2, 9, 1, 6, 4, 10, 3, 8, 5, 12, 11, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort_and_add(arr, size);

    return 0;
}