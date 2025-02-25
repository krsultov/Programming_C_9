#include <stdio.h>

void strhalf(char *str, char **ptr) {
    int len = 0;
    while (*(str + len) != '\0') {
        len++;
    }

    *ptr = str + len / 2;

}

int main(void) {
    char str[] = "Hello, World!";
    char *half_ptr;

    printf("Original string: %s\n", str);
    strhalf(str, &half_ptr);
    printf("Half string: %s\n", half_ptr);

    return 0;
}