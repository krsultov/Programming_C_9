#include <stdio.h>

int compare_asc(void* a, void* b) {
    if (*(int*)a > *(int*)b) {
        return 1;
    }

    if (*(int*)a < *(int*)b) {
        return -1;
    }

    return 0;
}

int compare_desc(void* a, void* b) {
    if (*(int*)a > *(int*)b) {
        return -1;
    }

    if (*(int*)a < *(int*)b) {
        return 1;
    }

    return 0;
}

// int main(void) {
//     int x = 1, y = 2;
//     printf("compare_asc(&x, &y) = %d\n", compare_asc(&x, &y));
//     printf("compare_desc(&x, &y) = %d\n", compare_desc(&x, &y));
//     printf("compare_asc(&y, &x) = %d\n", compare_asc(&y, &x));
//     printf("compare_desc(&y, &x) = %d\n", compare_desc(&y, &x));
//     printf("compare_asc(&x, &x) = %d\n", compare_asc(&x, &x));
//     printf("compare_desc(&x, &x) = %d\n", compare_desc(&x, &x));
//
//     return 0;
// }