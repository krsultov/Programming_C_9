#include <stdio.h>

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void reverse_array(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void sort_based_on_os(int arr[], int size) {
#if defined(_WIN32) || defined(_WIN64)
    bubble_sort(arr, size);
#elif defined(__linux__)
    selection_sort(arr, size);
#elif defined(__APPLE__)
    insertion_sort(arr, size);
#else
    reverse_array(arr, size);
#endif
}

int main(void) {

    int arr[] = {7, 2, 9, 1, 6, 4, 10, 3, 8, 5, 12, 11, 16};

    int size = sizeof(arr) / sizeof(arr[0]);

    sort_based_on_os(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}