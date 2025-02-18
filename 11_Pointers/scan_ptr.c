#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    int *p = &a;
    int *p1 = &b;

    printf("a = %d, b = %d\n", a, b);
    printf("p = %p, p1 = %p\n", p, p1);
}