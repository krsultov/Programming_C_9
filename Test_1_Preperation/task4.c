#include <stdio.h>

int binSearch(int arr[], int size, int target) {
    int bottom = 0;
    int top = size - 1;

    while (bottom <= top) {
        int middle = bottom + (top - bottom) / 2;

        if (arr[middle] == target) {
            return middle;
        }

        if (arr[middle] < target) {
            bottom = middle + 1;
        } else {
            top = middle - 1;
        }
    }

    return -1;
}

int main(void) {
    int arr[] = {1, 2, 5, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", binSearch(arr, size, 5));
    printf("%d", binSearch(arr, size, 6));

    return 0;
}
