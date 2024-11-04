#include  <stdio.h>

int main(void) {
    int num = 417;
    int result = 1;

    while (num != 0) {
        int digit = num % 10;
        result *= digit;
        num /= 10;
    }

    printf("%d", result);

    return 0;
}