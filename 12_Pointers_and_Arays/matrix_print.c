#include <stdio.h>

void print_matrix(char (*matrix)[4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main(void) {
    char matrix[3][4] = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'}
    };

    char matrix2[5][4] = { // 5 rows, 4 columns
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'},
        {'q', 'r', 's', 't'}
    };

    print_matrix(matrix, 3);
    printf("\n");
    print_matrix(matrix2, 5);

    return 0;
}