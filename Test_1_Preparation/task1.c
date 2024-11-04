#include <stdio.h>

// return 1 if prime number
int checkPrime(int num) {
    if (num == 1) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int arr[] = {1, 7, 10, 15, 16, 13, 23, 30};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < arr_size; i++) {
        if (checkPrime(arr[i])) {
            printf("%d\n", arr[i]);
            sum += arr[i];
        }
    }

    printf("%d", sum);

    return 0;
}
