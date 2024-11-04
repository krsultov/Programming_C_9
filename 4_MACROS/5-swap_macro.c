#include <stdio.h>

#define SWAP(X, Y, TYPE) \
TYPE temp = X;           \
X = Y;                   \
Y = temp;

int main(void) {
    int a = 5;
    int b = 10;

    //char c = 'A';
    //char d = 'B';

    printf("Before swap: a = %d, b = %d\n", a, b);
    //printf("Before swap: c = %c, d = %c\n", c, d);

    SWAP(a, b, int);
    //SWAP(c, d, char);

    printf("After swap: a = %d, b = %d\n", a, b);
    //printf("After swap: c = %c, d = %c\n", c, d);

    return 0;
}