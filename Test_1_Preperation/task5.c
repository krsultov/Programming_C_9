#include <stdio.h>

char findBiggestASCII(char string[]) {
    char biggest = string[0];
    for (int i = 1; string[i] != '\0'; i++) {
        if (string[i] > biggest) {
            biggest = string[i];
        }
    }
    return biggest;
}

int main(void) {

    char string[] = "Ivan";
    printf("%c", findBiggestASCII(string));

    return 0;
}