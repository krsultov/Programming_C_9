#include <stdio.h>

int find_LCM(int a, int b) {
    int max = a > b ? a : b;
    while (1) {
        if (max % a == 0 && max % b == 0) {
            return max;
        }
        max++;
    }
}

int main() {
    int a = 12;
    int b = 18;
    printf("LCM of %d and %d is %d\n", a, b, find_LCM(a, b));
    return 0;
}