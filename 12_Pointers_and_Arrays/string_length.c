#include <stdio.h>

int find_length(char *arr) {
    int len = 0;
    while (*(arr + len) != '\0') {
        len++;
    }

    return len;
}

int main(void) {
    char str[] = "Hello, World!";

    printf("Length of string: %d\n", find_length(str));

    return 0;
}