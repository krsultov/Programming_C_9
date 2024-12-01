#include <stdio.h>

#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }
    printf("%d", strcompare(argv[1], argv[2]));
}