#include "mystrings.h"

#include <stdio.h>

int strlength(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    return len;
}

void strconcat(char *dest, char *src) {

    int len1 = strlength(dest);
    int len2 = strlength(src);

    for (int i = 0; i < len2; i++) {
        dest[len1 + i] = src[i];
    }

}

int strcompare(char *str1, char *str2) {
    int len1 = strlength(str1);
    int len2 = strlength(str2);

    int longer = len1 > len2 ? len1 : len2;

    for (int i = 0; i < longer; i++) {
        if (longer > len1) {
            return -1;
        }
        if (longer > len2) {
            return 1;
        }
        if (str1[i] != str2[i]) {
            if (str1[i] < str2[i]) {
                return -1;
            }
            return 1;
        }
    }

    return 0;
}
