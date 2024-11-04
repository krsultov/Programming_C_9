#include <stdio.h>

long decToBin(int num) {
    if (num == 0) {
        return 0;
    }
    return num % 2 + 10 * decToBin(num / 2);
}

int main(void) {

    printf("%ld", decToBin(10));

    return 0;
}