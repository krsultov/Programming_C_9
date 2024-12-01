#include <stdio.h>

#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }
    if (strlength(argv[1]) > 50 || strlength(argv[2]) > 50) {
        printf("Strings are too long.\n");
        return 1;
    }
    strconcat(argv[1], argv[2]);
    printf("%s\n", argv[1]);
}