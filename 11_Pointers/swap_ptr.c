#include <stdio.h>

void swap(void *a, void *b) {
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}

// int main(void) {
//     int a,b;
//     scanf("%d", &a);
//     scanf("%d", &b);
//
//     swap(&a, &b);
//
//     printf("a = %d, b = %d\n", a, b);
//
//     return 0;
// }