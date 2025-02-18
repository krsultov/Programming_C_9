#include <stdio.h>
#include <string.h>

int main(void) {
    char a[50], b[50];

    fgets((char *)&a, 50, stdin);
    fgets((char *)&b, 50, stdin);

    char *nl_pos = strchr(a, '\n');
    if (nl_pos != NULL) {
        *nl_pos = '\0';
    }

    nl_pos = strchr(b, '\n');
    if (nl_pos != NULL) {
        *nl_pos = '\0';
    }

}
